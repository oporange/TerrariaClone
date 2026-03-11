#pragma once

class Player : public PhysicsEntity
{
public:

	void Init()
	{
		this->PosX = TileGrid::CenterX * 16;
		this->PosY = TileGrid::CenterY * 16;
		Camera::CameraX = this->PosX;
		Camera::CameraY = this->PosY;
	}

	void Draw()
	{
		SDL_Rect r = { 
			Camera::CameraX - PosX, 
			Camera::CameraY - PosY, 
			16, 
			32 };

		SDL_RenderCopy(Renderer, Sprite, nullptr, &r);
	}

	void Update()
	{

		if (Input::Keys[SDLK_w].IsPressed) { this->PosY -= 1; }
		if (Input::Keys[SDLK_a].IsPressed) { this->PosX -= 1; }
		if (Input::Keys[SDLK_s].IsPressed) { this->PosY += 1; }
		if (Input::Keys[SDLK_d].IsPressed) { this->PosX += 1; }

		Camera::CameraX = this->PosX;
		Camera::CameraY = this->PosY;

	}
};
