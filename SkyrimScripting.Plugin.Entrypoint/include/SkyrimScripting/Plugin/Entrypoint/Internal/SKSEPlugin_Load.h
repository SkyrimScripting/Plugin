#pragma once

#include <SKSE/SKSE.h>

#include "EntrypointCallbacks.h"

extern "C" __declspec(dllexport) bool SKSEPlugin_Load(const SKSE::LoadInterface* skse) {
    auto& callbacks = SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton();

    if (!callbacks.RunPreInitHighPriorityCallbacks(skse)) return false;
    if (!callbacks.RunPreInitCallbacks(skse)) return false;
    if (!callbacks.RunPreInitLowPriorityCallbacks(skse)) return false;

    SKSE::Init(skse);

    if (!callbacks.RunPostInitHighPriorityCallbacks(skse)) return false;
    if (!callbacks.RunPostInitCallbacks(skse)) return false;
    if (!callbacks.RunPostInitLowPriorityCallbacks(skse)) return false;

    callbacks.RunHighPriorityCallbacks();
    callbacks.RunCallbacks();
    callbacks.RunLowPriorityCallbacks();

    return true;
}