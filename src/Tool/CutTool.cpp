//
// Created by Marine on 21/01/2021.
//

#include "CutTool.h"

void CutTool::update(ShapeRegistry &registry, glm::ivec2 cursorPos, CursorState cursorState) {
	if(_currentPolygon != nullptr) {
		_currentPolygon->color = _context.getColor();
		glm::vec2 lastPos = _currentPolygon->vertices.front();
		float distance = glm::distance(lastPos, static_cast<glm::vec2>(cursorPos));
		if(distance < 15){
			_currentPolygon->vertices.back() = lastPos;
		}else{
			_currentPolygon->vertices.back() = cursorPos;
		}
	}
	if(cursorState == CursorState::RELEASED){
		if(_currentPolygon == nullptr){
			Polygon poly;
			poly.color = _context.getColor();
			poly.vertices.emplace_back(cursorPos);
			poly.vertices.emplace_back(cursorPos);
			registry.masks.push_back(poly);
			_currentPolygon = &registry.masks.back();
		}else{
			glm::vec2 lastPos = _currentPolygon->vertices.front();
			float distance = glm::distance(lastPos, static_cast<glm::vec2>(cursorPos));
			if(distance < 15){
				_currentPolygon->vertices.pop_back();
				cutPolygons(registry);
				_currentPolygon = nullptr;
			}else{
				_currentPolygon->vertices.emplace_back(cursorPos);
			}

		}
	}
}

void CutTool::drawUI() {

}

void CutTool::cutPolygons(ShapeRegistry &registry) {

}

std::string CutTool::getName() {
	return "Cut";
}
