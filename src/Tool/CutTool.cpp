//
// Created by Marine on 21/01/2021.
//

#include <iostream>
#include "CutTool.h"

void CutTool::update(ShapeRegistry &registry, glm::ivec2 cursorPos, CursorState cursorState) {
	if(_currentPolygonWindow != nullptr) {
        _currentPolygonWindow->color = _context.getColor();
		glm::vec2 lastPos = _currentPolygonWindow->vertices.front();
		float distance = glm::distance(lastPos, static_cast<glm::vec2>(cursorPos));
		if(distance < 15){
            _currentPolygonWindow->vertices.back() = lastPos;
		}else{
            _currentPolygonWindow->vertices.back() = cursorPos;
		}
	}
	if(cursorState == CursorState::RELEASED){
		if(_currentPolygonWindow == nullptr){
			Polygon poly;
			poly.color = _context.getColor();
			poly.vertices.emplace_back(cursorPos);
			poly.vertices.emplace_back(cursorPos);
			registry.masks.push_back(poly);
            _currentPolygonWindow = &registry.masks.back();
		}else{
			glm::vec2 lastPos = _currentPolygonWindow->vertices.front();
			float distance = glm::distance(lastPos, static_cast<glm::vec2>(cursorPos));
			if(distance < 15){
				_currentPolygonWindow->vertices.pop_back();
				cutPolygons(registry);
                _currentPolygonWindow = nullptr;
			}else{
				_currentPolygonWindow->vertices.emplace_back(cursorPos);
			}
		}
	}
}

void CutTool::drawUI() {

}

std::string CutTool::getName() {
    return "Cut";
}

void CutTool::cutPolygons(ShapeRegistry &registry) {
    std::vector<glm::vec2> windowPoints = _currentPolygonWindow->vertices;
    int windowPtsLen = windowPoints.size();
    for(Polygon& polygon : registry.polygons){    // iterate over polygons
        std::vector<glm::vec2> outputPoints;
        for(int w = 0; w < windowPtsLen; w++) { // iterate over window points
            glm::vec2 wP0 = windowPoints.at(0);
            glm::vec2 wP1 = windowPoints.at(1);
            std::vector<glm::vec2> inputPoints = polygon.vertices;
            outputPoints.clear();

            int inputSize = inputPoints.size();
            for(int i = 1; i < inputSize; i++){ // iterate over current polygon points
                glm::vec2 currentPoint = inputPoints.at(i);
                int indPrev = (i - 1) % inputSize;
                glm::vec2 prevPoint = inputPoints.at(indPrev);

                glm::vec2 intersectingPoint = intersection(prevPoint, currentPoint, wP0, wP1);

                if(isInside(wP0, wP1, currentPoint)){
                    if(!isInside(wP0, wP1, prevPoint))
                        outputPoints.push_back(intersectingPoint);
                    outputPoints.push_back(currentPoint);
                } else if(isInside(wP0, wP1, prevPoint)){
                    outputPoints.push_back(intersectingPoint);
                }
            }
        }
        polygon.vertices = outputPoints;
    }
}



glm::vec2 CutTool::intersection(glm::vec2 cp1, glm::vec2 cp2, glm::vec2 s, glm::vec2 e) {
    glm::vec2 dc(cp1.x - cp2.x, cp1.y - cp2.y);
    glm::vec2 dp(s.x - e.x, s.y - e.y);

    float n1 = cp1.x * cp2.y - cp1.y * cp2.x;
    float n2 = s.x * e.y - s.y * e.x;
    float n3 = 1.0f / (dc.x * dp.y - dc.y * dp.x);

    return glm::vec2((n1 * dp.x - n2 * dc.x) * n3, (n1 * dp.y - n2 * dc.y) * n3);
}

bool CutTool::isInside(glm::vec2 p, glm::vec2 p1, glm::vec2 p2) {
    return (p2.y - p1.y) * p.x + (p1.x - p2.x) * p.y + (p2.x * p1.y - p1.x * p2.y) < 0;
}

bool CutTool::isEditing() {
	return _currentPolygonWindow != nullptr;
}
