#include "Spaceship.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include "Bullet.h";

Spaceship::Spaceship(float m_x, float m_y, float m_x_speed, float m_y_speed) {
	x = m_x;
	y = m_y;
	x_speed = m_x_speed;
	y_speed = m_y_speed;
}

bool left = false;
bool right = false;
bool up = false;
bool down = false;

void Spaceship::draw() {
	
	glPushMatrix();

	if (direction == 0) {
		glTranslatef(x, y, 0);
		glRotatef(180, 0, 1, 0);
		glTranslatef(-x, -y, 0);
	}


	glColor3f(0.25f, 0.25f, 0.25f);

	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0f, y);
	glVertex2f(x + 15.0f, y);
	glVertex2f(x + 15.0f, y - 5.0f);
	glVertex2f(x - 10.0f, y - 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x, y - 5.0f);
	glVertex2f(x + 35.0f, y - 5.0f);
	glVertex2f(x + 35.0f,  y - 10.0f);
	glVertex2f(x, y - 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 5.0f, y - 10.0f);
	glVertex2f(x, y - 10.0f);
	glVertex2f(x, y - 15.0f);
	glVertex2f(x - 5.0f, y - 15.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 25.0f, y - 5.0f);
	glVertex2f(x - 20.0f, y - 5.0f);
	glVertex2f(x - 20.0f, y - 10.0f);
	glVertex2f(x - 25.0f, y - 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0f, y + 5.0f);
	glVertex2f(x, y + 5.0f);
	glVertex2f(x, y - 5.0f);
	glVertex2f(x - 10.0f, y - 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0f, y + 10.0f);
	glVertex2f(x - 5.0f, y + 10.0f);
	glVertex2f(x - 5.0f, y + 5.0f);
	glVertex2f(x - 10.0f, y + 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 25.0f, y + 10.0f);
	glVertex2f(x - 10.0f, y + 10.0f);
	glVertex2f(x - 10.0f, y);
	glVertex2f(x - 25.0f, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 20.0f, y + 15.0f);
	glVertex2f(x - 10.0f, y + 15.0f);
	glVertex2f(x - 10.0f, y + 10.0f);
	glVertex2f(x - 20.0f, y + 10.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(x + 15.0f, y);
	glVertex2f(x + 25.0f, y);
	glVertex2f(x + 25.0f, y - 5.0f);
	glVertex2f(x + 15.0f, y - 5.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(x + 25.0f, y);
	glVertex2f(x + 30.0f, y);
	glVertex2f(x + 30.0f, y - 5.0f);
	glVertex2f(x + 25.0f, y - 5.0f);
	glEnd();


	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(x + 35.0f, y - 5.0f);
	glVertex2f(x + 40.0f, y - 5.0f);
	glVertex2f(x + 40.0f, y - 10.0f);
	glVertex2f(x + 35.0f, y - 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x, y - 10.0f);
	glVertex2f(x + 5.0f, y - 10.0f);
	glVertex2f(x + 5.0f, y - 15.0f);
	glVertex2f(x, y - 15.0f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(x + 40.0f, y - 5.0f);
	glVertex2f(x + 45.0f, y - 5.0f);
	glVertex2f(x + 45.0f, y - 10.0f);
	glVertex2f(x + 40.0f, y - 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 5.0f, y - 10.0f);
	glVertex2f(x + 10.0f, y - 10.0f);
	glVertex2f(x + 10.0f, y - 15.0f);
	glVertex2f(x + 5.0f, y - 15.0f);
	glEnd();


	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(x - 20.0f, y);
	glVertex2f(x - 10.0f, y);
	glVertex2f(x - 10.0f, y - 15.0f);
	glVertex2f(x - 20.0f, y - 15.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0f, y - 5.0f);
	glVertex2f(x - 5.0f, y - 5.0f);
	glVertex2f(x - 5.0f, y - 15.0f);
	glVertex2f(x - 10.0f, y - 15.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 5.0f, y - 5.0f);
	glVertex2f(x, y - 5.0f);
	glVertex2f(x, y - 10.0f);
	glVertex2f(x - 5.0f, y - 10.0f);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(x - 30.0f, y + 5.0f);
	glVertex2f(x - 25.0f, y + 5.0f);
	glVertex2f(x - 25.0f, y);
	glVertex2f(x - 30.0f, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 25.0f, y);
	glVertex2f(x - 20.0f, y);
	glVertex2f(x - 20.0f, y - 5.0f);
	glVertex2f(x - 25.0f, y - 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 30.0f, y - 5.0f);
	glVertex2f(x - 25.0f, y - 5.0f);
	glVertex2f(x - 25.0f, y - 10.0f);
	glVertex2f(x - 30.0f, y - 10.0f);
	glEnd();





	glPopMatrix();

}


bool Spaceship::enemyCollision(float enemy_x, float enemy_y) {

	if (direction == 0) {
		float d = sqrt(pow(enemy_x - x, 2) + pow(enemy_y - y, 2));
		if (d <= 40) {
			return true;
		}
		else {
			return false;
		}
	}

	else if (direction == 1) {
		float d = sqrt(pow((enemy_x + 30) - x, 2) + pow(enemy_y - y, 2));
		if (d <= 40) {
			return true;
		}
		else {
			return false;
		}
	}

	else {
		return false;
	}

}


void Spaceship::move() {

	if (left) {
		x -= x_speed;
	}

	if (right) {
		x += x_speed;
	}

	if (up) {
		if (y < 360) {
			y += y_speed;
		}
	}
	if (down) {
		y -= y_speed;
	}
}


void Spaceship::specialKeyFunction(int key) {
	switch (key){

	case GLUT_KEY_RIGHT:
		if (direction == 0) {
			direction = 1;
		}
		right = true;
		left = false;
		break;


	case GLUT_KEY_LEFT:

		if (direction == 1) {
			direction = 0;

		}

		left = true;
		right = false;
		break;


	case GLUT_KEY_UP:
		up = true;
		down = false;
		break;

	case GLUT_KEY_DOWN:

		down = true;
		up = false;
		break;

	}
}


void Spaceship::specialKeyUpFunction(int key) {
	switch (key) {

	case GLUT_KEY_RIGHT:
		right = false;
		break;


	case GLUT_KEY_LEFT:
		left = false;
		break;


	case GLUT_KEY_UP:
		up = false;
		break;

	case GLUT_KEY_DOWN:
		down = false;
		break;

	}
}

void Spaceship::keyboardFunction(unsigned char key) {

/*	if (key == ' ') {
		Bullet bullet = Bullet(getX() + 50.0f, getY(), 0.5f);
		bullet.draw(direction);
	}*/

}

float Spaceship::getX() {
	return x;
}

float Spaceship::getY() {
	return y;
}

int Spaceship::getDirection() {
	return direction;
}

int Spaceship::getLives() {
	return lives;
}

void Spaceship::setLives(int num) {
	lives = num;
}

