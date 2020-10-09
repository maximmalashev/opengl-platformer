#include <iostream>

#include "../engine/application.h"

int main()
{
	engine::Application::Initialize(1080, 720, "OpenGL Window");
	engine::Application::Start();

	return 0;
}