#include "../include/UI.h"

void Chess::UI::init_UI(SDL_Renderer* ren,SDL_Color color, SDL_Rect rect)
{
	UI_Renderer = ren;
	UI_Color = color;
	UI_Box = rect;
}

void Chess::UI::setColor(int r, int g, int b, int a)
{
	UI_Color.r = r;
	UI_Color.g = g;
	UI_Color.b = b;
	UI_Color.a = a;
}

void Chess::UI::setPosition(int x, int y)
{
	UI_Box.x = x;
	UI_Box.y = y;
}

void Chess::UI::setSize(int w, int h)
{
	UI_Box.w = w;
	UI_Box.h = h;
}

SDL_Rect Chess::UI::getRect() const
{
	return UI_Box;
}