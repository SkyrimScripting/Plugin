#pragma once

#include "SkyrimScripting/Plugin/SKSEPlugin.h"

// Initializes a plugin
namespace SkyrimScripting::Plugin {

    // Initialize the plugin
    SKSEPluginLoad(const SKSE::LoadInterface *skse) {
        SKSE::Init(skse);
        SKSEPlugin::Initialize();
        return true;
    }
}
