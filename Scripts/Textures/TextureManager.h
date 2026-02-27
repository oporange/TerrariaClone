#pragma once

namespace Textures {

	std::unordered_map<std::string, SDL_Texture*> Tiles;

	SDL_Texture* TextureLoad(const char* file)
	{

		SDL_Surface* surf = SDL_LoadBMP(file);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, surf);

		SDL_FreeSurface(surf);

		return texture;
	}


	void LoadTiles()
	{
		Tiles.insert({ "air", SDL_CreateTexture(Renderer, 0, 0, 16, 16) });

		Tiles.insert({"Dirt", TextureLoad("Textures\\Tiles\\Dirt.bmp")});
		Tiles.insert({"Grass", TextureLoad("Textures\\Tiles\\Grass.bmp") });
		Tiles.insert({"Stone", TextureLoad("Textures\\Tiles\\Stone.bmp") });
		Tiles.insert({"TreeLog", TextureLoad("Textures\\Tiles\\TreeLog.bmp") });

	}




	std::string TileLookUp[] = {"air", "Dirt", "Grass", "Stone", "TreeLog"};
}