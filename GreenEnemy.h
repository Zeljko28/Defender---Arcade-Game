#pragma once

class GreenEnemy
{
	private:
		float g_enemy_x; 
		float g_enemy_y;
		float ge_x_speed, ge_y_speed;
		bool is_alive;
		bool out;

	public:
		GreenEnemy(float x, float y, float x_speed, float y_speed);
		void draw();
		void move();

		bool bulletCollision(float bullet_x, float bullet_y, int bullet_direction);
		void explosion();

		float getX();
		float getY();

		void setOut(bool m_out);
};

