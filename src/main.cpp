#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// Init GLFW et charge les fonctions OpenGL
	glfwInit();
	gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "test", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}