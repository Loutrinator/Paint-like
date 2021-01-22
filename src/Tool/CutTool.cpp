//
// Created by Marine on 21/01/2021.
//

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

void CutTool::cutPolygons(ShapeRegistry &registry) {
    std::vector<glm::vec2> windowPoints = _currentPolygonWindow->vertices;
    int windowPtsLen = windowPoints.size();
    for(const Polygon& polygon : registry.polygons){    // iterate over polygons
        std::vector<glm::vec2> outputPoints;
        for(int w = 0; w < windowPtsLen - 1; w++) { // iterate over window points
            glm::vec2 wP0 = windowPoints.at(0);
            glm::vec2 wP1 = windowPoints.at(1);
            std::vector<glm::vec2> inputPoints = polygon.vertices;
            outputPoints.clear();

            int inputSize = inputPoints.size();
            for(int i = 0; i < inputSize; i++){ // iterate over current polygon points
                glm::vec2 currentPoint = inputPoints.at(i);
                glm::vec2 prevPoint = inputPoints.at((i-1)%inputSize);

                glm::vec2 intersectingPoint = intersection(prevPoint, currentPoint, wP0, wP1);

                if(isBetween(wP0, wP1, currentPoint)){
                    if(!isBetween(wP0, wP1, prevPoint))
                        outputPoints.push_back(intersectingPoint);
                    outputPoints.push_back(currentPoint);
                } else if(isBetween(wP0, wP1, prevPoint)){
                    outputPoints.push_back(intersectingPoint);
                }
            }
        }
    }
}

std::string CutTool::getName() {
	return "Cut";
}

glm::vec2 CutTool::intersection(glm::vec2 p1, glm::vec2 p2, glm::vec2 f1, glm::vec2 f2) {
    glm::vec2 result;

    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1*p1.x + b1*p1.y;

    double a2 = f2.y - f1.y;
    double b2 = f1.x - f2.x;
    double c2 = a2 * f1.x + f2.y;

    double det = a1 * b2 - a2 * b1;
    if(det == 0){
        result = glm::vec2(FLT_MAX, FLT_MAX);
    } else {
        double x = (b2 * c1 - b1 * c2) / det;
        double y = (a1 * c2 - a2 * c1) / det;
        result = glm::vec2(x, y);
    }

    return result;
}

bool CutTool::isBetween(glm::vec2 f1, glm::vec2 f2, glm::vec2 p) {
    double crossProduct = (p.y - f1.y) * (f2.x - f1.x) - (p.x - f1.x) * (f2.y - f1.y);
    if(abs(crossProduct) > 0.001f)
        return false;
    double dotProduct = (p.x - f1.x) * (f2.x - f1.x) + (p.y - f1.y)*(p.y - f1.y);
    if(dotProduct < 0)
        return false;
    double squaredLength = (f2.x - f1.x)*(f2.x - f1.x) + (f2.y - f1.y)*(f2.y - f1.y);
    if(dotProduct > squaredLength)
        return false;
    return true;
}
