#pragma once

// Include spdlog support for a basic file logger
#include <spdlog/sinks/basic_file_sink.h>

// Allows us to check if a debugger is attached (optional, see below)
#include <Windows.h>
#include <spdlog/sinks/msvc_sink.h>

#include <atomic>
#include <filesystem>
#include <format>

#include "SkyrimScripting/Plugin/Config.h"

namespace SkyrimScripting::Plugin::Logger {

    std::atomic<bool> IsLoggerInitialized;

    std::filesystem::path GetSKSELogFolder() {
        auto logsFolder = SKSE::log::log_directory();
        if (!logsFolder) SKSE::stl::report_and_fail("SKSE log_directory not provided, logs disabled.");
        return *logsFolder;
    }

    void InitializeLog() {
        if (IsLoggerInitialized.exchange(true)) return;
        if (Config::LogDisabled) return;

        std::filesystem::path logPath = Config::LogFullPath;

        if (logPath.empty()) {
            if (!Config::LogFolderPath.empty() && !Config::LogFileName.empty())
                logPath = Config::LogFolderPath / Config::LogFileName;
            else if (!Config::LogFolderPath.empty())
                logPath =
                    Config::LogFolderPath / std::format("{}.log", SKSE::PluginDeclaration::GetSingleton()->GetName());
            else if (!Config::LogFileName.empty())
                logPath = GetSKSELogFolder() / Config::LogFileName;
            else
                logPath =
                    GetSKSELogFolder() / std::format("{}.log", SKSE::PluginDeclaration::GetSingleton()->GetName());
        }

        auto fileLoggerPtr = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logPath.string(), true);

        std::shared_ptr<spdlog::logger> loggerPtr;
        if (Config::LogToDebugConsole && IsDebuggerPresent()) {
            auto debugLoggerPtr = std::make_shared<spdlog::sinks::msvc_sink_mt>();
            spdlog::sinks_init_list loggers{std::move(fileLoggerPtr), std::move(debugLoggerPtr)};
            loggerPtr = std::make_shared<spdlog::logger>("log", loggers);
        } else {
            loggerPtr = std::make_shared<spdlog::logger>("log", std::move(fileLoggerPtr));
        }

        spdlog::set_default_logger(std::move(loggerPtr));
        spdlog::set_level(spdlog::level::trace);
        spdlog::flush_on(spdlog::level::trace);
    }
}
