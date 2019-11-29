#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include "GameEngine.hpp"

GameEngine::GameEngine() {
	player = new Player;
	map = new Map;
}

int GameEngine::init(int* argcp, char **argv) {
	//init
	// Initialize GLUT
	glutInit(argcp, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(920, 920);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Minecraft Clone CPP");
	// Bind the two functions (above) to respond when necessary

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	//set glut/gl functions
	glutReshapeFunc(this->reshape);
	glutDisplayFunc(this->draw);
	glutTimerFunc(0, this->timer, 0);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);


	glutMainLoop();
}


void GameEngine::update() {
	//check keyboard values
	//update based off of them
	

	
	//player->setCamera();
}

void GameEngine::draw() {
	//draw world
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//loop to each thing to draw

	glutSwapBuffers();
	//draw entities
}


void GameEngine::reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
}

void GameEngine::timer(int) {
	update(); //for animation
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, this->timer, 0);
}



void GameEngine::drawSquare() {
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

void GameEngine::drawCube() {
	glBegin(GL_QUADS);
	//front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	//back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	//right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//left
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	//top
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//bottom
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
}


void GameEngine::clean() {
	delete player;
	delete map;
}