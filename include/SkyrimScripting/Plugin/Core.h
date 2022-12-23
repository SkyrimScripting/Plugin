#pragma once

#include "SkyrimScripting/Plugin/EventCallback.h"
#include "SkyrimScripting/Plugin/LogInitializationMacros.h"
#include "SkyrimScripting/Plugin/SKSEPlugin.h"
#include "SkyrimScripting/Plugin/SystemEventMacros.h"

namespace logger = SKSE::log;

using namespace SkyrimScripting::Plugin::EventCallback;

namespace SkyrimScripting::Plugin {
    void Initialize() { SKSEPlugin::Initialize(); }
}
