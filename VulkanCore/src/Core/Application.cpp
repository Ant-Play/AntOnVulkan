#include "VulkanCorePch.h"
#include "Application.h"

#include "Log.h"

extern bool g_ApplicationRunning;

namespace VulkanCore {

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		s_Instance = this;
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		OnInit();
		while (m_Running)
		{
			/*VULKANCORE_CORE_FATAL_TAG("Core", "This is a spdlog test!");
			VULKANCORE_CORE_ERROR_TAG("Core", "This is a spdlog test!");
			VULKANCORE_CORE_WARN_TAG("Core", "This is a spdlog test!");
			VULKANCORE_CORE_TRACE_TAG("Core", "This is a spdlog test!");
			VULKANCORE_CORE_INFO_TAG("Core", "This is a spdlog test!");*/

			ANT_CORE_CRITICAL("This is a spdlog FATAL!");
			ANT_CORE_ERROR("This is a spdlog ERROR!");
			ANT_CORE_WARN("This is a spdlog WARN!");
			ANT_CORE_INFO("This is a spdlog INFO!");
			ANT_CORE_TRACE("This is a spdlog TRACE!");
		}
		
		OnShutdown();
	}

	void Application::Close()
	{
		m_Running = false;
	}

	void Application::OnInit()
	{

	}

	void Application::OnShutdown()
	{
		g_ApplicationRunning = false;
	}

	void Application::OnUpdate(Timestep ts)
	{

	}

	void Application::OnEvent()
	{

	}

}
