#pragma once

#include "../utils/color.h"

namespace engine {
	
	class Renderer
	{
	public:
		static void Initialize();

		static void SetBackgroundColor(Color color);
		static void Clear();

		static void DrawQuad();
	private:
	};

}