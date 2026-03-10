#pragma once

class Player : PhysicsEntity
{
public:

	void Init()
	{

	}

	void Update()
	{

		if (Input::Keys[SDLK_w].IsPressed) { Camera::CameraY -= 1; }
		if (Input::Keys[SDLK_a].IsPressed) { Camera::CameraX -= 1; }
		if (Input::Keys[SDLK_s].IsPressed) { Camera::CameraY += 1; }
		if (Input::Keys[SDLK_d].IsPressed) { Camera::CameraX += 1; }

	}
};
