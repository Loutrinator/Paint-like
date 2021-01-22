#pragma once

#include <string>
#include "../ShapeRegistry.h"
#include "../Context.h"
#include "../Enum/CursorState.h"
#include <string>

class ITool
{
public:
	ITool(Context& context):
	_context(context)
	{}
	
	virtual void update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState) = 0;
	virtual void drawUI() = 0;
	virtual std::string getName() = 0;
	virtual bool isEditing() = 0;

protected:
	Context& _context;
};
