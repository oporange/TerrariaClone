#pragma once

namespace TileGrid
{
	int WorldWidth;
	int WorldHeight;

	int CenterX;
	int CenterY;

	std::vector<std::vector<int>> TileGrid;

	void SetWorldSize()
	{
		TileGrid.resize(WorldWidth);

		for (int i = 0; i < WorldWidth; i++) { TileGrid[i].resize(WorldHeight); }

		CenterX = WorldWidth / 2;
		CenterY = WorldHeight / 2;

		Camera::CameraX = TileGrid::CenterX * 16;
		Camera::CameraY = TileGrid::CenterY * 16;
	}

}