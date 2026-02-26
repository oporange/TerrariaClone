#pragma once

namespace Textures {


	SDL_Texture* TextureLoad(char* file)
	{

		SDL_Surface* surf = SDL_LoadBMP(file);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, surf);

		SDL_FreeSurface(surf);

		return texture;
	}

}