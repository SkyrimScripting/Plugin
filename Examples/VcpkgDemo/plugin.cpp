#include <SkyrimScripting/Plugin.h>

OnInit { logger::info("Hello, world! I am a plugin."); }

EventHandlers {
    On<RE::TESActivateEvent>([](const RE::TESActivateEvent* event) {
        auto activator = event->actionRef ? event->actionRef->GetBaseObject()->GetName() : "";
        auto activated = event->objectActivated ? event->objectActivated->GetBaseObject()->GetName() : "";
        logger::info("{} activated {}", activator, activated);
    });
}
