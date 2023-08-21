#include "EntryPoint.h"

class VulkanTestApplication : public VulkanCore::Application
{
public:
	VulkanTestApplication(const VulkanCore::ApplicationSpecification& specification)
		: Application(specification)
	{

	}
};

VulkanCore::Application* VulkanCore::CreateApplication(int argc, char** argv)
{
	VulkanCore::ApplicationSpecification specification;
	specification.Name = "AntOfVulkan";
	specification.WindowHeight = 900;
	specification.WindowWidth = 1600;
	specification.VSync = true;

	return new VulkanTestApplication(specification);
}
