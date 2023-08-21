#include "VulkanCorePch.h"
#include "Base.h"

#include "Log.h"

#define ANTONVULKAN_BUILD_ID "v0.1a"

namespace VulkanCore {
	
	void InitializeCore()
	{
		Log::Init();

		ANT_CORE_TRACE("AntOfVulkan Engine {}", ANTONVULKAN_BUILD_ID);
		ANT_CORE_TRACE("Initializing...");

		//VULKANCORE_CORE_TRACE("AntOfVulkan Engine {}", ANTONVULKAN_BUILD_ID);
		//VULKANCORE_CORE_TRACE_TAG("Core", "AntOfVulkan Engine {}", ANTONVULKAN_BUILD_ID);
		//VULKANCORE_CORE_TRACE_TAG("Core", "Initializing...");
	}

	void ShutdownCore()
	{
		ANT_CORE_TRACE("Shutting down...");

		//VULKANCORE_CORE_TRACE_TAG("Core", "Shutting down...");
		//Log::Shutdown();
	}
}
