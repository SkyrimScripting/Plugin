#pragma once

#include "SkyrimScripting/Plugin/Init.h"
#include "SkyrimScripting/Plugin/SKSEPlugin.h"
#include "SkyrimScripting/Plugin/SystemEventMacros.h"

namespace SkyrimScripting {
    /*
     * Get a representation of a current SKSE plugin.
     */
    Plugin::SKSEPlugin* GetPlugin() { return &Plugin::SKSEPlugin::GetSingleton(); }
}
