#include "SurfRev.h"

SurfaceRev::SurfaceRev()
{

}

SurfaceRev::~SurfaceRev()
{

}

void SurfaceRev::readData(ifstream& fin)
{
	fin >> sliceCount;
	fin >> polyLinePointCount;
	for (int i=0; i<polyLinePointCount; ++i)
	{
		float x, y;
		fin >> x >> y;
		vec4 point = vec4(x, y, 0.0f, 1.0f);
		polyLine.push_back(point);
	}
}

void SurfaceRev::makeSlices()
{
	slices.push_back(polyLine);
	
	for (int i=1; i<sliceCount; ++i)
	{
		float angle = (360.0f / (float)sliceCount) * i;
		mat4 lineRot = rotate(mat4(1.0f), angle,vec3(0.0f, 1.0f, 0.0f));
		vector<vec4> newPolyLine;
		for (int l=0; l<polyLinePointCount; ++l)
		{
			vec4 pos = polyLine[l];
			vec4 point = pos * lineRot;
			newPolyLine.push_back(point);
		}
		slices.push_back(newPolyLine);
	}
}

void SurfaceRev::triangulate()
{
	for (int i=1; i<=sliceCount; ++i)
	{
		for (int j=0; j<polyLinePointCount - 1; ++j)
		{
			vec4 point1, point2, point3, point4; 
			int thisSlice = i, prevSlice = i-1;
			int topPoint = j, lowerPoint = j+1;
			//wrap around to first slice again
			if (thisSlice == sliceCount)
				thisSlice = 0;
			//grab all the points
			point1 = slices[prevSlice][topPoint];
			point2 = slices[thisSlice][topPoint];
			point3 = slices[prevSlice][lowerPoint];
			point4 = slices[thisSlice][lowerPoint];

			if (point1 == point2)
			{     // one triangle
				triangle t = triangle(point1, point4, point3);
				faces.push_back(t);
			}
			else if (point3 == point4)
			{
				triangle t = triangle(point1, point2, point3);
				faces.push_back(t);
			}
			else
			{
				triangle t1 = triangle(point1, point2, point4);
				triangle t2 = triangle(point1, point4, point3);
				faces.push_back(t1);
				faces.push_back(t2);
			}
		}
	}
}

vector<triangle> SurfaceRev::getFaces()
{
	return faces;
}