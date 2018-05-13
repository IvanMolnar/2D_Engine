#include "stdafx.h"
#include "Render.h"




#pragma comment(lib, "SDL2.lib")
//#pragma comment(lib, "SDL2main.lib")
//#pragma comment(lib, "SDL2test.lib")
#pragma comment(lib, "SDL2_image.lib")

Render::Render()
{
}


Render::~Render()
{
	close();
}


bool Render::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		m_Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_Window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (m_Renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

void Render::addObjectToRender(MyObjectDisplayData* object)
{
	_renderObjects[object->_drawLayer].push_back(object);
}

void Render::initObject(MyObjectDisplayData* object)
{
	object->gTexture = nullptr;
}

void Render::loadTexture(MyObjectDisplayData* object)
{
	//Load PNG texture
	object->gTexture = loadTexture("..\\DesignPatternDemo\\textures\\" + object->texturePath);

	if (object->gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
	}
}

SDL_Event* Render::getInput()
{
	SDL_Event event;

	SDL_WaitEventTimeout(&event, 10);
	
	return &event;
}

void Render::close()
{
	//Free loaded images

	for (auto& objectList : _renderObjects)
	{
		for (auto& object : objectList.second)
		{
			SDL_DestroyTexture(object->gTexture);
			object->gTexture = nullptr;
		}
	}

	//Destroy window	
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	m_Window = NULL;
	m_Renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Render::drawObjects(DrawingLayer layer)
{
	if (layer == DrawingLayer::UI)
	{
		for (MyObjectDisplayData* object : _renderObjects[layer])
		{
			int renderXPos = object->_position.x;
			int renderYPos = object->_position.y;

			SDL_Rect rect = { renderXPos, renderYPos, object->_dimension.w, object->_dimension.w };

			SDL_RenderCopy(m_Renderer, object->gTexture, NULL, &rect);
		}
	}
	else
	{
		for (MyObjectDisplayData* object : _renderObjects[layer])
		{
			int renderXPos = object->_position.x * cellSize;
			int renderYPos = object->_position.y * cellSize;

			SDL_Rect rect = { renderXPos, renderYPos, object->_dimension.w, object->_dimension.w };

			SDL_RenderCopy(m_Renderer, object->gTexture, NULL, &rect);
		}
	}
	
}

void Render::tick()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	// SDL_Event e;

	//While application is running
//	while (!quit)
//	{/*
		//Handle events on queue
	/*
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}*/

		//Clear screen
		SDL_RenderClear(m_Renderer);

		drawObjects(DrawingLayer::Background);
		drawObjects(DrawingLayer::Floor);
		drawObjects(DrawingLayer::Game);
		drawObjects(DrawingLayer::Foreground);
		drawObjects(DrawingLayer::UI);

		//Update screen
		SDL_RenderPresent(m_Renderer);
//	}

	//close();
}

SDL_Texture* Render::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(m_Renderer, loadedSurface);
		
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}