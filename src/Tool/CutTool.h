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
	Polygon* _currentPolygonWindow = nullptr;

	void cutPolygons(ShapeRegistry &registry);
	glm::vec2 intersection(glm::vec2 p1, glm::vec2 p2, glm::vec2 f1, glm::vec2 f2);
	bool isBetween(glm::vec2 f1, glm::vec2 f2, glm::vec2 p);
};
