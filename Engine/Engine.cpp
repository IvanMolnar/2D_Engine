// Engine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>

#include <iostream>

#include "Render.h"









int main(int argc, char* args[])
{
	Render r;
	r.init();
	r.tick();

	return 0;
}