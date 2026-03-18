#pragma once

float moveSpeed = 0.1f;

class Player : public PhysicsEntity
{
public:

	void Init()
	{
		rigidbody = RigidBody{ 16, 32 };

		PosX = TileGrid::CenterX * 16;
		PosY = TileGrid::CenterY * 16;
		Camera::CameraX = PosX;
		Camera::CameraY = PosY;
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
		Simulate();

		if (Input::Keys[SDLK_w].IsPressed && Y_Velocity == 0) { Y_Velocity -= 0.4f; }
		if (Input::Keys[SDLK_a].IsPressed) { Move(-moveSpeed, 0); }
		if (Input::Keys[SDLK_d].IsPressed) { Move(moveSpeed, 0);; }

		Camera::CameraX = PosX;
		Camera::CameraY = PosY;

	}
};
