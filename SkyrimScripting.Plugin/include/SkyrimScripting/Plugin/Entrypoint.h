#pragma once

#include <SkyrimScripting/SKSE/Messages/Entrypoint.h>  // IWYU pragma: keep

#include "Core.h"  // IWYU pragma: keep

__OnInit__(PluginEntrypointOnInit) { SkyrimScripting::SKSE::Logging::SetupLogging(); }
