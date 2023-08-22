#include "VulkanCorePch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

#include <filesystem>

#define ANT_HAS_CONSOLE !ANT_DIST

namespace VulkanCore {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		std::string logsDirectory = "logs";
		if (!std::filesystem::exists(logsDirectory))
			std::filesystem::create_directories(logsDirectory);

		std::vector<spdlog::sink_ptr> antSinks =
		{
			std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/AntCore.log", true),
#if ANT_HAS_CONSOLE
			std::make_shared<spdlog::sinks::stdout_color_sink_mt>()
#endif
		};

		std::vector<spdlog::sink_ptr> appSinks =
		{
			std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/AppTest.log", true),
#if ANT_HAS_CONSOLE
			std::make_shared<spdlog::sinks::stdout_color_sink_mt>()
#endif
		};

		antSinks[0]->set_pattern("[%Y/%m/%d %H:%M:%S.%e] [Processor:%P Threads:%t] [%l] %n: %v");
		appSinks[0]->set_pattern("[%Y/%m/%d %H:%M:%S.%e] [Processor:%P Threads:%t] [%l] %n: %v");

#if ANT_HAS_CONSOLE
		antSinks[1]->set_pattern("%^[%Y/%m/%d %H:%M:%S.%e] %n: %v%$");
		appSinks[1]->set_pattern("%^[%Y/%m/%d %H:%M:%S.%e] %n: %v%$");
#endif

		s_CoreLogger = std::make_shared<spdlog::logger>("AntCore", antSinks.begin(), antSinks.end());
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = std::make_shared<spdlog::logger>("AntTest", appSinks.begin(), appSinks.end());
		s_ClientLogger->set_level(spdlog::level::trace);

	}

	void Log::Shutdown()
	{
		s_ClientLogger.reset();
		s_CoreLogger.reset();
		spdlog::drop_all();
	}
}
