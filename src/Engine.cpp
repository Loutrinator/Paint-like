#include <iostream>
#include <stdexcept>
#include "Engine.h"
#include "ShapeRegistry.h"

Engine::Engine(int width, int height, bool debug):
_imGuiContext(ImGui::CreateContext())
{
	glfwInit();
	initWindow(width, height, debug);
	
	std::cout << "Driver: " << glGetString(GL_VERSION) << "\n";
	std::cout << "GPU: " << glGetString(GL_RENDERER) << "\n";
	
	if (debug)
	{
		activateDebugMode();
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetCursorPosCallback(window, mouse_callback);
	
	ImGui::SetCurrentContext(_imGuiContext);
    //ImGui::StyleColorsDark();
}

Engine::~Engine()
{
	glfwTerminate();
}

void Engine::initWindow(int width, int height, bool debug)
{
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (debug)
	{
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	}
	
	_window = glfwCreateWindow(width, height, "Pènte", nullptr, nullptr);
	if (_window == nullptr)
	{
		throw std::runtime_error("Failed to create GLFW window");
	}
	
	glfwMakeContextCurrent(_window);
	
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to initialize GLAD");
	}
}

void messageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	switch (severity)
	{
		case GL_DEBUG_SEVERITY_HIGH:
			std::cout << "ERROR " << id << ": " << message << std::endl;
			//if (IsDebuggerPresent())
			//	__debugbreak();
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			std::cout << "WARNING " << id << ": " << message << std::endl;
			break;
		case GL_DEBUG_SEVERITY_LOW:
			std::cout << "INFO " << id << ": " << message << std::endl;
			break;
	}
}

void Engine::activateDebugMode()
{
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(messageCallback, nullptr);
}

void Engine::run()
{
	while (!glfwWindowShouldClose(_window))
	{
		//events
		glfwPollEvents();// check les evenements qui ont eu lieu depuis le dernier appel de cette fonction
		
		//rendering
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

        _uiHandler.update();
        _uiHandler.render();

		//swap
		glfwSwapBuffers(_window); //échange les deux buffers (back buffer = tu fais ton rendu, front buffer = ton image affichée)
	}
}

std::unique_ptr<Engine> Engine::instance = std::make_unique<Engine>();


Engine::Engine() : _settings(), _uiHandler(&_settings, window) {
	deltaTime = 0.0f;
	lastFrame = glfwGetTime();
}

void Engine::terminate() {
	glfwTerminate();
}
