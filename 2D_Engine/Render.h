#pragma once

#include "src\Libraries\SDL\include\SDL.h"
#undef main
#include "src\Libraries\SDL_Image\include\SDL_image.h"

#include <iostream>

#include <vector>
#include "MyObjectDisplayData.h"

class Render
{
public:
	Render();
	~Render();

	void tick();
	bool init();

	//test
	void setRenderTargets(std::vector<MyObjectDisplayData*>* renderData);
	void loadTexture(MyObjectDisplayData* object);

private:
	
	
	void close();
	
	SDL_Texture* loadTexture(std::string path);

	//The window we'll be rendering to
	SDL_Window* m_Window = NULL;

	//The window renderer
	SDL_Renderer* m_Renderer = NULL;







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

	std::vector<MyObjectDisplayData*>* _renderObject;
};

