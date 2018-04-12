#pragma once

#include "src\Libraries\SDL\include\SDL.h"
#undef main
#include "src\Libraries\SDL_Image\include\SDL_image.h"

#include <iostream>

class Render
{
public:
	Render();
	~Render();

	void tick();
	bool init();

private:
	
	bool loadMedia();
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
	SDL_Texture* gTexture = NULL;
};
