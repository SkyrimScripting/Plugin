#include <SkyrimScripting/Plugin/Entrypoint/Functions.h>

__SKSEPlugin_Init__(SecondFile) {
    // ...
}

__SKSEPlugin_Init_HighPriority__(SecondFile) {
    // ...
}

__SKSEPlugin_PreInit__(SecondFile)(const SKSE::LoadInterface*) { return true; }
