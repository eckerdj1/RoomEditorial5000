#include "Face.h"


Face::Face(void)
{
}

Face::Face(Vertex one, Vertex two, Vertex three, Vertex four)
{
	//TODO: NEEDS IMPLEMENTED
}


Face::~Face(void)
{
}


void Face::useHalfEdges()
{
	//DO something.
	halfedge->vertex;
	HalfEdge* h = halfedge->nextEdge;
	//DO something.
	h = halfedge->nextEdge; //aka halfedge->symetric
	//DO something.
	h = halfedge->nextEdge;
	//Do something
	//Done going through the quad face.

	/////
	//Alternative
	/*
	halfedge->vertex;
	halfedge->nextEdge->vertex;
	halfedge->nextEdge->nextEdge->vertex; //aka half-edge->symetric
	halfedge->nextEdge->nextEdge->nextEdge->vertex;
	*/
}

glm::vec4 Face::calculateFaceNormal() const
{
	glm::vec3 AB = glm::vec3(halfedge->vertex - (halfedge->nextEdge->vertex));
	glm::vec3 BC = glm::vec3((halfedge->nextEdge->vertex) - (halfedge->nextEdge->nextEdge->vertex));
	glm::vec3 crossProduct = glm::cross(AB, BC);
	crossProduct = glm::normalize(crossProduct);
	return glm::vec4(crossProduct, 0.f); //make normal have w=0;
}