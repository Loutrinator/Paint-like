#ifndef CONTEXT_H
#define CONTEXT_H

#include <imgui.h>
#include <memory>
#include <glm/glm.hpp>
#include <vector>

class ITool;

class Context {
public:
	Context();
	
	glm::vec3 getColor();
    void setColor(glm::vec3 color);
    
	ITool* getCurrentTool();
	void setCurrentTool(ITool* tool);
	
	std::vector<std::unique_ptr<ITool>>& getTools();

private:
    glm::vec3 _currentColor;
    ITool* _currentTool;
    
	std::vector<std::unique_ptr<ITool>> _tools;
};

#endif //CONTEXT_H
