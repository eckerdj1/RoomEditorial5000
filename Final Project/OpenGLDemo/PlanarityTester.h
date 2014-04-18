//Andrew Claudy
//Tests planarity of a dataset in 3D coordinates
/*
Remember to always use counter-clockwise winding order
Checking for planarity:
1 point
• Always "planar" because there are infinite planes going through the point.
2 point
• Always "planar" too because there are infinite planes going though the axis formed
3 points
• One plane formed by the triangle
• Degenerate cases: 3+ points in a line
4 points or more
• It could be true or false. 3 points could be making a plane and the 4th might be off the plane.
• Actually, 3 points could make a plane and the nth might be off the plane

The test. For each point, record the normals. If any are not the same it's not planar. 
Enhanced version: record the normal of the first point.
If any subsequent normal is not equal value to the normal of the first point then the whole set is not planar.
*/

#pragma once
#include <vector>
using std::vector;
#include <glm/glm.hpp>
using glm::vec4;
bool checkPlanarity(const vector<vec4>& pts);