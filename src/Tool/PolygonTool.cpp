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
		    _lastPolygon = nullptr;
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
                _lastPolygon = _currentPolygon;
                _currentPolygon = nullptr;
			}else{
				_currentPolygon->vertices.emplace_back(cursorPos);
			}

		}
	}


}

void PolygonTool::drawUI() {
    if(ImGui::Begin("Polygon")){
		if(ImGui::Button("Undo")){
			_currentPolygon->vertices.pop_back();
		}
		if(_lastPolygon == nullptr) {

			ImGui::End();
			return;
		};
		if(ImGui::Button("Fill polygon")){
			// TODO fill polygon
		}
    }

	ImGui::End();
}

std::string PolygonTool::getName() {
	return "Polygon";
}

bool PolygonTool::isEditing() {
	return _currentPolygon != nullptr;
}
