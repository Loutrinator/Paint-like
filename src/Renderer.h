#pragma once

#include "ShapeRegistry.h"
#include "Shader.h"
#include <glad/glad.h>

class Renderer
{
public:
	Renderer(glm::ivec2 windowSize);
	void render(const ShapeRegistry& registry);

private:
	glm::ivec2 _size;
	
	GLuint _vao;
	
	GLuint _polygonVBO;
	GLuint _lineVBO;
	GLuint _pointVBO;
	
	Shader _shader;
	
	glm::mat4 _orthoProj;
	
	void renderPolygons(const std::vector<Polygon>& polygons);
	void renderLines(const std::vector<Line>& lines);
	void renderPoints(const std::vector<Point>& points);
};
