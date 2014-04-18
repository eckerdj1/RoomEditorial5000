#include "SceneGraph.h"

SceneGraph::SceneGraph()
{
	height = 1.0f;
	width = 1;
	depth = 1;
	model = 0;
	transX = transY = transZ = 0.0f;
	scaleX = scaleY = scaleZ = 1.0f;
	rotY = 0.0f;
	children = new SceneGraph*[width * depth];
	for (int i=0; i<width * depth; ++i)
		children[i] = 0;
	next = 0;
}
SceneGraph::SceneGraph(int w, int d)
{
	height = 1.0f;
	width = w;
	depth = d;
	model = 0;
	transX = transY = transZ = 0.0f;
	scaleX = scaleY = scaleZ = 1.0f;
	rotY = 0.0f;
	children = new SceneGraph*[width * depth];
	for (int i=0; i<width * depth; ++i)
		children[i] = 0;
	next = 0;
}


void SceneGraph::setChildCount(int c)
{
	//rootChildCount = c;
}



void SceneGraph::linkGeometry(Geometry* geom)
{
	model = geom;
	height = model->getHeight();
}

void SceneGraph::setFloorSize(int x, int z)
{
	floorX = x;
	floorZ = z;
}



void SceneGraph::addChild(SceneGraph* sg, int x, int z)
{
	if (model)
	{
		sg->setTransY(model->getHeight());
	}

	if (children[x * depth + z])
	{
		children[x * depth + z]->addChild(sg);
	}
	else
	{
		sg->setTransX(-(floorX / 2.0f) + 0.5f + x);
		sg->setTransZ(-(floorZ / 2.0f) + 0.5f + z);
		children[x * depth + z] = sg;
	}
 }

void SceneGraph::addChild(SceneGraph* sg)
{
	if (model)
	{
		sg->setTransY(model->getHeight());
	}

	if (children[0])
	{
		children[0]->addChild(sg);
	}
	else
	{
		children[0] = sg;
	}
}

//void SceneGraph::traverse(mat4 m)
//{
//	mat4 tr = glm::translate(mat4(1.0f), vec3(transX, transY, transZ));
//	mat4 sc = glm::scale(mat4(1.0f), vec3(scaleX, scaleY, scaleZ));
//	mat4 ro = glm::rotate(mat4(1.0f), rotY, vec3(0.0f, 1.0f, 0.0f));
//
//	m = m * tr * ro * sc;
//
//	if (model)
//	{
//		model->draw(m);
//	}
//
//	for (int i=0; i<width * depth; ++i)
//	{
//		if (children[i])
//		{
//			children[i]->traverse(m);
//		}
//	}
//}

void SceneGraph::traverse(mat4 m)
{
	mat4 tr = glm::translate(mat4(1.0f), vec3(transX, transY, transZ));
	mat4 sc = glm::scale(mat4(1.0f), vec3(scaleX, scaleY, scaleZ));
	mat4 ro = glm::rotate(mat4(1.0f), rotY, vec3(0.0f, 1.0f, 0.0f));

	m = m * tr * ro * sc;

	if (model)
	{
		model->draw(m);
	}

	for (int i=0; i<width * depth; ++i)
	{
		if (children[i])
		{
			children[i]->traverse(m);
		}
	}
}

void SceneGraph::incNext()
{
	next++;
	if(next >= width * depth)
		next = 0;
	if(!children[next])
		incNext();
}

void SceneGraph::decNext()
{
	next--;
	if(next < 0)
		next = width * depth - 1;
	if(!children[next])
		decNext();
}

void SceneGraph::transXPos()
{
	children[next]->setTransX(++children[next]->transX);
}

void SceneGraph::transXNeg()
{
	children[next]->setTransX(--children[next]->transX);
}

void SceneGraph::transYPos()
{
	children[next]->setTransY(++children[next]->transY);
}

void SceneGraph::transYNeg()
{
	children[next]->setTransY(--children[next]->transY);
}

void SceneGraph::transZPos()
{
	children[next]->setTransZ(++children[next]->transZ);
}

void SceneGraph::transZNeg()
{
	children[next]->setTransZ(--children[next]->transZ);
}

void SceneGraph::scaleXPos()
{
	children[next]->setScaleX(children[next]->scaleX+.25f);
}

void SceneGraph::scaleXNeg()
{
	children[next]->setScaleX(children[next]->scaleX-.25f);
	if(children[next]->scaleX <= 0.0f)
		children[next]->setScaleX(0.01f);
}

void SceneGraph::scaleYPos()
{
	children[next]->setScaleY(children[next]->scaleY+.25f);
}

void SceneGraph::scaleYNeg()
{
	children[next]->setScaleY(children[next]->scaleY-.25f);
	if(children[next]->scaleY <= 0.0f)
		children[next]->setScaleY(0.01f);
}

void SceneGraph::scaleZPos()
{
	children[next]->setScaleZ(children[next]->scaleZ+.25f);
}

void SceneGraph::scaleZNeg()
{
	children[next]->setScaleZ(children[next]->scaleZ-.25f);
	if(children[next]->scaleZ <= 0.0f)
		children[next]->setScaleZ(0.01f);
}

void SceneGraph::rotLeft()
{
	children[next]->setRotY(children[next]->rotY-15);
}

void SceneGraph::rotRight()
{
	children[next]->setRotY(children[next]->rotY+15);
}