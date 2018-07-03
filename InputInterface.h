#pragma once
#include "src\Libraries\SDL\include\SDL_events.h"

namespace InputModuleInfo
{
	static const char* DllName = "2D_Engine.dll";
	static const char* GetInstanceFunction = "getInstanceInput";
}

class InputInterface
{
public:
	virtual SDL_Event* getInput() = 0;
	virtual void destroy() = 0;
};