#include "Player.h"

Player::Player(Vec2 in_pos, Vec2 in_vel)
{
	pos = in_pos;
	vel = in_vel;
}

void Player::Update(Keyboard& kbd, Graphics& gfx, Box box, float dt)
{
	pos.x += vel.x * dt;
	pos.y += vel.y * dt;
	vel *= .9;

	if(kbd.KeyIsPressed('W'))
	{
		vel.y = -300;
	}
	if (kbd.KeyIsPressed('S'))
	{
		vel.y = 300;
	}
	if (kbd.KeyIsPressed('D'))
	{
		vel.x = 300;
	}
	if (kbd.KeyIsPressed('A'))
	{
		vel.x = -300;
	}

	if (CollisionTest(box))
	{
		if (vel.x > 0 )
		{
			pos.x = box.GetPos().x - width;
			vel.x = 0;
		}
		if (vel.x < 0)
		{
			pos.x = box.GetPos().x + box.GetWidth();
			vel.x = 0;
		}
		/*if (vel.y > 0)
		{
			pos.y = box.GetPos().y - height;
			vel.y = 0;
		}
		if (vel.y < 0)
		{
			pos.y = box.GetPos().y + box.GetHeight();
			vel.y = 0;
		}*/
	}
}

void Player::Draw(Graphics& gfx)
{
	for (int y = pos.y; y < pos.y + height; y++)
	{
		for (int x = pos.x; x < pos.x + width; x++)
		{
			gfx.PutPixel(x, y, c);
		}
	}
}

bool Player::CollisionTest(Box box)
{
	return pos.x < box.GetPos().x + box.GetWidth() &&
		   pos.x + width > box.GetPos().x &&
		   pos.y < box.GetPos().y + box.GetHeight() &&
		   pos.y + height > box.GetPos().y;
}
