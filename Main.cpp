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

	TileGrid::WorldHeight = 10;
	TileGrid::WorldWidth = 10;
	TileGrid::SetWorldSize();

	GenerateTerrain();
	DrawGame();

	while (GameRunning)
	{

		Input::PollInput();


		SDL_RenderPresent(Renderer);

	}

}