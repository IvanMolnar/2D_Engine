#pragma once

#include "MyObjectDisplayData.h"

#include <vector>

namespace GraphicEngineModuleInfo
{
	static const char* DllName = "2D_Engine.dll";
	static const char* GetInstanceFunction = "getInstance";
}

class GraphicEngineInterface
{

public:
	virtual void init() = 0;
	virtual void tick(std::vector<MyObjectDisplayData*>* renderData = nullptr) = 0;
	virtual void loadTexture(MyObjectDisplayData* object) = 0;
	virtual void destroy() = 0;
};