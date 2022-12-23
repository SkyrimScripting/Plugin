#include <SkyrimScripting/Plugin.h>

OnInit {
    On<RE::TESActivateEvent>([](const RE::TESActivateEvent* activation) {
        auto activator = activation ? activation->actionRef->GetBaseObject()->GetName() : "";
        auto activated = activation->objectActivated ? activation->objectActivated->GetBaseObject()->GetName() : "";
        logger::info("{} activated {}", activator, activated);
    });

    On<RE::TESContainerChangedEvent>([](const RE::TESContainerChangedEvent* event) {
        logger::info("{} {:x} transferred from {:x} to {:x}", event->itemCount, event->baseObj, event->oldContainer,
                     event->newContainer);
    });
}
