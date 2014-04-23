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
	id = idCounter++;
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