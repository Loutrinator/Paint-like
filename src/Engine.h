#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <memory>
#include "UIHandler.h"
#include "Renderer.h"

class Engine {
public:
	Engine(int width, int height, bool debug);
	~Engine();
	void run();

private:
	void activateDebugMode();
	void initWindow(int width, int height, bool debug);
	
	std::unique_ptr<Renderer> _renderer;
	
	ShapeRegistry _registry;
	
	GLFWwindow* _window;

	std::unique_ptr<UIHandler> _uiHandler;
	Settings _settings;
};
