#include <SkyrimScripting/Plugin.h>

OnFormsLoaded { RE::ConsoleLog::GetSingleton()->Print("Holy fuck, forms loaded!"); }

// SKSEPluginLoad(const SKSE::LoadInterface *skse) {
//     SKSE::Init(skse);

//     // Once all plugins and mods are loaded, then the ~ console is ready and can
//     // be printed to
//     SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message *message) {
//         if (message->type == SKSE::MessagingInterface::kDataLoaded)
//             RE::ConsoleLog::GetSingleton()->Print("HELLO FROM DEMO");
//     });

//     return true;
// }