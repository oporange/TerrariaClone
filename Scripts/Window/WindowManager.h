#pragma once

SDL_Window* Window;
SDL_Renderer* Renderer;

int WindowWidth = 1200;
int WindowHeight = 800;

namespace Game_Window {


	void WindowInit()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
	
		Window = SDL_CreateWindow("Terraria Clone", 50,50, WindowWidth, WindowHeight, 0);
		Renderer = SDL_CreateRenderer(Window, -1, 0);
	}



}