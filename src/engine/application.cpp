#include "application.h"
#include "logging/logger.h"
#include "rendering/renderer.h"

#include <iostream>

namespace engine {

	Window* Application::m_currentWindow = nullptr;

	void Application::Initialize(uint32_t windowWidth, uint32_t windowHeight, const std::string& title)
	{
		Logger::Log(Logger::MessageType::INFO, "Initialization...");
		m_currentWindow = new Window(windowWidth, windowHeight, title);

		Renderer::Initialize();
	}
	void Application::Start()
	{
		if (!m_currentWindow) 
		{
			Logger::Log(Logger::MessageType::FATAL, "Engine has not been initialized");
			std::exit(-1);
		}

		while (!m_currentWindow->GetShouldClose())
		{
			Renderer::Clear();

			Renderer::DrawQuad();

			m_currentWindow->SwapBuffers();
			m_currentWindow->PollEvents();
		}

		m_currentWindow->~Window();
	}
}
