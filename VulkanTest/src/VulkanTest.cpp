#include "EntryPoint.h"
#include "VulkanCore.h"

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

	ANT_INFO_TAG("Client", "This used in a app solution");

	return new VulkanTestApplication(specification);
}
