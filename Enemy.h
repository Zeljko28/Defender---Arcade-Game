#pragma once
class Enemy
{
	public:
		float enemy_x, enemy_y;
		float enemy_x_speed, enemy_y_speed;
		int type; // green = 1,  yellow = 2, red = 3

		Enemy(float x, float y, float x_speed, float y_speed, int type);

		virtual void draw();
		virtual void move();
};

