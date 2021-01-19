#include "ExampleTool.h"

void ExampleTool::update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState)
{
	if (_currentLineIndex != -1)
	{
		registry.lines[_currentLineIndex].color = _context.getColor();
		registry.lines[_currentLineIndex].pos2 = cursorPos;
	}
	
	if (cursorState == RELEASED)
	{
		if (_currentLineIndex == -1)
		{
			_currentLineIndex = registry.lines.size();
			
			Line line;
			line.pos1 = cursorPos;
			line.pos2 = cursorPos;
			line.color = _context.getColor();
			
			registry.lines.push_back(line);
		}
		else
		{
			_currentLineIndex = -1;
		}
	}
}

void ExampleTool::drawUI()
{

}
