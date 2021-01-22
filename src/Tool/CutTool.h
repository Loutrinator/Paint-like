//
// Created by Marine on 21/01/2021.
//
#pragma once

#include "ITool.h"

class CutTool : public ITool {
public:
	using ITool::ITool;

	void update(ShapeRegistry &registry, glm::ivec2 cursorPos, CursorState cursorState) override;
	void drawUI() override;
	std::string getName() override;
private:
	Polygon* _currentPolygon = nullptr;

	void cutPolygons(ShapeRegistry &registry);
};
