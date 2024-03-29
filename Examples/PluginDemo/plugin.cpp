// #include <SkyrimScripting/Plugin.h>

// EventHandlers {
//     On<RE::TESActivateEvent>([](const RE::TESActivateEvent* activation) {
//         auto activator = activation ? activation->actionRef->GetBaseObject()->GetName() : "";
//         auto activated = activation->objectActivated ? activation->objectActivated->GetBaseObject()->GetName() : "";
//         logger::info("{} activated {}", activator, activated);
//     });

//     On<RE::TESContainerChangedEvent>([](const RE::TESContainerChangedEvent* event) {
//         logger::info("{} {:x} transferred from {:x} to {:x}", event->itemCount, event->baseObj, event->oldContainer,
//                      event->newContainer);
//     });
// }

#include <SkyrimScripting/Plugin/Core.h>

OnInit { logger::info("INIT FROM THE MACRO!"); }

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);
    SkyrimScripting::Plugin::Initialize();
    return true;
}

OnInputLoaded { ConsoleLog("Hello! {} {} {}", 1, 2, 3); }
