#pragma once

struct TileData
{
	int tileID; // id for tile referenced in texture mananger
	int LightLevel = 0; // 0-8
	bool LightEmitter = false; 
};

namespace TileGrid
{
	int WorldWidth;
	int WorldHeight;

	int CenterX;
	int CenterY;

	std::vector<std::vector<TileData>> TileGrid;

	void SetWorldSize()
	{
		TileGrid.resize(WorldWidth);

		for (int i = 0; i < WorldWidth; i++) { TileGrid[i].resize(WorldHeight); }

		CenterX = WorldWidth / 2;
		CenterY = WorldHeight / 2;

		Camera::CameraX = TileGrid::CenterX * 16;
		Camera::CameraY = TileGrid::CenterY * 16;
	}

	std::pair<int, int> PixelToTile(int x, int y)
	{
		int CentreX = WindowWidth / 2; // centre of tilegrid in pixels
		int CentreY = WindowHeight / 2; // centre of tilegrid in pixels

		int worldX = Camera::CameraX + (x - CentreX);
		int worldY = Camera::CameraY + (y - CentreY);

		int tileX = worldX / 16;
		int tileY = worldY / 16;

		return { tileX, tileY };
	}

}