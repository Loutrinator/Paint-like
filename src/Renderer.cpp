#include "Renderer.h"
#include <glm/gtx/transform.hpp>

struct Vertex
{
	glm::vec2 position;
	glm::vec3 color;
	
	Vertex(glm::vec2 position, glm::vec3 color):
	position(position), color(color)
	{
	
	}
};

Renderer::Renderer(glm::ivec2 windowSize):
_shader("shader"), _size(windowSize)
{
	glClearColor(0, 0, 0, 0);
	
	glCreateVertexArrays(1, &_vao);
	
	glVertexArrayAttribFormat(_vao, 0, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
	glVertexArrayAttribBinding(_vao, 0, 0);
	glEnableVertexArrayAttrib(_vao, 0);
	
	glVertexArrayAttribFormat(_vao, 1, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, color));
	glVertexArrayAttribBinding(_vao, 1, 0);
	glEnableVertexArrayAttrib(_vao, 1);
	
	glCreateBuffers(1, &_polygonVBO);
	glCreateBuffers(1, &_lineVBO);
	glCreateBuffers(1, &_pointVBO);
}

void Renderer::render(const ShapeRegistry& registry)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	_shader.setMat4("u_projection", glm::ortho(0, _size.x, _size.y, 0, -10, 10));
	
	_shader.bind();
	glBindVertexArray(_vao);
	
	renderPolygons(registry.polygons);
	renderLines(registry.lines);
	renderPoints(registry.points);
	
	glBindVertexArray(0);
	glUseProgram(0);
}

void Renderer::renderPolygons(const std::vector<Polygon>& polygons)
{
	for (const Polygon& polygon : polygons)
	{
		std::vector<Vertex> vertices;
		
		for (glm::vec2 vertex : polygon.vertices)
		{
			vertices.emplace_back(vertex, polygon.color);
		}
		
		glNamedBufferData(_polygonVBO, vertices.size(), vertices.data(), GL_DYNAMIC_DRAW);
		
		glVertexArrayVertexBuffer(_vao, 0, _polygonVBO, 0, sizeof(Vertex));
		
		glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());
	}
}

void Renderer::renderLines(const std::vector<Line>& lines)
{
	std::vector<Vertex> vertices;
	
	for (const Line& line : lines)
	{
		vertices.emplace_back(line.pos1, line.color);
		vertices.emplace_back(line.pos2, line.color);
	}
	
	glNamedBufferData(_lineVBO, vertices.size(), vertices.data(), GL_DYNAMIC_DRAW);
	
	glVertexArrayVertexBuffer(_vao, 0, _lineVBO, 0, sizeof(Vertex));
	
	glDrawArrays(GL_LINES, 0, vertices.size());
}

void Renderer::renderPoints(const std::vector<Point>& points)
{
	std::vector<Vertex> vertices;
	
	for (const Point& point : points)
	{
		vertices.emplace_back(point.pos, point.color);
	}
	
	glNamedBufferData(_pointVBO, vertices.size(), vertices.data(), GL_DYNAMIC_DRAW);
	
	glVertexArrayVertexBuffer(_vao, 0, _pointVBO, 0, sizeof(Vertex));
	
	glDrawArrays(GL_POINTS, 0, vertices.size());
}
