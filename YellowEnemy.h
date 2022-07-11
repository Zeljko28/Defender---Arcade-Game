#pragma once
class YellowEnemy
{
private:
	float y_enemy_x;
	float y_enemy_y;
	float ye_x_speed, ye_y_speed;
	bool is_alive;
	bool out;

public:
	YellowEnemy(float x, float y, float x_speed, float y_speed);
	void draw();
	void move(float x, float y);

	bool bulletCollision(float bullet_x, float bullet_y, int bullet_direction); 
	void setOut(bool m_out);

	float getX();
	float getY();

	void setAlive(bool m_alive);
};

