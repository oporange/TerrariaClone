#pragma once

class Player : public PhysicsEntity
{
public:

	void Init()
	{
		this->rigidbody = RigidBody{ 16, 32 };

		this->PosX = TileGrid::CenterX * 16;
		this->PosY = TileGrid::CenterY * 16;
		Camera::CameraX = this->PosX;
		Camera::CameraY = this->PosY;
	}

	void Draw()
	{
		SDL_Rect r = { 
			Camera::CameraX - PosX + WindowWidth / 2,
			Camera::CameraY - PosY + WindowHeight / 2,
			16, 
			32 };

		SDL_RenderCopy(Renderer, Sprite, nullptr, &r);
	}

	void Update()
	{
		this->Simulate();

		if (Input::Keys[SDLK_w].IsPressed) { this->PosY -= 1; }
		if (Input::Keys[SDLK_a].IsPressed) { this->PosX -= 1; }
		if (Input::Keys[SDLK_s].IsPressed) { this->PosY += 1; }
		if (Input::Keys[SDLK_d].IsPressed) { this->PosX += 1; }

		Camera::CameraX = this->PosX;
		Camera::CameraY = this->PosY;

	}
};
