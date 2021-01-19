#pragma once

#include "ITool.h"

class ExampleTool : public ITool
{
public:
	void update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState) override;
	void drawUI() override;

private:
	int _currentLineIndex = -1;
};


