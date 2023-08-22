include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "AntOnVulkan"
    startproject "VulkanTest"
    configurations { "Debug", "Release", "Dist" }
    flags { "MultiProcessorCompile" }
    solution_items { ".editorconfig" }

    filter "language:C++ or language:C"
        architecture "x86_64"
    filter ""

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
include "VulkanCore/vendor/GLFW"
include "VulkanCore/vendor/imgui"
group ""

group "Core"
project "VulkanCore"
    location "VulkanCore"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("bin/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "VulkanCorePch.h"
    pchsource "VulkanCore/src/VulkanCorePch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor",

        "%{IncludeDir.GLFW}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.VulkanSDK}",

    }

    links
    {
        "GLFW",
        "ImGui",
        "%{Library.Vulkan}",
        -- "%{LibraryDir.VulkanSDK}/vulkan-1.lib",
		-- "%{Library.VulkanUtils}",

    }

    defines
    {
        "GLM_FORCE_DEPTH_ZERO_TO_ONE"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "ANT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

        includedirs
        {
            "%{IncludeDir.shaderc_util}",
			"%{IncludeDir.shaderc_glslc}"
        }

        links
        {
            "%{Library.ShaderC_Debug}",
			"%{Library.ShaderC_Utils_Debug}",
			"%{Library.SPIRV_Cross_Debug}",
			"%{Library.SPIRV_Cross_GLSL_Debug}",
			"%{Library.SPIRV_Tools_Debug}",
        }

        defines
        {
            "ANT_DEBUG",
        }

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

        includedirs
        {
            "%{IncludeDir.shaderc_util}",
			"%{IncludeDir.shaderc_glslc}"
        }

        links
        {
            "%{Library.ShaderC_Debug}",
			"%{Library.ShaderC_Utils_Debug}",
			"%{Library.SPIRV_Cross_Debug}",
			"%{Library.SPIRV_Cross_GLSL_Debug}",
			"%{Library.SPIRV_Tools_Debug}",
        }

        defines
        {
            "ANT_RELEASE",
        }

    filter "configurations:Dist"
        runtime "Release"
        optimize "on"

        defines
        {
            "ANT_DIST",
        }

group "Test"
project "VulkanTest"
    location "VulkanTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("bin/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/bin-int/" .. outputdir .. "/%{prj.name}")

    links
    {
        "VulkanCore"
    }

    defines 
	{
		"GLM_FORCE_DEPTH_ZERO_TO_ONE"
	}

    files
    {
        "%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp", 
    }

    includedirs
    {
        "%{prj.name}/src",
        "VulkanCore/src",
        "VulkanCore/vendor",
        "%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
        "%{IncludeDir.Vulkan}",
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "ANT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ANT_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ANT_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "ANT_DIST"
        runtime "Release"
        optimize "on"
