#include <GL/glew.h>

#include "ibo.h"

namespace engine {

	IBO::IBO(float data[])
	{
		glGenBuffers(1, &m_id);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	}

	void IBO::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	}

	void IBO::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IBO::~IBO() { }

}