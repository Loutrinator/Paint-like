#ifndef SETTINGS_H
#define SETTINGS_H

#include <imgui.h>
#include <memory>
#include "Tool/ITool.h"

class Context {
public:
	Context();
	
	glm::vec3 getColor();
    void setColor(glm::vec3 color);
    
	ITool* getCurrentTool();
	void setCurrentTool(std::unique_ptr<ITool>&& tool);

private:
    glm::vec3 _currentColor;
    std::unique_ptr<ITool> _currentTool;
};

#endif //SETTINGS_H
