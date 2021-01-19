//
// Created by Marine on 19/01/2021.
//

#ifndef PAINTLIKE_POLYGON_H
#define PAINTLIKE_POLYGON_H


#include <glm/glm.hpp>
#include <vector>

struct Polygon {
	std::vector<glm::vec2> vertices;
	glm::vec3 color;
};


#endif //PAINTLIKE_POLYGON_H
