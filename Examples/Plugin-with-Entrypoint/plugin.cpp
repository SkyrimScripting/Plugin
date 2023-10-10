#include <SkyrimScripting/Plugin/Entrypoint.h>

_SKSEPlugin_Init_ {
    // ...
}

_SKSEPlugin_Init_HighPriority_ {
    // ...
}

_SKSEPlugin_PreInit_(const SKSE::LoadInterface*) { return true; }
