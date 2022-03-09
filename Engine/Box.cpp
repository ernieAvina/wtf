#include "Box.h"

Box::Box(Vec2 in_pos)
{
	pos = in_pos;
}

void Box::Draw(Graphics& gfx)
{
	for (int y = pos.y; y < pos.y + height; y++)
	{
		for (int x = pos.x; x < pos.x + width; x++)
		{
			gfx.PutPixel(x, y, c);
		}
	}
}

void Box::SetColor(Color in_color)
{
	c = in_color;
}

Vec2 Box::GetPos()
{
	return pos;
}

float Box::GetWidth()
{
	return width;
}

float Box::GetHeight()
{
	return height;
}
