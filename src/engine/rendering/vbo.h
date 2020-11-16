#pragma once

#include <inttypes.h>

namespace engine {

	class VBO
	{
	public:
		VBO(float data[]);

		void Bind();
		void Unbind();

		~VBO();
	private:
		uint32_t m_id;
};

}

