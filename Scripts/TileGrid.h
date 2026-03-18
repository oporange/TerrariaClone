#pragma once

struct TileData
{
	int tileID; // id for tile referenced in texture mananger
	int LightLevel = 0; // 0-8
	bool LightEmitter = false; 
};

namespace TileGrid
{
	int WorldWidth;	int WorldHeight;

	int CenterX;	int CenterY;

	std::vector<std::vector<TileData>> TileGrid;

	void SetWorldSize()
	{
		TileGrid.resize(WorldWidth);

		for (int i = 0; i < WorldWidth; i++) { TileGrid[i].resize(WorldHeight); }

		CenterX = WorldWidth / 2;
		CenterY = WorldHeight / 2;
	}

	std::pair<int, int> PixelToTile(int x, int y)
	{

		int tileX = floor(x / 16);
		int tileY = floor(y / 16);

		return { tileX, tileY };
	}

	std::pair<int, int> ScreenToTile(int x, int y)
	{
		float worldX = Camera::CameraX + (x - WindowWidth / 2);
		float worldY = Camera::CameraY + (y - WindowHeight / 2);

		return PixelToTile(worldX, worldY);
	}

}