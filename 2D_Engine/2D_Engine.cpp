// 2D_Engine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "Render.h"
#include "2D_Engine.h"


class GraphicEngine : public GraphicEngineInterface {
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

private:
	Render* _render;
};

extern "C" __declspec(dllexport) GraphicEngineInterface* __cdecl createInstance()
{
	return new GraphicEngine();
}