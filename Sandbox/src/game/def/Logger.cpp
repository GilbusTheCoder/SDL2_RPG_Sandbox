#include "pch.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Game {
	std::shared_ptr<spdlog::logger> Logger::_logger;

	void Logger::init() {
		// https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
		spdlog::set_pattern("%^-- [%T] %n -- %v%$");

		// Make windows and set defaults
		_logger = spdlog::stdout_color_mt("SandboxLogger");
		_logger->set_level(spdlog::level::trace); 
		LOG_INFO("Logger initialized.");
	} 
}
