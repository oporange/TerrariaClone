#include "iostream"
#include "string"
#include <unordered_map>

#include "SDL.h"

#include "Scripts/Includes.h"

#undef main

static bool GameRunning = true;

Player p;

int main() 
{

	Game_Window::WindowInit();

	Textures::LoadTiles();

	Input::Init();

	DrawInit();

	TileGrid::WorldHeight = 1000;
	TileGrid::WorldWidth = 2000;
	TileGrid::SetWorldSize();

	GenerateTerrain();
	while (GameRunning)
	{
		//std::cout << "Drawing" << std::endl;

		SDL_RenderClear(Renderer);

		Input::PollInput();

		p.Update();

		DrawGame();


		SDL_RenderPresent(Renderer);

	}

}