#pragma once

#include "SkyrimScripting/Plugin/Config.h"
#include "SkyrimScripting/Plugin/Internal/FunctionRunner.h"
#include "SkyrimScripting/Plugin/Internal/Macros.h"


// Override the full path of the log file for this plugin
#define PluginLogFullPath(fullPath)                                       \
    __NEW_SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER {                        \
        []() { SkyrimScripting::Plugin::Config::LogFullPath = fullPath; } \
    }

// Override the filename of the log file for this plugin
#define PluginLogFileName(filename)                                       \
    __NEW_SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER {                        \
        []() { SkyrimScripting::Plugin::Config::LogFileName = filename; } \
    }

// Override the folder path of the log file for this plugin
#define PluginLogFolder(folderPath)                                           \
    __NEW_SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER {                            \
        []() { SkyrimScripting::Plugin::Config::LogFolderPath = folderPath; } \
    }

// Enables logging to debugger console when debugger is attached (default: false)
#define PluginLogToDebugConsole                                             \
    __NEW_SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER {                          \
        []() { SkyrimScripting::Plugin::Config::LogToDebugConsole = true; } \
    }

// Disables logging
#define PluginLogDisable                                              \
    __NEW_SKYRIM_SCRIPTING_PLUGIN_FUNCTIONRUNNER {                    \
        []() { SkyrimScripting::Plugin::Config::LogDisabled = true; } \
    }
