#include "UIHandler.h"

UIHandler::UIHandler(Settings* settings, GLFWwindow* window) : _settings(settings), _imGuiContext(ImGui::CreateContext()){
    ImGui::SetCurrentContext(_imGuiContext);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 450 core");

    //ImGui::StyleColorsDark();
}

UIHandler::~UIHandler()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	
	ImGui::DestroyContext(_imGuiContext);
}

void UIHandler::update() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
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
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
