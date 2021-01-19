#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "Context.h"

class UIHandler {
public:
    UIHandler(Context* context, GLFWwindow* window);
    ~UIHandler();
    void update();
    void render();

private:
	Context* _context;
    ImGuiContext* _imGuiContext;
};


#endif //UIHANDLER_H
