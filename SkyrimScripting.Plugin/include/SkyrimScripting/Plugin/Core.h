#pragma once

#ifndef _Log_
    #define _Log_(...) SKSE::log::info(__VA_ARGS__)
#endif

#ifndef _ConsoleLog_
    #include <string_format.h>
    #define _ConsoleLog_(...) \
        RE::ConsoleLog::GetSingleton()->Print(string_format(__VA_ARGS__).c_str())
#endif

#include <RE/Skyrim.h>  // IWYU pragma: keep
#include <SKSE/SKSE.h>  // IWYU pragma: keep
#include <SkyrimScripting/SKSE/Logging.h>
#include <SkyrimScripting/SKSE/Messages.h>
