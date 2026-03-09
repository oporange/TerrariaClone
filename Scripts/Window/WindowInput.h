#pragma once

extern bool GameRunning;

std::unordered_map<int, bool> KeysPressed;
bool MouseButtons[3];

namespace Input {

	SDL_Event event;

	void Init() {
		KeysPressed.insert({ SDLK_w, false });
		KeysPressed.insert({ SDLK_a, false });
		KeysPressed.insert({ SDLK_s, false });
		KeysPressed.insert({ SDLK_d, false });
	}

	void PollInput() 
	{

		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT) { GameRunning = false; }

			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_w) { KeysPressed.at(SDLK_w) = true; }
				if (event.key.keysym.sym == SDLK_a) { KeysPressed.at(SDLK_a) = true; }
				if (event.key.keysym.sym == SDLK_s) { KeysPressed.at(SDLK_s) = true; }
				if (event.key.keysym.sym == SDLK_d) { KeysPressed.at(SDLK_d) = true; }
			}

			else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_w) { KeysPressed.at(SDLK_w) = false; }
				if (event.key.keysym.sym == SDLK_a) { KeysPressed.at(SDLK_a) = false; }
				if (event.key.keysym.sym == SDLK_s) { KeysPressed.at(SDLK_s) = false; }
				if (event.key.keysym.sym == SDLK_d) { KeysPressed.at(SDLK_d) = false; }

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

		if (KeysPressed.at(SDLK_w)) { Camera::CameraY -= 1; }
		if (KeysPressed.at(SDLK_a)) { Camera::CameraX -= 1; }
		if (KeysPressed.at(SDLK_s)) { Camera::CameraY += 1; }
		if (KeysPressed.at(SDLK_d)) { Camera::CameraX += 1; }

		if (MouseButtons[0]) 
		{
			int x; int y;
			SDL_GetMouseState(&x, &y);


			std::pair<int, int> pos = TileGrid::PixelToTile(x, y);
			TileInteractions::BreakTile(pos.first, pos.second);
		}

	}

}