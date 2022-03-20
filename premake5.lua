workspace "Yuna"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Yuna"
    location "Yuna"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "YU_PLATFORM_WINDOWS",
            "YU_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines { "YU_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "YU_RELEASE" }
        optimize "On"

    filter "configurations:Release"
        defines { "YU_DIST" }
        optimize "On"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Yuna/vendor/spdlog/include",
        "Yuna/src"
    }

    links
    {
        "Yuna"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "YU_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines { "YU_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "YU_RELEASE" }
        optimize "On"

    filter "configurations:Release"
        defines { "YU_DIST" }
        optimize "On"