#include "color.h"

namespace engine {

	Color Color::red = Color(1, 0, 0, 1);
	Color Color::green = Color(0, 1, 0, 1);
	Color Color::blue = Color(0, 0, 1, 1);

	Color::Color(float r, float g, float b, float a) :r(r), g(g), b(b), a(a) { }

}