#pragma once

namespace Textures {

	std::unordered_map<std::string, SDL_Texture*> Tiles;

	SDL_Texture* TextureLoad(const char* file)
	{

		SDL_Surface* surf = SDL_LoadBMP(file);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, surf);

		SDL_FreeSurface(surf);

		std::cout << "loaded: " << file << std::endl;
		std::cout << SDL_GetError() << std::endl;

		return texture;
	}


	void LoadTiles()
	{

		Tiles.insert({"Dirt", TextureLoad("Textures\\Tiles\\Dirt.bmp")});

	}






	std::string TileLookUp[] = {"air", "Dirt"};
}