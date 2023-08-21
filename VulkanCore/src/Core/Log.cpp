#include "VulkanCorePch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

#include <filesystem>

#define ANT_HAS_CONSOLE !ANT_DIST

//namespace VulkanCore {
//
//	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
//	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
//
//	void Log::Init()
//	{
//		// Create "logs" directory if doesn't exist
//		std::string logsDirectory = "logs";
//		if (!std::filesystem::exists(logsDirectory))
//			std::filesystem::create_directories(logsDirectory);
//
//		std::vector<spdlog::sink_ptr> antSinks =
//		{
//			std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/ANTONVULKANCORE.log", true)
//		};
//
//		std::vector<spdlog::sink_ptr> appSinks =
//		{
//			std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/ANTONVULKANTEST.log", true)
//		};
//
//		//antSinks[0]->set_pattern("[%Y/%m/%d %H::%M::%S.%e] [Processor:%P Threads:%t] [%l] %n: %v");
//		//appSinks[0]->set_pattern("[%Y/%m/%d %H::%M::%S.%e] [Processor:%P Threads:%t] [%l] %n: %v");
//
//		antSinks[0]->set_pattern("%^[%T] %n: %v%$");
//		appSinks[0]->set_pattern("[%T] [%l] %n: %v");
//
//		s_CoreLogger = std::make_shared<spdlog::logger>("ANT", antSinks.begin(), antSinks.end());
//		s_CoreLogger->set_level(spdlog::level::trace);
//
//		s_ClientLogger = std::make_shared<spdlog::logger>("APP", appSinks.begin(), appSinks.end());
//		s_ClientLogger->set_level(spdlog::level::trace);
//
//	}
//
//	void Log::Shutdown()
//	{
//		s_ClientLogger.reset();
//		s_CoreLogger.reset();
//		spdlog::drop_all();
//	}
//
//
//
//}

namespace VulkanCore {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Ant.log", true));

		logSinks[0]->set_pattern("[%Y/%m/%d %H:%M:%S.%e] [Processor:%P Threads:%t] [%l] %n: %v");
		logSinks[1]->set_pattern("[%Y/%m/%d %H:%M:%S.%e] [Processor:%P Threads:%t] [%l] %n: %v");

		s_CoreLogger = std::make_shared<spdlog::logger>("Ant", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_CoreLogger);
		s_CoreLogger->set_level(spdlog::level::trace);
		s_CoreLogger->flush_on(spdlog::level::trace);

		s_ClientLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_ClientLogger);
		s_ClientLogger->set_level(spdlog::level::trace);
		s_ClientLogger->flush_on(spdlog::level::trace);

	}
}
