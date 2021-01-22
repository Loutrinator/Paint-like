#include "Renderer.h"
#include "Tool/PolygonTool.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

Renderer::Renderer(glm::ivec2 windowSize):
		_mainShader("shader"), _outlineShader("outline"), _size(windowSize), _orthoProj(glm::ortho(0.0f, (float)_size.x, (float)_size.y, 0.0f, 0.0f, 1.0f))
{
	glClearColor(1, 1, 1, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


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

void Renderer::render(const ShapeRegistry& registry, const Context& context)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	_mainShader.setMat4("u_projection", _orthoProj);
	_outlineShader.setMat4("u_projection", _orthoProj);
	float t = (float)glfwGetTime();
	_outlineShader.setFloat("u_time", t);


	_mainShader.bind();
	glBindVertexArray(_vao);
	
	renderPolygons(registry.polygons, context);
	renderLines(registry.lines);
	renderPoints(registry.points);
	renderMasks(registry.masks);
	
	glBindVertexArray(0);
	glUseProgram(0);
}

void Renderer::renderPolygons(const std::vector<Polygon>& polygons, const Context& context)
{
	for (int i = 0; i < polygons.size(); ++i) {
		const Polygon& polygon = polygons.at(i);
		std::vector<Vertex> vertices;
		std::vector<Vertex> outsideVertices;

		for (glm::vec2 vertex : polygon.vertices)
		{
			vertices.emplace_back(vertex, polygon.color);
			outsideVertices.emplace_back(vertex, glm::vec4(1));
		}

		_mainShader.bind();
		glNamedBufferData(_polygonVBO, vertices.size() * sizeof(Vertex), vertices.data(), GL_DYNAMIC_DRAW);

		glVertexArrayVertexBuffer(_vao, 0, _polygonVBO, 0, sizeof(Vertex));

		glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());
		PolygonTool* polygonTool  = dynamic_cast<PolygonTool*>(context.getCurrentTool());
		if(polygonTool != nullptr){
			if(polygonTool->isEditing()){
				if( i >= polygons.size()-1){_outlineShader.bind();
					glLineWidth(2.0f);//TODO: fournir une épaisseur aux lignes et pencil

					glNamedBufferData(_lineVBO, outsideVertices.size() * sizeof(Vertex), outsideVertices.data(), GL_DYNAMIC_DRAW);

					glVertexArrayVertexBuffer(_vao, 0, _lineVBO, 0, sizeof(Vertex));

					glDrawArrays(GL_LINE_LOOP, 0, outsideVertices.size());
					glLineWidth(1.0f);
					_mainShader.bind();
				}
			}
		}


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

	glNamedBufferData(_lineVBO, vertices.size() * sizeof(Vertex), vertices.data(), GL_DYNAMIC_DRAW);

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
	
	glNamedBufferData(_pointVBO, vertices.size() * sizeof(Vertex), vertices.data(), GL_DYNAMIC_DRAW);
	
	glVertexArrayVertexBuffer(_vao, 0, _pointVBO, 0, sizeof(Vertex));
	
	glDrawArrays(GL_POINTS, 0, vertices.size());
}

void Renderer::renderMasks(std::vector<Polygon> masks) {

	for (const Polygon& mask : masks)
	{
		std::vector<Vertex> vertices;
		std::vector<Vertex> outsideVertices;

		for (glm::vec2 vertex : mask.vertices)
		{
			outsideVertices.emplace_back(vertex, glm::vec4(1));
		}


		_outlineShader.bind();
		glLineWidth(2.0f);//TODO:

		glNamedBufferData(_lineVBO, outsideVertices.size() * sizeof(Vertex), outsideVertices.data(), GL_DYNAMIC_DRAW);

		glVertexArrayVertexBuffer(_vao, 0, _lineVBO, 0, sizeof(Vertex));

		glDrawArrays(GL_LINE_LOOP, 0, outsideVertices.size());
		glLineWidth(1.0f);
		_mainShader.bind();
	}
}
