#pragma once

#include "window.h"

#include <string>

namespace engine {

	class Application
	{
	public:
		static void Initialize(uint32_t windowWidth, uint32_t windowHeight, const std::string& title);
		static void Start();
	
	private:
		static Window* currentWindow;
	};

}