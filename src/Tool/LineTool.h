#pragma once

#include "ITool.h"

class LineTool : public ITool
{
public:
	using ITool::ITool;
	
	void update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState) override;
	void drawUI() override;
	std::string getName() override;
	bool isEditing() override;

private:
	Line* _currentLine = nullptr;
};


