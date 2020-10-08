workspace "opengl-platformer"
	configurations "debug"

project	"opengl-platformer"
	kind "ConsoleApp"
	language "C++"
	targetdir "out/%{cfg.buildcfg}"
	objdir "out/int/%{cfg.buildcfg}"

	files 
	{
		"%{prj.name}/src/engine/**.cpp",
		"%{prj.name}/src/game/**.h"

	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLEW_STATIC"
		}

		includedirs
		{
			"dependencies/glfw/include",
			"dependencies/glew/include"
		}

		libdirs
		{
			"dependencies/glfw/lib",
			"dependencies/glew/lib"
		}

		links
		{
			"glfw3",
			"glew32s",
			"opengl32"
		}