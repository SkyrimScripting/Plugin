add_requires("string_format")

target("SkyrimScripting.Plugin")
    set_kind("headeronly")
    add_includedirs("include", { public = true })
    add_headerfiles("include/(**.h)")
    add_deps(
        "SkyrimScripting.SKSE.Messages",
        "SkyrimScripting.SKSE.Logging",
        { public = true }
    )
    add_packages("string_format", { public = true })
