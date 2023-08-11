workspace "AntOnVulkan"
    architecture "x64"
    startproject "VulkanTest"
    configurations { "Debug", "Release", "Dist" }
    flags{ "MultiProcessorCompile" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "VulkanTest"
    location "VulkanTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir("bin/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp", 
    }

    filter "system:windows"
        systemversion "latest"

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
