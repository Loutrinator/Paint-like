#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Engine.h"

int main()
{
	Engine::instance->setup(1000,800,true);

	Engine::instance->run();

	Engine::instance->terminate();

	return 0;
}