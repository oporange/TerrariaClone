#include "iostream"
#include "string"
#include <unordered_map>

#include "SDL.h"

#include "Scripts/Includes.h"

#undef main

static bool GameRunning = true;

int main() 
{

	Game_Window::WindowInit();

	Textures::LoadTiles();

	Input::Init();

	TileGrid::WorldHeight = 200;
	TileGrid::WorldWidth = 500;
	TileGrid::SetWorldSize();

	GenerateTerrain();

	while (GameRunning)
	{
		SDL_RenderClear(Renderer);

		Input::PollInput();

		DrawGame();


		SDL_RenderPresent(Renderer);

	}

}