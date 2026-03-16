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

const float Gravity = 0.01f;

struct RigidBody {
	int w; int h;
};


class PhysicsEntity : public Entity
{
public:
	RigidBody rigidbody;

	float X_Velocity;
	float Y_Velocity;

	void Simulate()
	{

		Y_Velocity += Gravity;

		PosY += Y_Velocity;

	}

};