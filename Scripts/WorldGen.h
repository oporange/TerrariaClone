#pragma once


void GenerateTerrain()
{
	const siv::PerlinNoise::seed_type seed = 123456u;

	const siv::PerlinNoise perlin{ seed };

	// set tile loop
	for (int x = 0; x < TileGrid::WorldWidth; x++) {
		for (int y = 0; y < TileGrid::WorldHeight; y++)
		{

			int GroundHeight = TileGrid::CenterY + round(perlin.octave2D_01((x * 0.02), 10, 2) * 20);
			int StoneHeight = GroundHeight + round(perlin.octave2D_01((x * 0.1), 20, 2) * 10) + 10;

			float Tree = perlin.octave2D_01((x*100), 30+(x*10), 2);
			int TreeHeight = round(perlin.octave2D_01((x*50), 40, 2) * 10)+3;

			float CavesGen = perlin.octave2D_01((x * 0.03), (y * 0.03), 2);

			TileGrid::TileGrid[x][y].tileID = 1;

			if (y >= GroundHeight - TreeHeight && y < GroundHeight && Tree > 0.62f)
			{
				TileGrid::TileGrid[x][y].tileID = 4;
			}
			else if (y == GroundHeight)
			{
				TileGrid::TileGrid[x][y].tileID = 2;
			}
			else if (y > GroundHeight && y < StoneHeight)
			{
				TileGrid::TileGrid[x][y].tileID = 1;
			}
			else if (y >= StoneHeight && CavesGen > 0.3f)
			{
				TileGrid::TileGrid[x][y].tileID = 3;
			}

			else { //  set tile to air
				TileGrid::TileGrid[x][y].tileID = 0;
				TileGrid::TileGrid[x][y].LightEmitter = true;
			}

		}
	}

	// update tile lighting loop
	for (int x = 0; x < TileGrid::WorldWidth; x++) {
		for (int y = 0; y < TileGrid::WorldHeight; y++)
		{
			TileData tile = TileGrid::TileGrid[x][y];

			// new lighting for all directions

			if (tile.LightEmitter)
			{
				for (int RelX = -8; RelX <= 8; RelX++) {
					for (int RelY = -8; RelY <= 8; RelY++)
					{
						if (x + RelX < 0 || y + RelY < 0) { continue; }
						if (x + RelX > TileGrid::WorldWidth-1 || y + RelY > TileGrid::WorldHeight-1) { continue; }


						TileData reference = TileGrid::TileGrid[x + RelX][y + RelY];

						if (reference.LightEmitter) { continue; }

						float LightLevel = 0;

						float Xdist = abs(RelX);
						float Ydist = abs(RelY);

						float Distance = sqrt((Xdist*Xdist) + (Ydist * Ydist));
						LightLevel = 8 - ((Distance / 11.3137085) * 8);

						if (reference.LightLevel < LightLevel) { reference.LightLevel = LightLevel; }

						TileGrid::TileGrid[x + RelX][y + RelY] = reference;
					}
				}
			}


			TileGrid::TileGrid[x][y] = tile;
		}
	}



}