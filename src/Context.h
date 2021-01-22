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
	
	glm::vec4 getColor() const;
    void setColor(glm::vec4 color);

	ITool* getCurrentTool() const;
	void setCurrentTool(ITool* tool);
	
	std::vector<std::unique_ptr<ITool>>& getTools();

private:
    glm::vec4 _currentColor;
    ITool* _currentTool;
    
	std::vector<std::unique_ptr<ITool>> _tools;
};

#endif //CONTEXT_H
