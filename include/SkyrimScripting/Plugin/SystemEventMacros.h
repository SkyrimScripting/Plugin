#pragma once

#include "SkyrimScripting/Plugin/Internal/FunctionRunner.h"

#define __SKYRIM_SCRIPTING_PLUGIN_CONCAT0(x, y) x##y
#define __SKYRIM_SCRIPTING_PLUGIN_CONCAT(x, y) __SKYRIM_SCRIPTING_PLUGIN_CONCAT0(x, y)

// Create a "FunctionRunner" which takes a std::function which is run immediately at runtime
#define __SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER(count)                                 \
    SkyrimScripting::Plugin::Internal::FunctionRunner __SKYRIM_SCRIPTING_PLUGIN_CONCAT( \
        __skyrimScriptingPluginFunctionRunner, count)

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

#define OnSystemEvent(systemEvent)                                                                             \
    __SKYRIM_SCRIPTING_PLUGIN_REGISTER_AND_DEFINE_CALLBACK(SkyrimScripting::Plugin::SystemEvents::Data_Loaded, \
                                                           __COUNTER__)                                        \
    ()

#define OnPluginLoad OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::SKSE_Plugins_Loaded)
#define OnLoad OnPluginLoad
#define OnPluginsLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded::After_SKSE_Plugins_Loaded)
#define OnLoadingGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded::Loading_Game)
#define OnLoadedGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded::Loaded_Game)
#define OnSaveGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded::Save_Game)
#define OnDeleteGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded::Delete_Game)
#define OnNewGame OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded::New_Game)
#define OnInputLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded::Input_Loaded)
#define OnUIReady OnInputLoaded
#define OnDataLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Data_Loaded)
#define OnFormsLoaded OnDataLoaded
