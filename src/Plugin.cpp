#include "Logging.h"
#include "PapyrusInterface.h"

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    InitializeLog();
    SKSE::Init(skse);
    SKSE::GetPapyrusInterface()->Register(PapyrusInterface::BIND);
    SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* event){
        if (event->type == SKSE::MessagingInterface::kDataLoaded) {
            Log("Hello from My SKSE Plugin");
        }
    });
    return true;
}
