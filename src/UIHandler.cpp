#include "UIHandler.h"

UIHandler::UIHandler(Settings* settings, GLFWwindow* window) : _settings(settings), _imGuiContext(ImGui::CreateContext()){
    ImGui::SetCurrentContext(_imGuiContext);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460 core");

    //ImGui::StyleColorsDark();
}

void UIHandler::update() {
    ImGui::NewFrame();

    if(ImGui::BeginPopupContextWindow()){
        if(ImGui::MenuItem("Color :")){
            _settings->changeColor();
        }
        ImGui::EndPopup();
    }
}

void UIHandler::render() {
    ImGui::Render();
}
