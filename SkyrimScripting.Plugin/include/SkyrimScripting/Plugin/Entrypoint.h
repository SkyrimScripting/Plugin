#pragma once

#include <SkyrimScripting/SKSE/Messages/Entrypoint.h>  // IWYU pragma: keep

#include "Core.h"  // IWYU pragma: keep

__OnInit__(PluginEntrypointOnInit) {
    auto pluginName = ::SKSE::PluginDeclaration::GetSingleton()->GetName();

    // auto pluginHandle = SkyrimScripting::SKSE::LoadInterface->GetPluginHandle();
    SkyrimScripting::SKSE::Logging::SetupLogging(pluginName.data());
    // SkyrimScripting::SKSE::Logging::SetupLogging("ThisIsVR");
    // REL::Version::
}
