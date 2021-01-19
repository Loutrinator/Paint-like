#include "Context.h"
#include "Tool/ExampleTool.h"

Context::Context():
_currentColor(1.0, 0.0, 0.0), _currentTool(std::make_unique<ExampleTool>())
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
	return _currentTool ? _currentTool.get() : nullptr;
}

void Context::setCurrentTool(std::unique_ptr<ITool>&& tool)
{
	_currentTool = std::move(tool);
}
