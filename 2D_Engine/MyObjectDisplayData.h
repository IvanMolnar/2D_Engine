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

struct dimension2d
{
	dimension2d(int width = 0, int height = 0)
	{
		w = width;
		h = height;
	}

	int w;
	int h;
};

struct SDL_Texture;

struct ObjectRect
{
	int x;
	int y;
	int w;
	int h;
};

class MyObjectDisplayData
{
public:

	position2d _position;
	dimension2d _dimension;
	int _drawLayer;

	
	std::string texturePath;

	SDL_Texture* gTexture;
};