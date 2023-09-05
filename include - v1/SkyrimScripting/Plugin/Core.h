#pragma once

#include "SkyrimScripting/Plugin/ConsoleLogging.h"
#include "SkyrimScripting/Plugin/EventCallback.h"
#include "SkyrimScripting/Plugin/LogInitializationMacros.h"
#include "SkyrimScripting/Plugin/SKSEPlugin.h"
#include "SkyrimScripting/Plugin/SystemEventMacros.h"

namespace logger = SKSE::log;

using namespace SkyrimScripting::Plugin::EventCallback;
using namespace SkyrimScripting::Plugin::ConsoleLogging;

namespace SkyrimScripting::Plugin {
    void Initialize() { SKSEPlugin::Initialize(); }
}
