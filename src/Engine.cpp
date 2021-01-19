#include <iostream>
#include <stdexcept>
#include "Engine.h"
#include "ShapeRegistry.h"
#include "Enum/CursorState.h"
#include "Tool/ITool.h"

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

Engine::Engine(int width, int height, bool debug)
{
	glfwInit();
	initWindow(width, height, debug);
	
	_uiHandler = std::make_unique<UIHandler>(&_context, _window);
	
	std::cout << "Driver: " << glGetString(GL_VERSION) << "\n";
	std::cout << "GPU: " << glGetString(GL_RENDERER) << "\n";
	
	if (debug)
	{
		activateDebugMode();
	}
	
	_renderer = std::make_unique<Renderer>(glm::ivec2(width, height));
	
}

Engine::~Engine()
{
	glfwTerminate();
}

void Engine::initWindow(int width, int height, bool debug)
{
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
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
		
		//update
		ITool* tool = _context.getCurrentTool();
		if (!ImGui::GetIO().WantCaptureMouse)
		{
			glm::dvec2 cursorPos;
			glfwGetCursorPos(_window, &cursorPos.x, &cursorPos.y);
			
			CursorState cursorState;
			int cursorStateGLFW = glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT);
			if (_lastCursorState == GLFW_RELEASE && cursorStateGLFW == GLFW_PRESS)
				cursorState = PRESSED;
			else if (_lastCursorState == GLFW_PRESS && cursorStateGLFW == GLFW_PRESS)
				cursorState = HELD;
			else if (_lastCursorState == GLFW_PRESS && cursorStateGLFW == GLFW_RELEASE)
				cursorState = RELEASED;
			else // if (_lastCursorState == GLFW_RELEASE && cursorStateGLFW == GLFW_RELEASE)
				cursorState = NONE;
			
			tool->update(_registry, cursorPos, cursorState);
			
			_lastCursorState = cursorStateGLFW;
		}
		
		//rendering
		_renderer->render(_registry);
		
		//ui
        _uiHandler->update();
        _uiHandler->render();
		
		//swap
		glfwSwapBuffers(_window); //échange les deux buffers (back buffer = tu fais ton rendu, front buffer = ton image affichée)
	}
}
