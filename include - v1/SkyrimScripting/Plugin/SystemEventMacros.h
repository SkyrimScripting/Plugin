#pragma once

#include "SkyrimScripting/Plugin/Internal/FunctionRunner.h"
#include "SkyrimScripting/Plugin/Internal/Macros.h"

// Setup for a callback function to be registered, e.g. as a SystemEvent handler
#define __SKYRIM_SCRIPTING_PLUGIN_CALLBACKFN_NAME(count) \
    __SKYRIM_SCRIPTING_PLUGIN_CONCAT(__skyrimScriptingPluginCallback, count)

// Add a System Event Callback to SKSEPlugin
//
// It'll call the function which the developer defines using the macro
// so they need access to the same __COUNTER__ (which is why we take the count as an argument)
//
#define __SKYRIM_SCRIPTING_PLUGIN_REGISTER_AND_DEFINE_CALLBACK(systemEvent, count)                          \
    inline void __SKYRIM_SCRIPTING_PLUGIN_CALLBACKFN_NAME(count)();                                         \
    __SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER(count){[]() {                                                  \
        SkyrimScripting::Plugin::SKSEPlugin::GetSingleton().RegisterSystemEventCallback(systemEvent, []() { \
            __SKYRIM_SCRIPTING_PLUGIN_CALLBACKFN_NAME(count)();                                             \
        });                                                                                                 \
    }};                                                                                                     \
    inline void __SKYRIM_SCRIPTING_PLUGIN_CALLBACKFN_NAME(count)

#define OnSystemEvent(systemEvent)                                                   \
    __SKYRIM_SCRIPTING_PLUGIN_REGISTER_AND_DEFINE_CALLBACK(systemEvent, __COUNTER__) \
    ()

// SKSEPluginLoad macro(s)
// OnPluginLoad() because it's SKSEPluginLoad()
#define OnPluginLoad OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Plugin_Init)
// OnInit() to be like Papyrus
#define OnInit OnPluginLoad
// Semantics for registering event handlers
#define EventHandlers OnPluginLoad

// Other Macros
#define OnPluginsLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::SKSE_Plugins_Loaded)
#define AfterPluginsLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::After_SKSE_Plugins_Loaded)
#define OnLoadingGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Loading_Game)
#define OnLoadedGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Loaded_Game)
#define OnSaveGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Save_Game)
#define OnDeleteGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Delete_Game)
#define OnNewGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::New_Game)
#define OnInputLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Input_Loaded)
#define OnDataLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded)
#define OnFormsLoaded OnDataLoaded
