//glut moving circle 

#include <GL/glut.h> //should include everything
#define P_HEIGHT 400
#define P_WIDTH 400

//Usual C++ includes
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Circle{
public:
	float xCentre , yCentre;
	float radius;
	float color[] = { 1.0 , 1.0 , 1.0 , 1.0};

}myCircle;

//Header file kinda thing
void eventHandler(); //The function that handles events/interrupts(keyboard/mouse)
void display(); //The display function that is required by openGL
void init(); //Takes care of initialization



//Main loop.
int main(int argc, char** argv) {
	myCircle.xCentre = 0.0;
	myCircle.yCentre = 0.0;
	myCircle.radius = 2.0;
	glutInit(&argc , char** argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(P_HEIGHT , P_WIDTH); //Window sizes defined earlier.
	glutInitWindowPosition(50,50); //ARbit values.
	int window1 = glutCreateWindow("Moving Cirlce");
	init(); //Dfined below
	glutDisplayFunc(display);
	glutSpecialFunc(eventHandler);
	glutMainLoop();

	return 0;
}

void init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFLush();
}