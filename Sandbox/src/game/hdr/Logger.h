#pragma once

#include "spdlog/spdlog.h"
namespace Game {
	class Logger { 
	private:
		static std::shared_ptr<spdlog::logger> _logger;
		
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getLogger() { return _logger; }
	};
}


#ifdef DEBUG
	#define LOG_TRACE(...)				Game::Logger::getLogger()->trace(__VA_ARGS__)
	#define LOG_INFO(...)				Game::Logger::getLogger()->info(__VA_ARGS__)
	#define LOG_WARN(...)				Game::Logger::getLogger()->warn(__VA_ARGS__)
	#define LOG_ERROR(...)				Game::Logger::getLogger()->error(__VA_ARGS__)
	#define LOG_CRITICAL(...)			Game::Logger::getLogger()->critical(__VA_ARGS__)
#else 
	#define LOG_TRACE(...)			
	#define LOG_INFO(...)			
	#define LOG_WARN(...)			
	#define LOG_ERROR(...)			
	#define LOG_CRITICAL(...)		
#endif
