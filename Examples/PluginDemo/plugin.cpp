#include <SkyrimScripting/Plugin.h>

OnInit { logger::trace("Immediately init logged!"); }
OnLoad { logger::trace("Hello from plugin!"); }
OnPluginsLoaded { logger::trace("Plugins loaded!"); }
OnDataLoaded { logger::trace("Data loaded!"); }
OnSaveGame { logger::trace("Save game!"); }
OnLoadedGame { logger::trace("Loaded game!"); }
