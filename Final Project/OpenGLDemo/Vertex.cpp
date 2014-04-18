//Andrew Claudy

#include "Vertex.h"

Vertex::Vertex(void)
{
	++idCounter;
}

Vertex::Vertex(const Vertex& copy) //Copy CTOR
{
	this->id		= idCounter++; //DO NOT COPY copy.id, preserve id's uniqueness.
	this->position	= copy.position;
	this->color		= copy.color;
	this->normal	= copy.normal;
}

Vertex& Vertex::operator=(const Vertex& rhs) //danger: untested
{
	if(this == &rhs) //e.g., rhs = rhs;
        return *this; 
	//implied else
	return *(new Vertex(rhs.position, rhs.color, rhs.normal));
}

Vertex::Vertex(vec4 position_, vec3 color_, vec4 normal_)
{
	id			= idCounter++;
	position	= position_;
	color		= color_;
	normal		= normal_;
}

Vertex::Vertex(vec4 position_, vec3 color_) //Normal removed in this CTOR
{
	id			= idCounter++;
	position	= position_;
	color		= color_;
	normal		= vec4(0); //To be overwritten over anyways.
}

Vertex::Vertex(vec3 position_, vec3 color_, vec4 normal_)
{
	id			= idCounter++;
	position	= vec4(position_, 1); //Convert vec3 into vec4 point
	color		= color_;
	normal		= normal_;
}

Vertex::Vertex(vec3 position_, vec3 color_) //Normal removed in this CTOR
{
	id			= idCounter++;
	position	= vec4(position_, 1); //Convert vec3 into vec4 point
	color		= color_;
	normal		= vec4(0); //To be overwritten over anyways.
}

Vertex::~Vertex(void)
{
}
