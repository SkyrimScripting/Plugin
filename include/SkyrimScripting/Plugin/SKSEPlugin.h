#pragma once

#include <RE/Skyrim.h>

#include <atomic>
#include <filesystem>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "SkyrimScripting/Plugin/Logger.h"
#include "SkyrimScripting/Plugin/SystemEvents.h"

namespace SkyrimScripting::Plugin {

    class SKSEPlugin {
        SKSEPlugin() = default;
        ~SKSEPlugin() = default;
        SKSEPlugin(const SKSEPlugin&) = delete;
        SKSEPlugin(SKSEPlugin&&) = delete;
        SKSEPlugin& operator=(const SKSEPlugin&) = delete;
        SKSEPlugin& operator=(SKSEPlugin&&) = delete;

        std::atomic<bool> _initialized;
        std::unordered_map<SystemEvents, std::vector<std::function<void()>>> _systemCallbacks;

    public:
        static SKSEPlugin& GetSingleton() {
            static SKSEPlugin singleton;
            return singleton;
        }

        // TODO Add support for a OnStartGame() event which is just TESCellFullyLoaded which is reset by the main menu
        //      and reset by load game (maybe)

        static void __Initialize() {
            auto& plugin = GetSingleton();
            if (plugin._initialized.exchange(true)) return;
            Logger::InitializeLog();
            plugin.RunSystemEventCallbacks(SystemEvents::Plugin_Init);
            SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* message) {
                auto& plugin = GetSingleton();
                switch (message->type) {
                    case SKSE::MessagingInterface::kPostLoad:
                        plugin.RunSystemEventCallbacks(SystemEvents::SKSE_Plugins_Loaded);
                        break;
                    case SKSE::MessagingInterface::kPostPostLoad:
                        plugin.RunSystemEventCallbacks(SystemEvents::After_SKSE_Plugins_Loaded);
                        break;
                    case SKSE::MessagingInterface::kPreLoadGame:
                        plugin.RunSystemEventCallbacks(SystemEvents::Loading_Game);
                        break;
                    case SKSE::MessagingInterface::kPostLoadGame:
                        plugin.RunSystemEventCallbacks(SystemEvents::Loaded_Game);
                        break;
                    case SKSE::MessagingInterface::kSaveGame:
                        plugin.RunSystemEventCallbacks(SystemEvents::Save_Game);
                        break;
                    case SKSE::MessagingInterface::kDeleteGame:
                        plugin.RunSystemEventCallbacks(SystemEvents::Delete_Game);
                        break;
                    case SKSE::MessagingInterface::kInputLoaded:
                        plugin.RunSystemEventCallbacks(SystemEvents::Input_Loaded);
                        break;
                    case SKSE::MessagingInterface::kNewGame:
                        plugin.RunSystemEventCallbacks(SystemEvents::New_Game);
                        break;
                    case SKSE::MessagingInterface::kDataLoaded:
                        plugin.RunSystemEventCallbacks(SystemEvents::Data_Loaded);
                        break;
                    default:
                        // Setup log please lol so we can log!
                        break;
                }
            });
        }

        void RunSystemEventCallbacks(SystemEvents event) {
            if (_systemCallbacks.contains(event)) {
                for (auto& callback : _systemCallbacks.at(event)) {
                    callback();
                }
            }
        }

        void RegisterSystemEventCallback(SystemEvents event, std::function<void()> callback) {
            if (!_systemCallbacks.contains(event))
                _systemCallbacks.insert_or_assign(event, std::vector<std::function<void()>>{});
            _systemCallbacks.at(event).emplace_back(callback);
        }
    };
}
