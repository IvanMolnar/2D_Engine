// 2D_Engine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "Render.h"
#include "2D_Engine.h"
#include "InputInterface.h"


class GraphicEngine : public GraphicEngineInterface
{

public:
	
	void init()
	{
		_render = new Render();
		_render->init();
	}

	void destroy()
	{
		if (_render)
		{
			delete _render;
		}
		
		delete this;
	}

	void tick()
	{
		_render->tick();
	}

	void initObject(MyObjectDisplayData* object)
	{
		_render->initObject(object);
	}
	
	void initObjects(std::vector<MyObjectDisplayData*>* objects)
	{
		for (auto& object: *objects)
		{
			_render->initObject(object);
		}
	}

	void loadTexture(MyObjectDisplayData* object)
	{
		_render->loadTexture(object);
	}

	void loadTextures(std::vector<MyObjectDisplayData*>* objects)
	{
		for (auto& object : *objects)
		{
			_render->loadTexture(object);
		}
	}

	void addObjectToRender(MyObjectDisplayData* object)
	{
		_render->addObjectToRender(object);
	}

	void addObjectsToRender(std::vector<MyObjectDisplayData*>* objects)
	{
		for (auto& object : *objects)
		{
			_render->addObjectToRender(object);
		}
	}

	SDL_Event* getInput()
	{
		return _render->getInput();
	}

	static GraphicEngine* getInstance()
	{
		static GraphicEngine* instance;

		if (!instance)
		{
			instance = new GraphicEngine();
		}

		return instance;
	}

private:
	Render* _render;
};

class Input : public InputInterface
{
public:
	SDL_Event* getInput()
	{
		return GraphicEngine::getInstance()->getInput();
	}

	static Input* getInstance()
	{
		static Input* instance;

		if (!instance)
		{
			instance = new Input();
		}

		return instance;
	}

	void destroy()
	{
		delete this;
	}
};


extern "C" __declspec(dllexport) GraphicEngineInterface* __cdecl getInstanceGraphic()
{
	return GraphicEngine::getInstance();
}

extern "C" __declspec(dllexport) Input* __cdecl getInstanceInput()
{
	return Input::getInstance();
}