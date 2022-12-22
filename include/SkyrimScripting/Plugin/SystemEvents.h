#pragma once

namespace SkyrimScripting::Plugin {

    enum class SystemEvents {
        SKSE_Plugins_Loaded = 0,
        After_SKSE_Plugins_Loaded = 1,
        Loading_Game = 2,
        Load_Game = 3,
        Save_Game = 4,
        Delete_Game = 5,
        UI_Loaded = 6,
        New_Game = 7,
        Forms_Loaded = 8
    };
}
