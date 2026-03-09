#pragma once


void GenerateLightDataForEmitter(int x, int y) {

	// new lighting for all directions
	for (int RelX = -8; RelX <= 8; RelX++) {
		for (int RelY = -8; RelY <= 8; RelY++)
		{
			if (x + RelX < 0 || y + RelY < 0) { continue; }
			if (x + RelX > TileGrid::WorldWidth - 1 || y + RelY > TileGrid::WorldHeight - 1) { continue; }


			TileData reference = TileGrid::TileGrid[x + RelX][y + RelY];

			if (reference.LightEmitter) { continue; }

			float LightLevel = 0;

			float Xdist = abs(RelX);
			float Ydist = abs(RelY);

			float Distance = sqrt((Xdist * Xdist) + (Ydist * Ydist));
			LightLevel = 8 - ((Distance / 11.3137085) * 8);

			if (reference.LightLevel < LightLevel) { reference.LightLevel = LightLevel; }

			TileGrid::TileGrid[x + RelX][y + RelY] = reference;
			}
		}


}

void FindNearLightSources(int x, int y)
{
	TileData tile = TileGrid::TileGrid[x][y];

	for (int RelX = -8; RelX <= 8; RelX++) {
		for (int RelY = -8; RelY <= 8; RelY++)
		{
			if (x + RelX < 0 || y + RelY < 0) { continue; }
			if (x + RelX > TileGrid::WorldWidth - 1 || y + RelY > TileGrid::WorldHeight - 1) { continue; }

			TileData reference = TileGrid::TileGrid[x + RelX][y + RelY];

			if (!reference.LightEmitter) { continue; }

			float LightLevel = 0;

			float Xdist = abs(RelX);
			float Ydist = abs(RelY);

			float Distance = sqrt((Xdist * Xdist) + (Ydist * Ydist));
			LightLevel = ((Distance / 11.3137085) * 8);

			if (tile.LightLevel < LightLevel) { tile.LightLevel = LightLevel; }

			TileGrid::TileGrid[x][y] = tile;
			std::cout << "Light level: " << tile.LightLevel << std::endl;

		}
	}
}


void UpdateLightingForTile(int x, int y)
{
	TileData tile = TileGrid::TileGrid[x][y];

	if (tile.LightEmitter) {
		GenerateLightDataForEmitter(x, y);
	}
	else {
		FindNearLightSources(x, y);
	}

}
