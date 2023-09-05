#pragma once

namespace SkyrimScripting::Plugin {

    // https://github.com/ianpatt/skse64/blob/09f520a2433747f33ae7d7c15b1164ca198932c3/skse64/PluginAPI.h#L193-L212
    enum class SystemEvents {
        Plugin_Init,
        SKSE_Plugins_Loaded,
        After_SKSE_Plugins_Loaded,
        Loading_Game,
        Loaded_Game,
        Save_Game,
        Delete_Game,
        Input_Loaded,
        New_Game,
        Data_Loaded
    };
}
