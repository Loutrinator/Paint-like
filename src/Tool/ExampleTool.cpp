#include "ExampleTool.h"

void ExampleTool::update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState)
{
	if (cursorState == RELEASED)
	{
		if (_currentLineIndex == -1)
		{
			_currentLineIndex = registry.lines.size();
			
			Line line;
			line.pos1 = cursorPos;
			line.pos2 = cursorPos;
			line.color = glm::vec3(1, 0, 0);
			
			registry.lines.push_back(line);
		}
		else
		{
			registry.lines[_currentLineIndex].pos2 = cursorPos;
			_currentLineIndex = -1;
		}
	}
	else
	{
		if (_currentLineIndex != -1)
		{
			registry.lines[_currentLineIndex].pos2 = cursorPos;
		}
	}
}

void ExampleTool::drawUI()
{

}
