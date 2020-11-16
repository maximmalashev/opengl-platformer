#include <GL/glew.h>

#include "vbo.h"

namespace engine {

	VBO::VBO(float data[])
	{
		glGenBuffers(1, &m_id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	}

	void VBO::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	void VBO::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	VBO::~VBO() { }
}