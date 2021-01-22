//
// Created by Marine on 21/01/2021.
//

#include <iostream>
#include "CutTool.h"
#include <glm/gtx/integer.hpp>

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
				registry.masks.pop_back();
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

bool CutTool::intersection(glm::vec2 p0, glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2* i)
{
	glm::vec2 s1, s2;
	s1 = p1 - p0;
	s2 = p3 - p2;
	
	float s, t;
	s = (-s1.y * (p0.x - p2.x) + s1.x * (p0.y - p2.y)) / (-s2.x * s1.y + s1.x * s2.y);
	t = ( s2.x * (p0.y - p2.y) - s2.y * (p0.x - p2.x)) / (-s2.x * s1.y + s1.x * s2.y);
	
	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		// Collision detected
		*i = p0 + (t * s1);
		return true;
	}
	
	return false; // No collision
}

void CutTool::cutPolygons(ShapeRegistry &registry) {
    std::vector<glm::vec2> windowPoints = _currentPolygonWindow->vertices;
    int windowPtsLen = windowPoints.size();
    for(Polygon& polygon : registry.polygons){    // iterate over polygons
        std::vector<glm::vec2> outputPoints = polygon.vertices;
        for(int w = 0; w < windowPtsLen; w++) { // iterate over window points
            glm::vec2 wP0 = windowPoints.at(w);
            glm::vec2 wP1 = windowPoints.at(glm::mod(w+1, windowPtsLen));
            
            std::vector<glm::vec2> inputPoints = outputPoints;
            outputPoints.clear();

            int inputSize = inputPoints.size();
            for(int i = 0; i < inputSize; i++){ // iterate over current polygon points
                glm::vec2 currentPoint = inputPoints.at(i);
                glm::vec2 nextPoint = inputPoints.at(glm::mod(i+1, inputSize));
	
	            glm::vec2 intersectingPoint;
	            bool intersect = intersection(currentPoint, nextPoint, wP0, wP1, &intersectingPoint);
	            
	            if (intersect)
	            {
		            if(isInside(wP0, wP1, currentPoint))
		            {
		            	outputPoints.push_back(currentPoint);
		            	outputPoints.push_back(intersectingPoint);
		            }
		            else if(isInside(wP0, wP1, nextPoint))
		            {
		            	outputPoints.push_back(intersectingPoint);
		            }
	            }
	            else
	            {
		            if(isInside(wP0, wP1, currentPoint))
		            {
			            outputPoints.push_back(currentPoint);
		            }
	            }
            }
        }
        polygon.vertices = outputPoints;
    }
}

bool CutTool::isInside(glm::vec2 p, glm::vec2 p1, glm::vec2 p2) {
    return (p2.y - p1.y) * p.x + (p1.x - p2.x) * p.y + (p2.x * p1.y - p1.x * p2.y) < 0;
}

bool CutTool::isEditing() {
	return _currentPolygonWindow != nullptr;
}
