#pragma once

#include "vertexBuffer.h"

namespace engine {

	class ArrayBuffer
	{
	public:
		ArrayBuffer();

		void attachVertexBuffer(VertexBuffer& vbo);

		inline unsigned int getId() const { return id; }

		void bind();
		void unbind();

		~ArrayBuffer();
	private:
		unsigned int id;
	};

}