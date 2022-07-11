#include "Bullet.h"
#include "Spaceship.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "glut.h"


Bullet::Bullet(float m_x, float m_y, float x_speed, int m_direction) {
	x_bullet = m_x;
	y_bullet = m_y;
	bullet_speed = x_speed;
	direction = m_direction;
	out = false;
}

void Bullet::draw() {

	if (!out) {
		glPushMatrix();

		if (direction == 0) {
			glTranslatef(x_bullet, y_bullet, 0);
			glRotatef(180, 0, 1, 0);
			glTranslatef(-x_bullet, -y_bullet, 0);
		}

		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex2f(x_bullet, y_bullet);
		glVertex2f(x_bullet + 3.0f, y_bullet);
		glVertex2f(x_bullet + 3.0f, y_bullet - 3.0f);
		glVertex2f(x_bullet, y_bullet - 3.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x_bullet, y_bullet - 6.0f);
		glVertex2f(x_bullet + 3.0f, y_bullet - 6.0f);
		glVertex2f(x_bullet + 3.0f, y_bullet - 9.0f);
		glVertex2f(x_bullet, y_bullet - 9.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x_bullet + 3.0f, y_bullet - 3.0f);
		glVertex2f(x_bullet + 6.0f, y_bullet - 3.0f);
		glVertex2f(x_bullet + 6.0f, y_bullet - 6.0f);
		glVertex2f(x_bullet + 3.0f, y_bullet - 6.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x_bullet + 6.0f, y_bullet);
		glVertex2f(x_bullet + 12.0f, y_bullet);
		glVertex2f(x_bullet + 12.0f, y_bullet - 9.0f);
		glVertex2f(x_bullet + 6.0f, y_bullet - 9.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x_bullet + 12.0f, y_bullet);
		glVertex2f(x_bullet + 15.0f, y_bullet);
		glVertex2f(x_bullet + 15.0f, y_bullet - 3.0f);
		glVertex2f(x_bullet + 12.0f, y_bullet - 3.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x_bullet + 12.0f, y_bullet - 6.0f);
		glVertex2f(x_bullet + 15.0f, y_bullet - 6.0f);
		glVertex2f(x_bullet + 15.0f, y_bullet - 9.0f);
		glVertex2f(x_bullet + 12.0f, y_bullet - 9.0f);
		glEnd();

		glColor3f(0.5f, 0.0f, 0.5f);
		glBegin(GL_POLYGON);
		glVertex2f(x_bullet + 12.0f, y_bullet - 3.0f);
		glVertex2f(x_bullet + 18.0f, y_bullet - 3.0f);
		glVertex2f(x_bullet + 18.0f, y_bullet - 6.0f);
		glVertex2f(x_bullet + 12.0f, y_bullet - 6.0f);
		glEnd();

		glPopMatrix();
	}
}

void Bullet::move() {

	if (direction == 1) {
		x_bullet += bullet_speed;
	}

	else if (direction == 0) {
		x_bullet -= bullet_speed;
	}

}

float Bullet::getX() {
	return x_bullet;
}

float Bullet::getY() {
	return y_bullet;
}

float Bullet::getDirection() {
	return direction;
}

void Bullet::setOut(bool m_out) {
	out = m_out;
}
