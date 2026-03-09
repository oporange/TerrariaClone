#pragma once

namespace TileInteractions {

	void BreakTile(int x, int y)
	{
		if (x < 0 || y < 0 || x >= TileGrid::WorldWidth || y >= TileGrid::WorldHeight)
			return;

		TileData tile = TileData();
		tile.LightEmitter = true;

		TileGrid::TileGrid[x][y] = tile;

		std::cout << "tile at: " << x << "   " << y << std::endl;
		UpdateLightingForTile(x, y);

	}
}