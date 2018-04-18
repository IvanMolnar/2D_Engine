#pragma once
#include "src\Libraries\SDL\include\SDL_scancode.h"

namespace InputModuleInfo
{
	static const char* DllName = "2D_Engine.dll";
	static const char* GetInstanceFunction = "getInstanceInput";
}

class InputInterface
{
public:
	virtual SDL_Scancode getInput() = 0;
	virtual void destroy() = 0;
};