#pragma once

SDL_Texture* SkyTexture;

void DrawInit()
{
	SkyTexture = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WindowWidth, WindowHeight);

	SDL_SetRenderTarget(Renderer, SkyTexture);

	SDL_SetRenderDrawColor(Renderer, 16, 206, 227, 255); // sky color
	SDL_Rect r = { 0,0, WindowWidth, WindowHeight };
	SDL_RenderFillRect(Renderer, &r);

	SDL_SetRenderTarget(Renderer, NULL);

}

void DrawGame()
{
	SDL_Rect sky = { 0,0,WindowWidth, WindowHeight };
	SDL_RenderCopy(Renderer, SkyTexture, nullptr, &sky);

	int DrawWidth = WindowWidth / 16 + 2;
	int DrawHeight = WindowHeight / 16 + 2;

	int startTileX = (Camera::CameraX / 16) - (DrawWidth / 2);
	int startTileY = (Camera::CameraY / 16) - (DrawHeight / 2);


	for (int x = -1; x < DrawWidth; x++) {
		for (int y = -1; y < DrawHeight; y++)
		{
			int TileX = startTileX + x;
			int TileY = startTileY + y;

			// Bounds check
			if (TileX < 0 || TileY < 0 ||
				TileX >= TileGrid::WorldWidth ||
				TileY >= TileGrid::WorldHeight)
				continue;


			int worldX = TileX * 16;
			int worldY = TileY * 16;

			int screenX = worldX - Camera::CameraX + (WindowWidth / 2);
			int screenY = worldY - Camera::CameraY + (WindowHeight / 2);

			SDL_Texture* texture = Textures::Tiles.at(Textures::TileLookUp[TileGrid::TileGrid[TileX][TileY].tileID]);
			SDL_Rect r = { screenX, screenY, 16, 16 };

			if (texture == nullptr) { continue; }

			//SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
			//SDL_RenderFillRect(Renderer, &r);

			if (TileGrid::TileGrid[TileX][TileY].LightLevel == 0) { continue; }

			SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
			SDL_SetTextureAlphaMod(texture, TileGrid::TileGrid[TileX][TileY].LightLevel * 32);

			SDL_RenderCopy(Renderer, texture, nullptr, &r);

		}
	}


}