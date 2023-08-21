include "./vendor/premake/premake_customization/solution_items.lua"

workspace "AntOnVulkan"
    startproject "VulkanTest"
    configurations { "Debug", "Release", "Dist" }
    flags { "MultiProcessorCompile" }
    solution_items { ".editorconfig" }

    filter "language:C++ or language:C"
        architecture "x86_64"
    filter ""

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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

project "VulkanTest"
    location "VulkanTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("bin/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/bin-int/" .. outputdir .. "/%{prj.name}")

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
    }

    links
    {
        "VulkanCore"
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
