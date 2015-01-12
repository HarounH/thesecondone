/**
Compile instructions : g++ <fileName> -o <executableName> -lGL -lGLU -lglut
*/

//Glut includes
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

//Standard includes
#include <iostream>
#include <vector>


#include <math.h>
#define PI 3.14159
using namespace std;

//Called by the glut command thingy to display stuff onto the window
void display(){
	glClearColor(0.4, //R
				0.3, //G
				0.2, //B
				0.5); //Transparecny
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_TRIANGLES); //Begin drawing a triangle.
		glColor3f(1.0 , 0.0 , 0.0);
		glVertex2f(0.0 , 0.0);
		glColor3f(0.0,1.0,1.0);
		glVertex2f( tan( PI/6 ) , 0.0);
		glColor3f(0.0 , 0.0 , 1.0);
		glVertex2f(0.0 , 1.0);
	glEnd();

	glBegin(GL_TRIANGLES); //Begin drawing a triangle.
		glColor3f(1.0 , 0.0 , 0.0);
		glVertex2f(0.0 , 0.0);
		glColor3f(0.0,0.0,1.0);
		glVertex2f( tan( PI/6 ) , 0.0);
		glColor3f(0.0 , 1.0 , 0.0);
		glVertex2f(0.0 , 1.0);
	glEnd();

	glFlush();
	glutSwapBuffers();

}

class myGLTriangle {
public:
	pair< float , float > vertices[3];
};

int main(int argc, char** argv) {

	glutInit(&argc,argv);	//Glut initialization ( of the command thingy? )
	int firstWindow = glutCreateWindow("COP290 Hello World"); // Title of the dabba is hellow world
	//glutWindowSize(800 , 800);		//size is 800x800 pixels
	//glutWindowPosition(50,50);
	glutReshapeWindow(800,800);
	glutDisplayFunc(display) ; //sets the display function of glut command thingy to "display()"
	glutMainLoop(); //Start the main loop
	return 0; //INT main
}
