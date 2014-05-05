//Author(s):Andrew Claudy, Dan Ecker
//COMP 361
//Due May 5th, 2014
//Desc: 

#include "HalfEdge.h"

HalfEdge::HalfEdge(void)
{
	id = -1;
	ownerFace	= nullptr;
	vertex		= nullptr;
	symetric	= nullptr;
	nextEdge	= nullptr;
}

HalfEdge::HalfEdge(const HalfEdge& copy)
{
	//ajc: I was tired when I wrote this...it might be wrong.

	//dje: I changed this to copy's id. I think it was wrong. 
	id = copy.id;//++;
	ownerFace	= copy.ownerFace;
	vertex		= copy.vertex;
	symetric	= copy.symetric;
	nextEdge	= copy.nextEdge;
}

HalfEdge::~HalfEdge(void)
{
	if(vertex != nullptr)
		delete vertex;
}

void HalfEdge::setSym(HalfEdge* he)
{
	symetric = he;
	he->symetric = this;
}

void HalfEdge::copyPointers(HalfEdge* he)
{
	nextEdge = he->nextEdge;
	vertex = he->vertex;
}

HalfEdge* HalfEdge::previousEdge()
{
	HalfEdge* current = this;

	do
	{
		current = current->nextEdge;
	}while (current->nextEdge != this && current->nextEdge != 0);

	return current;
}

