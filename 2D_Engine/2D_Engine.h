#pragma once

namespace GraphicEngineModuleInfo
{
	static const char* DllName = "2D_Engine.dll";
	static const char* GetInstanceFunction = "getInstance";
}

class GraphicEngineInterface
{

public:
	virtual void init() = 0;
	virtual void tick() = 0;
	virtual void destroy() = 0;
};