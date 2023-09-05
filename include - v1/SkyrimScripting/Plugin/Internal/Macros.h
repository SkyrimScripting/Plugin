#pragma once

#define __SKYRIM_SCRIPTING_PLUGIN_CONCAT0(x, y) x##y
#define __SKYRIM_SCRIPTING_PLUGIN_CONCAT(x, y) __SKYRIM_SCRIPTING_PLUGIN_CONCAT0(x, y)

// Create a "FunctionRunner" which takes a std::function which is run immediately at runtime
#define __SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER(count)                                 \
    SkyrimScripting::Plugin::Internal::FunctionRunner __SKYRIM_SCRIPTING_PLUGIN_CONCAT( \
        __skyrimScriptingPluginFunctionRunner, count)

#define __NEW_SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER __SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER(__COUNTER__)
