#pragma once

namespace SkyrimScripting::Plugin {

    // https://github.com/ianpatt/skse64/blob/09f520a2433747f33ae7d7c15b1164ca198932c3/skse64/PluginAPI.h#L193-L212
    enum class SystemEvents {
        SKSE_Plugins_Loaded = 0,
        After_SKSE_Plugins_Loaded = 1,
        Loading_Game = 2,
        Loaded_Game = 3,
        Save_Game = 4,
        Delete_Game = 5,
        Input_Loaded = 6,
        New_Game = 7,
        Data_Loaded = 8
    };
}
