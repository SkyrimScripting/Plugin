add_requires("skyrim-commonlib")

target("SkyrimScripting.Plugin - Example with Logging")
    add_files("*.cpp")
    add_deps("SkyrimScripting.Plugin")
    add_packages("skyrim-commonlib")
    add_rules("@skyrim-commonlib/plugin", {
        mod_folders = os.getenv("SKYRIM_SCRIPTING_MOD_FOLDERS")
    })
