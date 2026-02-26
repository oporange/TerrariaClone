#pragma once

namespace Textures {


	SDL_Texture* TextureLoad(const char* file)
	{

		SDL_Surface* surf = SDL_LoadBMP(file);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, surf);

		SDL_FreeSurface(surf);

		std::cout << "loaded: " << file << std::endl;

		return texture;
	}

	namespace Tiles {

		SDL_Texture* Dirt = TextureLoad("Textures/Tiles/Dirt.bmp");

	}

}