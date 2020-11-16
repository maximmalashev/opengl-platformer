#pragma once
#include "rendering/window.h"

#include <string>

namespace engine {

	class Application
	{
	public:
		static void Initialize(uint32_t windowWidth, uint32_t windowHeight, const std::string& title);
		static void Start();

		static inline Window* GetCurrentWindow() { return m_currentWindow; }
	
	private:
		static Window* m_currentWindow;
	};

}