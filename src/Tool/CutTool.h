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
	bool isEditing() override;
private:
	Polygon* _currentPolygonWindow = nullptr;

	void cutPolygons(ShapeRegistry &registry);
	static bool intersection(glm::vec2 p0, glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2* i);
	static bool isInside(glm::vec2 p, glm::vec2 p1, glm::vec2 p2);
};
