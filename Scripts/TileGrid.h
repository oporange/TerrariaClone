#pragma once

namespace TileGrid
{
	int WorldWidth;
	int WorldHeight;

	std::vector<std::vector<int>> TileGrid;

	void SetWorldSize()
	{
		TileGrid.resize(WorldWidth);

		for (int i = 0; i < WorldWidth; i++) { TileGrid[i].resize(WorldHeight); }
	}

}