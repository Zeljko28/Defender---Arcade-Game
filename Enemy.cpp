#include "Enemy.h"
#include "Spaceship.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include "Bullet.h";
#include "GreenEnemy.h"

Enemy::Enemy(float m_x, float m_y, float m_x_speed, float m_y_speed, int type) {
	
	if (type == 1) {
		GreenEnemy(m_x, m_y, m_x_speed, m_y_speed);
	}

}

