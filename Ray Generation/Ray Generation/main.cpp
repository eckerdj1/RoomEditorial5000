/**
 * An example program that creates a 24-bit bitmap file that is 800 x 600 and makes a blue/red checkerboard pattern.
 * Uses EasyBMP
 *
 * Cory Boatright
 * University of Pennsylvania, Fall 2011
 **/

#include "EasyBMP.h"
#include "glm\glm.hpp"

using namespace std;

int main(int argc, char** argv) {
	unsigned int width = 800;
	unsigned int height = 600;

	BMP output;
	output.SetSize(width, height);
	output.SetBitDepth(24);
	
	glm::vec3 M = glm::vec3(0, 0, 1);
	glm::vec3 V = glm::vec3(0, 1, 0);	//should take into account trig (like tangent..) and half-angle for fovy in the notes
	glm::vec3 H = glm::vec3(1, 0, 0);	//should take into account the aspect ratio
			

	for(unsigned int x = 0; x < width; x++) {
		for(unsigned int y = 0; y < height; y++) {
			float w = (2 * x / ((float)width - 1) - 1);
			float h = (2 * y / ((float)height - 1) - 1);
			glm::vec3 P = M + w * H + h * V;
			glm::vec3 E = glm::vec3(0, 0, 0);
			glm::vec3 D = glm::normalize(P - E);

			glm::vec3 color = D;
			//ebmpBYTE color;

			output(x, y)->Red = abs(color.x) * 255;
			output(x, y)->Green = abs(color.y) * 255;
			output(x, y)->Blue = abs(color.z) * 255;

			//if(x % 2 == 0) {
			//	if(y % 2 == 0) {
			//		output(x, y)->Red = 255;
			//		output(x, y)->Blue = 0;
			//		output(x, y)->Green = 0;
			//	}
			//	else {
			//		output(x, y)->Red = 0;
			//		output(x, y)->Blue = 255;
			//		output(x, y)->Green = 0;
			//	}
			//}
			//else {
			//	if(y % 2 == 0) {
			//		output(x, y)->Red = 0;
			//		output(x, y)->Blue = 255;
			//		output(x, y)->Green = 0;
			//	}
			//	else {
			//		output(x, y)->Red = 255;
			//		output(x, y)->Blue = 0;
			//		output(x, y)->Green = 0;
			//	}
			//}
		}
	}

	output.WriteToFile("output.bmp");
	return 0;
}