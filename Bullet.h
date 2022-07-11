#pragma once
class Bullet
{
	private:
		float x_bullet, y_bullet;
		float bullet_speed;
		int direction;
		bool out;

	public:
		Bullet(float m_x, float m_y, float m_x_speed, int m_direction);

		void draw();
		void move();
		float getX();
		float getY();
		float getDirection();
		//void keyboardFunction(unsigned char key);
		void setOut(bool m_out);
};

