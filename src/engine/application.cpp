#include "application.h"
#include "logging/logger.h"

#include <iostream>

namespace engine {

	Window* Application::m_currentWindow = nullptr;

	void Application::Initialize(uint32_t windowWidth, uint32_t windowHeight, const std::string& title)
	{
		m_currentWindow = new Window(windowWidth, windowHeight, title);
	}
	void Application::Start()
	{
		if (!m_currentWindow) 
		{
			std::exit(-1);
		}

		Logger::Log(Logger::MessageType::MESSAGE, "This is the usual text color!");
		Logger::Log(Logger::MessageType::WARNING, "This text should be yellow!");
		Logger::Log(Logger::MessageType::FATAL, "This text should be red!");
		while (!m_currentWindow->GetShouldClose())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			m_currentWindow->SwapBuffers();
			m_currentWindow->PollEvents();
		}

		glfwTerminate();
	}
}
