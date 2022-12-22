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

#define OnSystemEvent(systemEvent)                                                                              \
    __SKYRIM_SCRIPTING_PLUGIN_REGISTER_AND_DEFINE_CALLBACK(SkyrimScripting::Plugin::SystemEvents::Forms_Loaded, \
                                                           __COUNTER__)                                         \
    ()

#define OnFormsLoaded OnSystemEvent(SkyrimScripting::Plugin::SystemEvents::Forms_Loaded)

// enum class SystemEvents {
//     SKSE_Plugins_Loaded = 0,
//     After_SKSE_Plugins_Loaded = 1,
//     Loading_Game = 2,
//     Load_Game = 3,
//     Save_Game = 4,
//     Delete_Game = 5,
//     UI_Loaded = 6,
//     New_Game = 7,
//     Forms_Loaded = 8
// };