#include <glm/gtc/type_ptr.hpp>
#include "UIHandler.h"
#include "Tool/ITool.h"
#include "Shape/Image.h"

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

		Image picto("round.png");

		int frame_padding = 0;                             // -1 == uses default padding (style.FramePadding)
		ImVec2 size = ImVec2(32.0f, 32.0f);                     // Size of the image we want to make visible
		ImVec2 uv0 = ImVec2(0.0f, 0.0f);                        // UV coordinates for lower-left
		ImVec2 uv1 = ImVec2(32.0f / picto.getWidth(), 32.0f / picto.getHeight());// UV coordinates for (32,32) in our texture
		ImVec4 bg_col = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);         // Black background
		ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);       // No tint
		if (ImGui::ImageButton(reinterpret_cast<ImTextureID>(picto.getTextureId()), size, uv0, uv1, frame_padding, bg_col, tint_col));
    }
    ImGui::End();
	ImGui::ShowDemoWindow();
    _context->getCurrentTool()->drawUI();
}

void UIHandler::render() {
    ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
