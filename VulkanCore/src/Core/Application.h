#pragma once

#include "Timestep.h"
#include "Base.h"

#include <string>
#include <functional>

namespace VulkanCore {

	struct ApplicationSpecification
	{
		std::string Name = "AntOnVulkan";
		uint32_t WindowWidth = 1600, WindowHeight = 900;
		bool Fullscreen = false;
		bool VSync = true;
		bool Resizable = true;
	};

	class Application
	{
		//using EventCallbackFn = std::function<void(Event&)>;

	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();

		void Run();
		void Close();

		virtual void OnInit();
		virtual void OnShutdown();
		virtual void OnUpdate(Timestep ts);

		virtual void OnEvent();

		const ApplicationSpecification& GetSpecification() const { return m_Specification; }

	private:
		ApplicationSpecification m_Specification;
		bool m_Running = true, m_Minimized = false;

		static Application* s_Instance;
	};

	// Implemented by CLIENT
	Application* CreateApplication(int argc, char** argv);
}
