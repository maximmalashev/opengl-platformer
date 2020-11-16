#include <GL/glew.h>

#include "renderer.h"
#include "../logging/logger.h"

namespace engine {
	
	void Renderer::Initialize()
	{
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK)
		{
			Logger::Log(Logger::MessageType::FATAL, "Failed to initialize glew");
			std::exit(-1);
		}
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::SetBackgroundColor()
	{
		glClearColor(0, 0, 0, 1);
	}

	void Renderer::DrawQuad()
	{

	}
}
