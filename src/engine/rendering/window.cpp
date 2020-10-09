#include "window.h"

#include "../logging/logger.h"

namespace engine {

	Window::Window(uint32_t width, uint32_t height, const std::string& title)
	{
		if (!glfwInit())
		{
			Logger::Log(Logger::MessageType::FATAL, "Failed to initialize glfw");
			std::exit(-1);
		}

		m_windowInstance = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!m_windowInstance)
		{
			Logger::Log(Logger::MessageType::FATAL, "Failed to create a window");

			glfwTerminate();
			std::exit(-1);
		}

		Logger::Log(Logger::MessageType::INFO, "Window created");

		glfwMakeContextCurrent(m_windowInstance);

		UpdateViewport();

		m_width = width;
		m_height = height;
		m_title = title;
	}

	void Window::UpdateViewport()
	{
		glfwGetFramebufferSize(m_windowInstance, &m_viewportWidth, &m_viewportHeight);
	}

	bool Window::GetShouldClose()
	{
		return glfwWindowShouldClose(m_windowInstance);
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_windowInstance);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::SetDimensions(uint32_t newWidth, uint32_t newHeight)
	{
		glfwSetWindowSize(m_windowInstance, newWidth, newHeight);
		UpdateViewport();

		m_width = newWidth;
		m_height = newHeight;
	}

	void Window::SetTitle(const std::string& newTitle)
	{
		glfwSetWindowTitle(m_windowInstance, newTitle.c_str());

		m_title = newTitle;
	}

	Window::~Window()
	{
		Logger::Log(Logger::MessageType::INFO, "Closing...");
		glfwTerminate();
	}
}