//
// Created by Marine on 21/01/2021.
//

#include "PolygonTool.h"
void PolygonTool::update(ShapeRegistry &registry, glm::ivec2 cursorPos, CursorState cursorState) {
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
			registry.polygons.push_back(poly);
			_currentPolygon = &registry.polygons.back();
		}else{
			glm::vec2 lastPos = _currentPolygon->vertices.front();
			float distance = glm::distance(lastPos, static_cast<glm::vec2>(cursorPos));
			if(distance < 15){
				_currentPolygon->vertices.pop_back();
				_currentPolygon = nullptr;
			}else{
				_currentPolygon->vertices.emplace_back(cursorPos);
			}

		}
	}


}

void PolygonTool::drawUI() {

}

std::string PolygonTool::getName() {
	return "Polygon";
}
