#pragma once

#include "MyObjectDisplayData.h"


#include <vector>

namespace GraphicEngineModuleInfo
{
	static const char* DllName = "2D_Engine.dll";
	static const char* GetInstanceFunction = "getInstanceGraphic";
}

class GraphicEngineInterface
{

public:
	virtual void init() = 0;
	virtual void tick() = 0;

	virtual void initObject(MyObjectDisplayData* object) = 0;
	virtual void initObjects(std::vector<MyObjectDisplayData*>* objects) = 0;
	virtual void loadTexture(MyObjectDisplayData* object) = 0;
	virtual void loadTextures(std::vector<MyObjectDisplayData*>* objects) = 0;
	virtual void addObjectToRender(MyObjectDisplayData* object) = 0;
	virtual void addObjectsToRender(std::vector<MyObjectDisplayData*>* objects) = 0;
	virtual void destroy() = 0;
};

