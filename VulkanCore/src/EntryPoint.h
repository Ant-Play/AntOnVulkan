#pragma once

#include "Core/Application.h"

#ifdef ANT_PLATFORM_WINDOWS

extern VulkanCore::Application* VulkanCore::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;


namespace VulkanCore {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			InitializeCore();
			Application* app = CreateApplication(argc, argv);
			app->Run();
			delete app;
			ShutdownCore();
		}
		return 0;
	}
}

#ifdef ANT_DIST

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdLine, int cmdshow)
{
	return VulkanCore::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return VulkanCore::Main(argc, argv);
}

#endif

#endif
