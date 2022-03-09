#pragma once

#include "Graphics.h"

class Box
{
public:
	Box() = default;
	Box(Vec2 in_pos);
	void Draw(Graphics& gfx);
	void SetColor(Color in_color);
	Vec2 GetPos();
	float GetWidth();
	float GetHeight();
private:
	Vec2 pos;
	float width = 50.0f;
	float height = 50.0f;
	Color c = Colors::Red;
};

