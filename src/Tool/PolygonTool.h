#pragma once

#include "ITool.h"

class PolygonTool  : public ITool {
public:
	using ITool::ITool;

	void update(ShapeRegistry &registry, glm::ivec2 cursorPos, CursorState cursorState) override;
	void drawUI() override;
	std::string getName() override;
private:
	Polygon* _currentPolygon = nullptr;
};