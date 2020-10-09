#include "window.h"

namespace engine {

	Window::Window(uint32_t width, uint32_t height, const std::string& title)
	{
		if (!glfwInit())
		{
			std::exit(-1);
		}

		m_windowInstance = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!m_windowInstance)
		{
			glfwTerminate();
			std::exit(-1);
		}

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
	}

	void Window::SetTitle(const std::string& newTitle)
	{
		glfwSetWindowTitle(m_windowInstance, newTitle.c_str());
	}

	Window::~Window()
	{
		glfwTerminate();
	}
}