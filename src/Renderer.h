#pragma once

#include "ShapeRegistry.h"
#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>


struct Vertex
{
	glm::vec2 position;
	glm::vec4 color;

	Vertex(glm::vec2 position, glm::vec4 color):
			position(position), color(color)
	{

	}
};

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

	Shader _mainShader;
	Shader _outlineShader;
	
	glm::mat4 _orthoProj;
	
	void renderPolygons(const std::vector<Polygon>& polygons);
	void renderLines(const std::vector<Line>& lines);
	void renderPoints(const std::vector<Point>& points);

	void renderMasks(std::vector<Polygon> vector);
};
