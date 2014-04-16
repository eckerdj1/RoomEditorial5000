#include "Face.h"


Face::Face(void)
{
}

Face::Face(Vertex one, 
		   Vertex two, 
		   Vertex three, 
		   Vertex four) //Pass by value, opportunity for optimization?
{
	//Set up the halfedges, but don't assign verticies yet.
	halfedge = new HalfEdge(); //HE0
	halfedge->ownerFace = this;
	halfedge->id = idCounter++;

	halfedge->nextEdge = new HalfEdge();
	HalfEdge* HE1 = halfedge->nextEdge;
	HE1->id = idCounter++;
	HE1->ownerFace = this;
	
	halfedge->nextEdge->nextEdge = new HalfEdge();
	HalfEdge* HE2 = halfedge->nextEdge->nextEdge; //Just identifier name alias
	HE2->id = idCounter++;
	HE2->symetric = halfedge; //Set symmetry pointers
	halfedge->symetric = HE2; //Set symmetry pointers
	HE2->ownerFace = this;

	halfedge->nextEdge->nextEdge->nextEdge = new HalfEdge();
	HalfEdge* HE3 = halfedge->nextEdge->nextEdge->nextEdge;
	HE3->id = idCounter++;
	HE3->symetric = HE1; //Set symmetry pointers
	HE1->symetric = HE3; //Set symmetry pointers
	HE3->ownerFace = this;
	
	//Now assign the vertecies.
	//Uses copy constructor of Vertex...creates new Vertex objects.
	halfedge->vertex = &one;
	halfedge->nextEdge->vertex = &two;
	halfedge->nextEdge->nextEdge->vertex = &three;
	halfedge->nextEdge->nextEdge->nextEdge->vertex = &four;

	//Calculate the normal
	vec4 calculatedNormal = calculateFaceNormal();

	//Store the normal in each vertex
	halfedge->vertex->normal = calculatedNormal;
	HE1->vertex->normal = calculatedNormal;
	HE2->vertex->normal = calculatedNormal;
	HE3->vertex->normal = calculatedNormal;
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