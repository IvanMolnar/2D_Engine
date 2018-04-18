#pragma once

#include "src\Libraries\SDL\include\SDL.h"
#undef main
#include "src\Libraries\SDL_Image\include\SDL_image.h"

#include <iostream>

#include <vector>
#include <map>
#include "MyObjectDisplayData.h"

class Render
{
public:
	Render();
	~Render();

	void tick();
	bool init();

	//test
	void initObject(MyObjectDisplayData* object);
	void addObjectToRender(MyObjectDisplayData* object);
	void loadTexture(MyObjectDisplayData* object);

private:
	
	
	void close();

	void drawObjects(DrawingLayer layer);
	
	SDL_Texture* loadTexture(std::string path);

	//The window we'll be rendering to
	SDL_Window* m_Window = NULL;

	//The window renderer
	SDL_Renderer* m_Renderer = NULL;



	int cellSize = 50;



	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;





	//Current displayed texture
	//SDL_Texture* gTexture = NULL;
	/*
	struct object
	{
		object()
		{
			gTexture = nullptr;
			destination = { 0, 0, 50, 50 };
		}

		SDL_Texture* gTexture;
		SDL_Rect destination;
	};*/

	//std::vector<object> _renderObject;

	//std::vector<MyObjectDisplayData*> _renderObject;
	std::map<DrawingLayer, std::vector<MyObjectDisplayData*>> _renderObjects;
};

