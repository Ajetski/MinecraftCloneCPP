#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include "GameEngine.hpp"
#include <cmath>

void reshapeFunc(int, int);
void drawFunc();
void timerFunc(int);

GameEngine* engine;
bool* temp;
float z = -5;
const float PI = 3.1415928479323846;

GameEngine::GameEngine() {
	player_var = new Player;
	player_var->setPos(0, 2, 0);
	player_var->setRot(0, 0);

	map_var = new Map;

	reshape = reshapeFunc;
	draw = drawFunc;
	timer = timerFunc;

	engine = this;
	temp = &a_key;

	w_key = false;
	a_key = false;
	s_key = false;
	d_key = false;
	left_key = false;
	right_key = false;
	up_key = false;
	down_key = false;
	shift_key = false;
	ctrl_key = false;
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
	glutReshapeFunc(reshape);
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutTimerFunc(0, timer, 0);

	glClearColor(0.1f, 0.6f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);


	glutMainLoop();
	return 0;
}

const Player* GameEngine::player() const {
	return player_var;
}

const Map* GameEngine::map() const {
	return map_var;
}


void GameEngine::update() {
	//check keyboard values
	//update based off of them
	
	handleKeyPress();

	float movementSpeed = .25;
	//float rotateSpeed = ;

	if (w_key)
		player_var->deltaZ(-movementSpeed);
	if (a_key)
		player_var->deltaX(-movementSpeed);
	if (s_key)
		player_var->deltaZ(movementSpeed);
	if (d_key)
		player_var->deltaX(movementSpeed);
	if (shift_key)
		player_var->deltaY(movementSpeed);
	if (ctrl_key)
		player_var->deltaY(-movementSpeed);
	if (left_key)
		player_var->deltaYaw(movementSpeed);
	if (right_key)
		player_var->deltaYaw(-movementSpeed);
	if (up_key)
		player_var->deltaPitch(-movementSpeed);
	if (down_key)
		player_var->deltaPitch(movementSpeed);
}

void GameEngine::handleKeyPress() {
	if (GetAsyncKeyState('W') & 0x8000)
		w_key = true;
	else
		w_key = false;
	if (GetAsyncKeyState('A') & 0x8000)
		a_key = true;
	else
		a_key = false;
	if (GetAsyncKeyState('S') & 0x8000)
		s_key = true;
	else
		s_key = false;
	if (GetAsyncKeyState('D') & 0x8000)
		d_key = true;
	else
		d_key = false;
	if (GetKeyState(VK_SHIFT) & 0x8000)
		shift_key = true;
	else
		shift_key = false;
	if (GetKeyState(VK_CONTROL) & 0x8000)
		ctrl_key = true;
	else
		ctrl_key = false;
	if (GetKeyState(VK_LEFT) & 0x8000)
		left_key = true;
	else
		left_key = false;
	if (GetKeyState(VK_RIGHT) & 0x8000)
		right_key = true;
	else
		right_key = false;
	if (GetKeyState(VK_UP) & 0x8000)
		up_key = true;
	else
		up_key = false;
	if (GetKeyState(VK_DOWN) & 0x8000)
		down_key = true;
	else
		down_key = false;

}


void drawFunc() {
	//draw world
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/*
	const unsigned int size = engine->map()->size();*/
	const Player* player = engine->player();
	float xRotScalar = cos(PI * player->yaw() / 180);
	float zRotScalar = sin(PI * player->yaw() / 180);

	//loop to each thing to draw
	for(int x = -3; x <= 3; x++){
		for (int z = -3; z <= -3; z++) {
			glLoadIdentity();
			//glRotatef(-player->yaw(), 0, 1, 0);
			glRotatef(-player->yaw(), 0, 1, 0);
			glRotatef(-player->pitch(), xRotScalar, 0, -zRotScalar);
			glTranslatef(x, 0, z);
			glTranslatef(-player->x(), -player->y(), -player->z());
			engine->drawCube();
		}
	}

	//draw entities


	glutSwapBuffers();
}


void reshapeFunc(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
}

void timerFunc(int) {
	engine->update(); //for animation
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timerFunc, 0);
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
	glColor3f(.588235f, 0.29411f, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	//back
	glColor3f(.588235f, 0.29411f, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	//left
	glColor3f(.588235f, 0.29411f, 0.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//right
	glColor3f(.588235f, 0.29411f, 0.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	//bottom
	glColor3f(0.2461f, 0.5039f, 0.1562f); // ?
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//top
	glColor3f(.588235f, 0.29411f, 0.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
}


void GameEngine::clean() {
	delete player_var;
	delete map_var;
}