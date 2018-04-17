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
	void updatePosition(position2d& position)
	{
		_x = position.x * _cellSize;
		_y = position.y * _cellSize;
	}

	void updateDimenstion(dimension2d& dimension)
	{
		_w = dimension.w;
		_h = dimension.h;
	}

	int _x;
	int _y;
	int _w;
	int _h;
	int _cellSize = 50;
};

class MyObjectDisplayData
{
public:
	position2d _position;
	dimension2d _dimension;
	int _drawLayer;

	
	std::string texturePath;

	SDL_Texture* gTexture;
	ObjectRect _objectRect;
};