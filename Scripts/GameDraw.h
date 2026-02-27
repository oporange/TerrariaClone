#pragma once


void DrawGame()
{

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

			SDL_Rect r = { screenX, screenY, 16, 16 };

			SDL_Texture* texture = Textures::Tiles.at(Textures::TileLookUp[TileGrid::TileGrid[TileX][TileY]]);

			SDL_RenderCopy(Renderer, texture, nullptr, &r);

		}
	}


}