#pragma once

extern bool GameRunning;

namespace Input {

	SDL_Event event;

	void PollInput() 
	{

		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT) { GameRunning = false; }

		}

	}

}