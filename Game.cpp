#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Glut.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "GreenEnemy.h"
#include "YellowEnemy.h"
#include <vector>
#include <ctime>


const double Xmin = 0.0, Xmax = 600;
const double Ymin = 0.0, Ymax = 480;
Spaceship spaceship(300.0f, 240.0f, 0.4f, 0.3f); //300.0f, 240.0f, 0.3f, 0.2f
std::vector<Bullet> bullets;
std::vector<GreenEnemy> g_enemies;

std::vector<float> ground_x;
std::vector<float> ground_y;

bool collision = false;


char lives[] = "LIVES: 4";

YellowEnemy y_enemy(500.0f, 350.0f, 0.05f, 0.05f);


void myKeyboardFunc(unsigned char key, int x, int y)
{
	
	if (key == ' ') {
		if (spaceship.getDirection() == 1) {
			bullets.push_back(Bullet(spaceship.getX() + 50.0f, spaceship.getY() - 3.0f, 0.7f, spaceship.getDirection()));
		}
		else if (spaceship.getDirection() == 0) {
			bullets.push_back(Bullet(spaceship.getX() - 50.0f, spaceship.getY() - 3.0f, 0.7f, spaceship.getDirection()));
		}
	}
}


void mySpecialKeyFunc(int key, int x, int y)
{
	spaceship.specialKeyFunction(key);
}

void mySpecialKeyUpFunc(int key, int x, int y)
{
	spaceship.specialKeyUpFunction(key);
}


void drawGround() {
	glColor3f(0.98f, 0.625f, 0.12f);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < ground_x.size(); i++) {
		glVertex2f(ground_x.at(i), ground_y.at(i));
	}
	glEnd();
}

void drawLives() {

	glPushMatrix();
	glColor3f(0.98, 0.625, 0.25);
	glTranslatef(spaceship.getX() - 400, 450, 0);
	glScalef(0.2, 0.2, 1);

	if (spaceship.getLives() == 3) { lives[7] = '3'; }
	if (spaceship.getLives() == 2) { lives[7] = '2'; }
	if (spaceship.getLives() == 1) { lives[7] = '1'; }
	if (spaceship.getLives() == 0) { lives[7] = '0'; }
	if (spaceship.getLives() < 0) { lives[7] = '0'; }


	for (int i = 0; i < 8; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, lives[i]);
	}
	glutStrokeCharacter(GLUT_STROKE_ROMAN, spaceship.getLives());
	glPopMatrix();
	
}

void drawGreenEnemies() {
	for (int j = 0; j < g_enemies.size(); j++) {

		g_enemies.at(j).move();
		g_enemies.at(j).draw();
	}
}

void collisionGreenEnemies() {
	for (int j = 0; j < bullets.size(); j++) {
		for (int n = 0; n < g_enemies.size(); n++) {
			if (g_enemies.at(n).bulletCollision(bullets.at(j).getX(), bullets.at(j).getY(), bullets.at(j).getDirection())) {
				g_enemies.erase(g_enemies.begin() + n);
				bullets.erase(bullets.begin() + j);
				break;
			}
		}
	}
}


void bulletsOut() {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets.at(i).getDirection() == 1) {
			if (bullets.at(i).getX() > spaceship.getX() + 450) {
				bullets.at(i).setOut(true);
				bullets.erase(bullets.begin() + i);
			}
		}
		else if (bullets.at(i).getDirection() == 0) {
			if (bullets.at(i).getX() < spaceship.getX() - 450) {
				bullets.at(i).setOut(true);
				bullets.erase(bullets.begin() + i);
			}
		}
	}
}

void yellowEnemiesHit() {
	if (sqrt(pow(spaceship.getX() - y_enemy.getX(), 2) + pow(spaceship.getY() - y_enemy.getY(), 2)) <= 20) {
		y_enemy.setAlive(false);
		collision = true;
	}
}


void greenEnemiesOut() {
	for (int i = 0; i < g_enemies.size(); i++) {
		if (g_enemies.at(i).getX() > spaceship.getX() + 450) {
			g_enemies.at(i).setOut(true);
		}
		
		else if (g_enemies.at(i).getX() < spaceship.getX() - 450) {
			g_enemies.at(i).setOut(true);
		}

		else {
			g_enemies.at(i).setOut(false);
		}
	}
	
}

void yellowEnemiesOut() {
		if (y_enemy.getX() > spaceship.getX() + 450) {
			y_enemy.setOut(true);
		}

		else if (y_enemy.getX() < spaceship.getX() - 450) {
			y_enemy.setOut(true);
		}

		else {
			y_enemy.setOut(false);
		}
}




void drawMinimap() {

	//glLoadIdentity();
	glPushMatrix();
	glTranslatef(300, 410, 0);
	glScalef(0.3, 0.2, 0);


	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-500 ,650);
	glVertex2f(500, 650);
	glVertex2f(500, -80);
	glVertex2f(-500, -80);
	glEnd();

	glTranslatef(-300, -410, 0);
	
	glTranslatef(Xmax / 2, 400, 0);
	glTranslatef(-spaceship.getX(), 0, 0);
	

	spaceship.draw();

	drawGreenEnemies();
	if (!collision) {
		y_enemy.draw();
	}
	for (int i = 0; i < bullets.size(); i++) {

		bullets.at(i).move();
		bullets.at(i).draw();
	}

	glPopMatrix();

}


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawMinimap();

	glTranslatef(Xmax/2, 0, 0);

	glTranslatef(-spaceship.getX(), 0, 0);

	drawLives();

	spaceship.move();
	for (int k = 0; k < g_enemies.size(); k++) {
		if (spaceship.enemyCollision(g_enemies.at(k).getX(), g_enemies.at(k).getY())) {
			spaceship.setLives(spaceship.getLives() - 1);
			g_enemies.erase(g_enemies.begin() + k);
		}
	}
	spaceship.draw();

	bulletsOut();
	for (int i = 0; i < bullets.size(); i++) {
		bullets.at(i).move();
		bullets.at(i).draw();
	}


	drawGround();

	collisionGreenEnemies();
	greenEnemiesOut();
	drawGreenEnemies();


	yellowEnemiesOut();
	yellowEnemiesHit();
	y_enemy.move(spaceship.getX(), spaceship.getY());
	for (int k = 0; k < bullets.size(); k++) {
		if (y_enemy.bulletCollision(bullets.at(k).getX(), bullets.at(k).getY(), bullets.at(k).getDirection())) {
			collision = true;
			break;
		}

	}
	if (!collision) {
		y_enemy.draw();
	}


	glFlush();
	glutSwapBuffers();

	
	glutPostRedisplay();
}


void spawnGreenEnemies() {
	srand((unsigned)time(0));
	int g_enemies_num = (rand() % 10) + 1;
	
	for (int i = 0; i < g_enemies_num; i++) {
		g_enemies.push_back(GreenEnemy(rand()%550 + 50, rand()%430 + 30, 0.3f, 0.3f));
	}
}

void spawnGround() {
	srand((unsigned)time(0));

	for (int i = -10000; i < 10000; i += 100) {
		ground_x.push_back(i);
		ground_y.push_back(rand() % 80 + 20);
	}

}



void initRendering()
{
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}


void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	glViewport(0, 0, w, h);

	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;
	if ((Xmax - Xmin) / w < (Ymax - Ymin) / h) {
		scale = ((Ymax - Ymin) / h) / ((Xmax - Xmin) / w);
		center = (Xmax + Xmin) / 2;
		windowXmin = center - (center - Xmin) * scale;
		windowXmax = center + (Xmax - center) * scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax - Xmin) / w) / ((Ymax - Ymin) / h);
		center = (Ymax + Ymin) / 2;
		windowYmin = center - (center - Ymin) * scale;
		windowYmax = center + (Ymax - center) * scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(windowXmin, windowXmax, windowYmin, windowYmax, -1, 1);

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	spawnGround();
	spawnGreenEnemies();

	glutInitWindowPosition(10, 60);
	glutInitWindowSize(360, 360);
	glutCreateWindow("DEFENDER");


	initRendering();

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialUpFunc(mySpecialKeyUpFunc);
	glutSpecialFunc(mySpecialKeyFunc);

	glutReshapeFunc(resizeWindow);
	glutDisplayFunc(drawScene);
	glutMainLoop();

	return(0);
}