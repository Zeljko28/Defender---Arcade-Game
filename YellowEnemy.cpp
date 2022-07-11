#include "YellowEnemy.h"
#include "Spaceship.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include "Bullet.h"
#include <vector>

YellowEnemy::YellowEnemy(float x, float y, float x_speed, float y_speed) {
	y_enemy_x = x;
	y_enemy_y = y;
	ye_x_speed = x_speed;
	ye_y_speed = y_speed;
	is_alive = true;
	out = false;
}

void YellowEnemy::draw() {
	if (!out) {
		glPushMatrix();

		glColor3f(0.0f, 1.0f, 0.0f);

		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x, y_enemy_y);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x, y_enemy_y - 3.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x - 3.0f, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x - 3.0f, y_enemy_y - 9.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 15.0f);
		glVertex2f(y_enemy_x, y_enemy_y - 15.0f);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x - 3.0f, y_enemy_y - 15.0f);
		glVertex2f(y_enemy_x, y_enemy_y - 15.0f);
		glVertex2f(y_enemy_x, y_enemy_y - 18.0f);
		glVertex2f(y_enemy_x - 3.0f, y_enemy_y - 18.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x - 6.0f, y_enemy_y - 18.0f);
		glVertex2f(y_enemy_x - 3.0f, y_enemy_y - 18.0f);
		glVertex2f(y_enemy_x - 3.0f, y_enemy_y - 21.0f);
		glVertex2f(y_enemy_x - 6.0f, y_enemy_y - 21.0f);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x + 9.0f, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x + 9.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 9.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 6.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 9.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 9.0f, y_enemy_y - 21.0f);
		glVertex2f(y_enemy_x + 6.0f, y_enemy_y - 21.0f);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 15.0f, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x + 18.0f, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x + 18.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 15.0f, y_enemy_y - 9.0f);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 12.0f, y_enemy_y);
		glVertex2f(y_enemy_x + 15.0f, y_enemy_y);
		glVertex2f(y_enemy_x + 15.0f, y_enemy_y - 15.0f);
		glVertex2f(y_enemy_x + 12.0f, y_enemy_y - 15.0f);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 15.0f, y_enemy_y - 15.0f);
		glVertex2f(y_enemy_x + 18.0f, y_enemy_y - 15.0f);
		glVertex2f(y_enemy_x + 18.0f, y_enemy_y - 18.0f);
		glVertex2f(y_enemy_x + 15.0f, y_enemy_y - 18.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 18.0f, y_enemy_y - 18.0f);
		glVertex2f(y_enemy_x + 21.0f, y_enemy_y - 18.0f);
		glVertex2f(y_enemy_x + 21.0f, y_enemy_y - 21.0f);
		glVertex2f(y_enemy_x + 18.0f, y_enemy_y - 21.0f);
		glEnd();


		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y + 3.0f);
		glVertex2f(y_enemy_x + 12.0f, y_enemy_y + 3.0f);
		glVertex2f(y_enemy_x + 12.0f, y_enemy_y - 3.0f);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 3.0f);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 6.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 6.0f, y_enemy_y - 12.0f);
		glVertex2f(y_enemy_x + 3.0f, y_enemy_y - 12.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(y_enemy_x + 9.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 12.0f, y_enemy_y - 9.0f);
		glVertex2f(y_enemy_x + 12.0f, y_enemy_y - 12.0f);
		glVertex2f(y_enemy_x + 9.0f, y_enemy_y - 12.0f);
		glEnd();

		glPopMatrix();
	}
}


void YellowEnemy::move(float x, float y) {
	if (y_enemy_x >= x) {
		y_enemy_x -= ye_x_speed;
	}

	if (y_enemy_x < x) {
		y_enemy_x += ye_x_speed;
	}

	if (y_enemy_y >= y) {
		y_enemy_y -= ye_y_speed;
	}

	if (y_enemy_y < y) {
		y_enemy_y += ye_y_speed;
	}
	/*if (y_enemy_x == x) {
		destroy
		lives -=1;
	}*/

	/*if (y_enemy_y == y) {
	destroy
	lives -=1;
}*/
	
}

bool YellowEnemy::bulletCollision(float bullet_x, float bullet_y, int bullet_direction) {

	if (bullet_direction == 0) {
		float d = sqrt(pow(y_enemy_x - bullet_x, 2) + pow(y_enemy_y - bullet_y, 2));
		if (d <= 20) {
			return true;
		}
		else {
			return false;
		}
	}

	else if (bullet_direction == 1) {
		float d = sqrt(pow((y_enemy_x + 30) - bullet_x, 2) + pow(y_enemy_y - bullet_y, 2));
		if (d <= 20) {
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


void YellowEnemy::setOut(bool m_out) {
	out = m_out;
}

float YellowEnemy::getX() {
	return y_enemy_x;
}

float YellowEnemy::getY() {
	return y_enemy_y;
}

void YellowEnemy::setAlive(bool m_alive) {
	is_alive = m_alive;
}