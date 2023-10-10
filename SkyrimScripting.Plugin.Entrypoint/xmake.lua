add_requires("global_macro_functions")

target("SkyrimScripting.Plugin.Entrypoint")
    set_kind("headeronly")
    add_includedirs("include", { public = true })
    add_headerfiles("include/(**.h)")
    add_packages("global_macro_functions", { public = true })
