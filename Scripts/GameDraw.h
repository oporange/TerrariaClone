#pragma once


void DrawGame()
{

	for (int x = 0; x < TileGrid::WorldWidth; x++) {
		for (int y = 0; y < TileGrid::WorldHeight; y++)
		{

			SDL_Rect r = { x * 16, y * 16, 16, 16 };

			std::cout << TileGrid::TileGrid[x][y] << std::endl;
			SDL_Texture* texture = Textures::Tiles.at(	Textures::TileLookUp[	TileGrid::TileGrid[x][y]	]);

			SDL_RenderCopy(Renderer, texture, nullptr, &r);

		}
	}


}