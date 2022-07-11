#include "GreenEnemy.h"
#include "Spaceship.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include "Bullet.h"
#include <vector>

std::vector<int> dir = {-1, 0, 1};

GreenEnemy::GreenEnemy(float x, float y, float x_speed, float y_speed) {
	g_enemy_x = x;
	g_enemy_y = y;
	ge_x_speed = x_speed;
	ge_y_speed = y_speed;
	is_alive = true;
	out = false;
}

void GreenEnemy::draw() {

	if (!out) {

		glPushMatrix();

		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x, g_enemy_y);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y - 3.0f);
		glVertex2f(g_enemy_x, g_enemy_y - 3.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x - 3.0f, g_enemy_y - 3.0f);
		glVertex2f(g_enemy_x + 6.0f, g_enemy_y - 3.0f);
		glVertex2f(g_enemy_x + 6.0f, g_enemy_y - 9.0f);
		glVertex2f(g_enemy_x - 3.0f, g_enemy_y - 9.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x + 9.0f, g_enemy_y - 3.0f);
		glVertex2f(g_enemy_x + 18.0f, g_enemy_y - 3.0f);
		glVertex2f(g_enemy_x + 18.0f, g_enemy_y - 9.0f);
		glVertex2f(g_enemy_x + 9.0f, g_enemy_y - 9.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x, g_enemy_y - 9.0f);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y - 9.0f);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y - 12.0f);
		glVertex2f(g_enemy_x, g_enemy_y - 12.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x + 6.0f, g_enemy_y - 12.0f);
		glVertex2f(g_enemy_x + 9.0f, g_enemy_y - 12.0f);
		glVertex2f(g_enemy_x + 9.0f, g_enemy_y - 21.0f);
		glVertex2f(g_enemy_x + 6.0f, g_enemy_y - 21.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x, g_enemy_y - 12.0f);
		glVertex2f(g_enemy_x + 3.0f, g_enemy_y - 12.0f);
		glVertex2f(g_enemy_x + 3.0f, g_enemy_y - 15.0f);
		glVertex2f(g_enemy_x, g_enemy_y - 15.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x - 3.0f, g_enemy_y - 15.0f);
		glVertex2f(g_enemy_x, g_enemy_y - 15.0f);
		glVertex2f(g_enemy_x, g_enemy_y - 18.0f);
		glVertex2f(g_enemy_x - 3.0f, g_enemy_y - 18.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x - 6.0f, g_enemy_y - 18.0f);
		glVertex2f(g_enemy_x - 3.0f, g_enemy_y - 18.0f);
		glVertex2f(g_enemy_x - 3.0f, g_enemy_y - 21.0f);
		glVertex2f(g_enemy_x - 6.0f, g_enemy_y - 21.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x + 12.0f, g_enemy_y - 12.0f);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y - 12.0f);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y - 15.0f);
		glVertex2f(g_enemy_x + 12.0f, g_enemy_y - 15.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y - 15.0f);
		glVertex2f(g_enemy_x + 18.0f, g_enemy_y - 15.0f);
		glVertex2f(g_enemy_x + 18.0f, g_enemy_y - 18.0f);
		glVertex2f(g_enemy_x + 15.0f, g_enemy_y - 18.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(g_enemy_x + 18.0f, g_enemy_y - 18.0f);
		glVertex2f(g_enemy_x + 21.0f, g_enemy_y - 18.0f);
		glVertex2f(g_enemy_x + 21.0f, g_enemy_y - 21.0f);
		glVertex2f(g_enemy_x + 18.0f, g_enemy_y - 21.0f);
		glEnd();


		glPopMatrix();

	}
}

void GreenEnemy::move() {

	int m = rand() % dir.size();
	int x = dir[m];
	int n = rand() % dir.size();
	int y = dir[n];

	
	g_enemy_x = g_enemy_x + ge_x_speed * x;
	
	if (g_enemy_y < 350) {
		g_enemy_y = g_enemy_y + ge_y_speed * y;
	}

	else {
		g_enemy_y = g_enemy_y - ge_y_speed;
	}
}

bool GreenEnemy::bulletCollision(float bullet_x, float bullet_y, int bullet_direction) {

	if (bullet_direction == 0) {
		float d = sqrt(pow(g_enemy_x - bullet_x, 2) + pow(g_enemy_y - bullet_y, 2));
		if (d <= 20) {
			return true;
		}
		else {
			return false;
		}
	}

	else if (bullet_direction == 1) {
		float d = sqrt(pow((g_enemy_x + 30) - bullet_x, 2) + pow(g_enemy_y - bullet_y, 2));
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

void GreenEnemy::explosion() {

	
}

float GreenEnemy::getX() {
	return g_enemy_x;
}

float GreenEnemy::getY() {
	return g_enemy_y;
}

void GreenEnemy::setOut(bool m_out) {
	out = m_out;
}