#pragma once

#include <format>
#include <RE/C/ConsoleLog.h>
#include <spdlog/sinks/basic_file_sink.h>

template <class... Types>
void Log(const std::string text, const Types&... args) {
	std::string result = std::format(text, args...);
	logger::info("{}", result);
	RE::ConsoleLog::GetSingleton()->Print(std::format("[SkyrimScripting] {}", result).c_str());
};

void InitializeLog() {
	auto path = logger::log_directory();
	if (!path) {
		stl::report_and_fail("Failed to find standard logging directory"sv);
	}
	*path /= fmt::format("{}.log", SKSE::PluginDeclaration::GetSingleton()->GetName());
	auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);

#ifndef NDEBUG
	const auto level = spdlog::level::trace;
#else
	const auto level = spdlog::level::info;
#endif

	auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));
	log->set_level(level);
	log->flush_on(level);

	spdlog::set_default_logger(std::move(log));
	spdlog::set_pattern("%g(%#): [%^%l%$] %v"s);
}
