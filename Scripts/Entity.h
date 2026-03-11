#pragma once


class Entity
{
public:
	float PosX = 0; float PosY = 0;

	SDL_Texture* Sprite;


	void Draw()
	{
		SDL_Rect r = { PosX, PosY, 16, 32 };
		SDL_RenderCopy(Renderer, Sprite, nullptr, &r);
	}
};

class PhysicsEntity : public Entity
{



};