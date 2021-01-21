#include "ExampleTool.h"

void ExampleTool::update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState)
{
	if (_currentLine != nullptr)
	{
		_currentLine->color = _context.getColor();
		_currentLine->pos2 = cursorPos;
	}
	
	if (cursorState == RELEASED)
	{
		if (_currentLine == nullptr)
		{
			Line line;
			line.pos1 = cursorPos;
			line.pos2 = cursorPos;
			line.color = _context.getColor();
			
			registry.lines.push_back(line);
			
			_currentLine = &registry.lines.back();
		}
		else
		{
			_currentLine = nullptr;
		}
	}
}

void ExampleTool::drawUI()
{

}
