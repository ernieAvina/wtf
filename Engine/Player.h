#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Box.h"

class Player
{
public:
	Player() = default;
	Player(Vec2 in_pos, Vec2 in_vel);
	void Update(Keyboard& kbd, Graphics& gfx, Box box, float dt);
	void Draw(Graphics& gfx);
	bool CollisionTest(Box box);
private:
	Vec2 pos;
	Vec2 vel;
	float width = 50.0f;
	float height = 50.0f;
	Color c = Colors::Green;
};