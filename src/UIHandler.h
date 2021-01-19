#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "Settings.h"

class UIHandler {
public:
    UIHandler(Settings* settings, GLFWwindow* window);
    void update();
    void render();

private:
    Settings* _settings;
    ImGuiContext* _imGuiContext;
};


#endif //UIHANDLER_H
