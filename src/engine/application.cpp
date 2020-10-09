#include "application.h"

#include <iostream>

namespace engine {

	Window* Application::currentWindow = nullptr;

	void Application::Initialize(uint32_t windowWidth, uint32_t windowHeight, const std::string& title)
	{
		currentWindow = new Window(windowWidth, windowHeight, title);
	}
	void Application::Start()
	{
		if (!currentWindow) 
		{
			std::exit(-1);
		}

		while (!currentWindow->GetShouldClose())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			currentWindow->SwapBuffers();
			currentWindow->PollEvents();
		}

		glfwTerminate();
	}
}
