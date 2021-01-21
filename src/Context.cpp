#include "Context.h"
#include "Tool/LineTool.h"
#include <cassert>

Context::Context():
_currentColor(1.0, 0.0, 0.0)
{
	_tools.emplace_back(std::make_unique<LineTool>(*this));
	_currentTool = _tools.front().get();
}

glm::vec3 Context::getColor()
{
    return _currentColor;
}

void Context::setColor(glm::vec3 color)
{
	_currentColor = color;
}

ITool* Context::getCurrentTool()
{
	assert(_currentTool); // ensure _currentTool is not null
	
	return _currentTool;
}

void Context::setCurrentTool(ITool* tool)
{
	assert(tool); // prevent setting _currentTool to nullptr
	
	_currentTool = tool;
}

std::vector<std::unique_ptr<ITool>>& Context::getTools()
{
	return _tools;
}
