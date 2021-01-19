#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <memory>
#include "UIHandler.h"

class Engine {
public:
	Engine(int width, int height, bool debug);
	~Engine();
	void run();

private:
	void activateDebugMode();
	void initWindow(int width, int height, bool debug);
	
	GLFWwindow* _window;

	UIHandler _uiHandler;
	Settings _settings;
};
