#include "iostream"
#include "string"

#include "SDL.h"

#include "Scripts/Includes.h"

#undef main

static bool GameRunning = true;

int main() 
{

	Game_Window::WindowInit();

	while (GameRunning)
	{

		Input::PollInput();


	}

}