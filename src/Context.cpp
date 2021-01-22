#include "Context.h"
#include "Tool/LineTool.h"
#include "Tool/PolygonTool.h"
#include "Tool/CutTool.h"
#include <cassert>

Context::Context():
_currentColor(1.0, 0.0, 0.0,1.0)
{
	_tools.emplace_back(std::make_unique<LineTool>(*this));
	_tools.emplace_back(std::make_unique<PolygonTool>(*this));
	_tools.emplace_back(std::make_unique<CutTool>(*this));
	_currentTool = _tools.front().get();
}

glm::vec4 Context::getColor()
{
    return _currentColor;
}

void Context::setColor(glm::vec4 color)
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
