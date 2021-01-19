#include "Context.h"
#include "Tool/ExampleTool.h"
#include <cassert>

Context::Context():
_currentColor(1.0, 0.0, 0.0),
_currentTool(std::make_unique<ExampleTool>(*this))
{

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
	return _currentTool.get();
}

void Context::setCurrentTool(std::unique_ptr<ITool>&& tool)
{
	assert(tool); // prevent setting _currentTool to nullptr
	
	_currentTool = std::move(tool);
}
