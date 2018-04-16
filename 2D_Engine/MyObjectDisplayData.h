#pragma once

#include <string>

struct position2d
{
	position2d(int xPos = 0, int yPos = 0)
	{
		x = xPos;
		y = yPos;
	}

	int x;
	int y;
};

struct SDL_Texture;
struct SDL_Rect;

class MyObjectDisplayData
{
public:
	position2d _position;
	int _drawLayer;

	SDL_Texture* gTexture;
	std::string texturePath;

	SDL_Rect* destination;
};