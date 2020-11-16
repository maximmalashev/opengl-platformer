#pragma once

#include <inttypes.h>

namespace engine {

	class IBO
	{
	public:
		IBO(float data[]);

		void Bind();
		void Unbind();

		~IBO();
	private:
		uint32_t m_id;
	};

}

