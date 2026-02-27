#pragma once


void GenerateTerrain()
{


	for (int x = 0; x < TileGrid::WorldWidth; x++) {
		for (int y = 0; y < TileGrid::WorldHeight; y++)
		{

			TileGrid::TileGrid[x][y] = 1;

		}
	}


}