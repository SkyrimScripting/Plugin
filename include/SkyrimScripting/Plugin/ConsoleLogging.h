#pragma once

namespace SkyrimScripting::Plugin::ConsoleLogging {

    template <class... Args>
    void ConsoleLog(fmt::format_string<Args...> text, Args&&... args) {
        auto* log = RE::ConsoleLog::GetSingleton();
        if (log)
            log->Print(fmt::format(text, std::forward<Args>(args)...).c_str());
        else
            SKSE::log::error(
                "Failed to get RE::ConsoleLog::GetSingleton(). Did you call ConsoleLog() before OnDataLoaded?");
    }
}
