#pragma once

#include "GLFW/glfw3.h"

#include <string>

namespace engine {

	class Window
	{
	public: 
		Window(uint32_t width, uint32_t height, const std::string& title);
		~Window();

		void UpdateViewport();

		inline uint32_t GetWidth() { return m_width; }
		inline uint32_t GetHeight() { return m_height; }
		inline std::string GetTitle() { return m_title; }

		inline int GetViewportWidth() { return m_viewportWidth; }
		inline int GetViewportHeight() { return m_viewportHeight; }

		bool GetShouldClose();
		void SwapBuffers();
		void PollEvents();

		void SetDimensions(uint32_t newWidth, uint32_t newHeight);
		void SetTitle(const std::string& newTitle);

	private:
		GLFWwindow* m_windowInstance;

		uint32_t m_width, m_height;
		std::string m_title;

		int m_viewportWidth, m_viewportHeight;
	};


}