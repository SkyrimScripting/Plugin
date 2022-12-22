#pragma once

#include <RE/Skyrim.h>

#include <atomic>
#include <functional>
#include <unordered_map>
#include <vector>

#include "SkyrimScripting/Plugin/SystemEvents.h"

namespace SkyrimScripting::Plugin {

    class SKSEPlugin {
        SKSEPlugin() = default;
        ~SKSEPlugin() = default;
        SKSEPlugin(const SKSEPlugin&) = delete;
        SKSEPlugin(SKSEPlugin&&) = delete;
        SKSEPlugin& operator=(const SKSEPlugin&) = delete;
        SKSEPlugin& operator=(SKSEPlugin&&) = delete;

        std::unordered_map<SystemEvents, std::vector<std::function<void()>>> _systemCallbacks;

    public:
        static SKSEPlugin& GetSingleton() {
            static SKSEPlugin singleton;
            return singleton;
        }

        static void __Initialize() {
            SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* message) {
                auto& plugin = GetSingleton();
                switch (message->type) {
                    case SKSE::MessagingInterface::kDataLoaded:
                        plugin.RunSystemEventCallbacks(SystemEvents::Forms_Loaded);
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
