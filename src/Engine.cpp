//
// Created by Marine on 13/01/2021.
//

#include "Engine.h"
#include <iostream>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <vector>

void Engine::setup(int width, int height, bool debug) {
	glfwInit();
	initWindow(width, height,debug);

	std::cout << "Driver: " << glGetString(GL_VERSION) << "\n";
	std::cout<< "GPU: " << glGetString(GL_RENDERER) << "\n";

	if(debug){
		activateDebugMode();
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetCursorPosCallback(window, mouse_callback);
}

void Engine::mouse_callback(GLFWwindow* window, double xpos, double ypos){
	if (Engine::instance->firstMouse)
	{
		Engine::instance->firstMouse = false;
	}
}

void Engine::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

int Engine::initWindow(int width, int height, bool debug) {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if(debug){
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	}

	window = glfwCreateWindow(width, height, "ProjetPhong", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, width, height); //set la zone sur laquelle tu fais ton rendu

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//resize

	glEnable(GL_DEPTH_TEST);
	return 1;
}

void Engine::messageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
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

void Engine::activateDebugMode(){
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(messageCallback,nullptr);
}

void Engine::processInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Engine::run() {
	std::cout << "run" << "\n";

	while (!glfwWindowShouldClose(window)) {

		//events
		glfwPollEvents();// check les evenements qui ont eu lieu depuis le dernier appel de cette fonction
		//inputs
		processInput();

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//rendering

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		GLuint _vbo;
		std::vector<glm::vec2> vertices;
		//glCreateBuffers(1, &_vbo);
		//glNamedBufferData(_vbo, vertices.size() * sizeof(glm::vec2), vertices.data(), GL_STATIC_DRAW);//GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW

		//bind
		//glDrawElements(GL_LINE_LOOP, /*taille des indices*/, GL_UNSIGNED_SHORT, nullptr);

		_uiHandler.update();
		_uiHandler.render();

		//swap
		glfwSwapBuffers(window); //échange les deux buffers (back buffer = tu fais ton rendu, front buffer = ton image affichée)
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
