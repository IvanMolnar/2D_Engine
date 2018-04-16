// 2D_Engine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "Render.h"
#include "2D_Engine.h"


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

extern "C" __declspec(dllexport) GraphicEngineInterface* __cdecl getInstance()
{
	return GraphicEngine::getInstance();
}