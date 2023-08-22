-- Ant Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK");

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/VulkanCore/vendor/GLFW/include"
IncludeDir["ImGui"] = "%{wks.location}/VulkanCore/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/VulkanCore/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/VulkanCore/vendor/stb_image"
IncludeDir["shaderc_util"] = "%{wks.location}/VulkanCore/vendor/shaderc/libshaderc_util/include"
IncludeDir["shaderc"] = "%{wks.location}/VulkanCore/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/VulkanCore/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

Library = {}

Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUntils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Library["ShaderC_Utils_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_utild.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["ShaderC_Utils_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_util.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"

-- Temporarily use our own SPIRV-Cross binaries
-- Vulkan SDK 1.3.204.1 (currently latest) shipped with a critical bug for us (see https://github.com/KhronosGroup/SPIRV-Cross/issues/1879)
Library["SPIRV_Cross_Debug"] = "%{wks.location}/VulkanCore/vendor/SPIRV-Cross/lib/spirv-cross-cored.lib"
Library["SPIRV_Cross_Release"] = "%{wks.location}/VulkanCore/vendor/SPIRV-Cross/lib/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{wks.location}/VulkanCore/vendor/SPIRV-Cross/lib/spirv-cross-glsld.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{wks.location}/VulkanCore/vendor/SPIRV-Cross/lib/spirv-cross-glsl.lib"

