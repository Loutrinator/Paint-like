#include <glm/gtc/type_ptr.hpp>
#include "UIHandler.h"
#include "Tool/ITool.h"

UIHandler::UIHandler(Context* context, GLFWwindow* window):
_context(context), _imGuiContext(ImGui::CreateContext())
{
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

void UIHandler::update()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if(ImGui::Begin("Color"))
    {
	    glm::vec4 color = _context->getColor();
	    if (ImGui::ColorPicker4("Color", glm::value_ptr(color)))
	    {
		    _context->setColor(color);
	    }
    }
    ImGui::End();

    ImVec2 buttonSize(60, 40);
	std::string title = "Tool (current : " + _context->getCurrentTool()->getName() + ")";
    if(ImGui::Begin(title.c_str())){
        std::vector<std::unique_ptr<ITool>>& tools(_context->getTools());
        int toolsSize = tools.size();
        for(int i = 0; i < toolsSize; i++){
            std::unique_ptr<ITool>& currentTool = tools.at(i);
            if(ImGui::Button(currentTool->getName().c_str(), buttonSize)){
                _context->setCurrentTool(currentTool.get());
            }
            if(i < toolsSize - 1) ImGui::SameLine();
        }
    }
    ImGui::End();
    
    _context->getCurrentTool()->drawUI();
}

void UIHandler::render() {
    ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
