#include "GameEngine.hpp"

GameEngine::GameEngine() {
	player = new Player;
	map = new Map;
}

void GameEngine::init() {
	//init
	//set glut/gl functions
}

void GameEngine::update() {
	//check keyboard values
	//update based off of them
}

void draw() {
	//draw world
	//draw entities
}

void GameEngine::clean() {
	delete player;
	delete map;
}
