#pragma once

#include "Shape/Polygon.h"
#include "Shape/Line.h"
#include "Shape/Point.h"
#include <vector>

struct ShapeRegistry
{
	std::vector<Polygon> polygons;
	std::vector<Line>    lines;
	std::vector<Point>   points;
};