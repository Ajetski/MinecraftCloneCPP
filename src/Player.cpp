#include "Player.hpp"
#include <GL\glew.h>

void Player::setCamera() const {
	glLoadIdentity();
	glTranslatef(pos_x, pos_y, pos_z);
	glRotatef(rot_pitch, 1, 0, 0);
	glRotatef(rot_yaw, 0, 1, 0);
	//glRotatef(rot_roll, 0, 0, 1);
}

void Player::setPos(float x, float y, float z) {
	pos_x = x;
	pos_y = y;
	pos_z = z;
}

void Player::setRot(float pitch, float yaw /*, float roll*/) {
	rot_pitch = pitch;
	rot_yaw = yaw;
	//rot_roll = roll;
}

void Player::deltaX(float x) {
	pos_x += x;
}

void Player::deltaY(float y) {
	pos_y += y;
}

void Player::deltaZ(float z) {
	pos_z += z;
}

void Player::deltaPitch(float pitch) {
	rot_pitch += pitch;
	if (rot_pitch > 180)
		rot_pitch = 180;
	else if (rot_pitch < -180)
		rot_pitch = -180;
}

void Player::deltaYaw(float yaw) {
	rot_yaw += yaw;
	if (rot_yaw > 360)
		rot_yaw -= 360;
	else if (rot_yaw < 0)
		rot_yaw += 360;
}

const float& Player::x() const {
	return pos_x;
}

const float& Player::y() const {
	return pos_y;
}

const float& Player::z() const {
	return pos_z;
}

const float& Player::pitch() const {
	return rot_pitch;
}

/*
const float& Player::roll() const {
	return rot_roll;
}*/

const float& Player::yaw() const {
	return rot_yaw;
}

