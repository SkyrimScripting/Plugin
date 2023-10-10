add_requires("skyrim-commonlib")

target("Using_Plugin_Entrypoint")
    add_files("*.cpp")
    add_packages("skyrim-commonlib")
    add_deps("SkyrimScripting.Plugin.Entrypoint")
    add_rules("@skyrim-commonlib/plugin", {
        mods_folder = os.getenv("SKYRIM_MODS_AE")
    })
