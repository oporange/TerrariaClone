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

	Textures::LoadAll();

	Input::Init();

	DrawInit();

	TileGrid::WorldHeight = 1000;
	TileGrid::WorldWidth = 2000;
	TileGrid::SetWorldSize();

	Player p;
	p.Init();
	p.Sprite = Textures::Sprites.at("Player");

	GenerateTerrain();
	while (GameRunning)
	{
		//std::cout << "Drawing" << std::endl;

		SDL_RenderClear(Renderer);

		Input::PollInput();


		DrawGame();

		p.Update();
		p.Draw();


		SDL_RenderPresent(Renderer);

	}

}