#pragma once


void GenerateTerrain()
{
	const siv::PerlinNoise::seed_type seed = 123456u;

	const siv::PerlinNoise perlin{ seed };

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

			else {
				TileGrid::TileGrid[x][y].tileID = 0;
			}

		}
	}

	for (int x = 0; x < TileGrid::WorldWidth; x++) {
		for (int y = 0; y < TileGrid::WorldHeight; y++)
		{
			TileData tile = TileGrid::TileGrid[x][y];

			if (tile.tileID == 0)
			{
				tile.LightLevel = 7;
			}
			else 
			{

				for (int i = 1; i <= 7; i++)
				{
					if (TileGrid::TileGrid[x][y - i].tileID == 0 || TileGrid::TileGrid[x][y - i].tileID == 4) {
						tile.LightLevel = 7 - i;
						break;
					}
				}
			}


			TileGrid::TileGrid[x][y] = tile;
		}
	}



}