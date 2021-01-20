#pragma once

#include "../ShapeRegistry.h"
#include "../Context.h"
#include "../Enum/CursorState.h"

class ITool
{
public:
	ITool(Context& context):
	_context(context)
	{}
	
	virtual void update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState) = 0;
	virtual void drawUI() = 0;

protected:
	Context& _context;
};