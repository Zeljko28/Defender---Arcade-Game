#pragma once

class Spaceship
{
	private:
		float x, y;
		float x_speed, y_speed;
		float direction = 1;
		int lives = 4;


	public:
		Spaceship(float m_x, float m_y, float m_x_speed, float m_y_speed);

		void draw();
		void move();
		void specialKeyFunction(int key);
		void specialKeyUpFunction(int key);
		void keyboardFunction(unsigned char key);
		float getX();
		float getY();
		int getDirection();

		bool enemyCollision(float enemy_x, float enemy_y);
		int getLives();
		void setLives(int num);
		
};

