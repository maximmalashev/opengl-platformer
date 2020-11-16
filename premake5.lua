workspace "opengl-platformer"
	configurations "debug"

project	"opengl-platformer"
	kind "ConsoleApp"
	language "C++"
	targetdir "out/%{cfg.buildcfg}"
	objdir "out/int/%{cfg.buildcfg}"

	files 
	{
		"src/engine/**.cpp",
		"src/game/**.cpp",
		"src/engine/**.h",
		"src/game/**.h"
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
			"dependencies/glew/include",
			"dependencies/glm"
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
			"opengl32",
			"gdi32.lib",
			"MSVCRT.lib"
		}