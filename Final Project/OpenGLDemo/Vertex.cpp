#include "Vertex.h"


Vertex::Vertex(void)
{
	++idCounter;
}

Vertex::Vertex(const Vertex& copy) //Copy CTOR
{
	this->id		= copy.id;
	this->position	= copy.position;
	this->color		= copy.color;
	this->normal	= copy.normal;
}

Vertex::Vertex(vec4 position_, vec3 color_, vec4 normal_)
{
	id = idCounter++;
	position	= position_;
	color		= color_;
	normal		= normal_;
}

Vertex::~Vertex(void)
{
}
