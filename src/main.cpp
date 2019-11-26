//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>


void init();
void timer(int);
void update();
void render();
void reshape(int w, int h);

int main(int argc, char* argv[]) {
	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(640, 640);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Hello, GL");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);

	glutTimerFunc(0, timer, 0);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	init();

	glutMainLoop();
	return 0;
}

void init() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

void timer(int) {
	//update(); //for animation
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}


//control animation
float x = -9;
int state = 1;

/*
void update() {
	if (state == 1) {
		if (x < 9)
			x += .1;
		else
			state = -1;
	}
	else if (state == -1) {
		if (x > -9)
			x -= .1;
		else
			state = 1;
	}
}*/

void drawSquare() {
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.5f);
	glVertex2f(-1.0, 1.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-1.0, -1.0);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(1.0, -1.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(1.0, 1.0);
	glEnd();
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//glTranslatef(x, x, 0.0);
	
	//drawSquare();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.7f);
	glVertex2f(-1.0, 1.0);
	glVertex2f(-1.0, -1.0);
	glVertex2f(1.0, -1.0);
	glVertex2f(1.0, 1.0);
	glEnd();

	

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective();
	glMatrixMode(GL_MODELVIEW);
}

