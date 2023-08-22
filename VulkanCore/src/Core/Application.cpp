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
