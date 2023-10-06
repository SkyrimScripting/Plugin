#include <SkyrimScripting/Plugin.h>

_OnSKSEMessage_(::SKSE::MessagingInterface::Message* message) {
    _Log_("Hello from _OnSKSEMessage_");
    _Log_("Message: {}", message->type);
}

_OnInit_ {
    SKSE::log::info("This is an SKSE log message (using SKSE::log) {}", 420);

    // Only care about _Log_ because it's what's used internally by SkyrimScripting* libraries
    _Log_("This is an SKSE log message (using _Log_) {}", 69);
}

_OnPluginsLoaded_ { _Log_("Hello from _OnPluginsLoaded_"); }
_OnAfterPluginsLoaded_ { _Log_("Hello from _OnAfterPluginsLoaded_"); }
_OnInputLoaded_ { _Log_("Hello from _OnInputLoaded_"); }
_OnDataLoaded_ { _Log_("Hello from _OnDataLoaded_"); }

_OnNewGame_(RE::TESQuest* quest) {
    _Log_("Hello from _OnNewGame_");
    _Log_("Quest: {}", quest->GetName());
}

_OnSaveGame_(std::filesystem::path path) {
    _Log_("Hello from _OnSaveGame_");
    _Log_("Path: {}", path.string().c_str());
}

_OnLoadingGame_(std::filesystem::path path) {
    _Log_("Hello from _OnLoadingGame_");
    _Log_("Path: {}", path.string().c_str());
}

_OnLoadedGame_(bool success) {
    _Log_("Hello from _OnLoadedGame_");
    _Log_("Success: {}", success);
}

_OnDeleteGame_(std::filesystem::path path) {
    _Log_("Hello from _OnDeleteGame_");
    _Log_("Path: {}", path.string().c_str());
}
