#pragma once

extern bool GameRunning;

bool MouseButtons[3];


namespace Input {

	class KeyData
	{
	public:
		bool IsPressed;
		bool WasPressedThisFrame;

	};
	KeyData Keys[512] = { KeyData{} };



	SDL_Event event;

	void Init() {

	}

	void PollInput() 
	{

		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT) { GameRunning = false; }

			else if (event.type == SDL_KEYDOWN)
			{
				Keys[event.key.keysym.sym].IsPressed = true;
			}

			else if (event.type == SDL_KEYUP)
			{
				Keys[event.key.keysym.sym].IsPressed = false;
			}

			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				MouseButtons[0] = true;
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				MouseButtons[0] = false;
			}
		}

		// process inputs

		if (MouseButtons[0]) 
		{
			int x; int y;
			SDL_GetMouseState(&x, &y);


			std::pair<int, int> pos = TileGrid::ScreenToTile(x, y);
			TileInteractions::BreakTile(pos.first, pos.second);
		}

	}

}