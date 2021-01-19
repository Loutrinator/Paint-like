#pragma once

#include "../ShapeRegistry.h"

enum CursorState
{
	PRESSED,
	HELD,
	RELEASED,
	NONE
};

class ITool
{
public:
	virtual void update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState) = 0;
	virtual void drawUI() = 0;
};