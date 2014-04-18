//Andrew Claudy
//Tests convexity of a list of points in 3D coordinate space

#pragma once
#include <vector>
using std::vector;
#include <glm/glm.hpp>
using glm::vec4;
bool isConvexPolygon(const vector<vec4>& verts);