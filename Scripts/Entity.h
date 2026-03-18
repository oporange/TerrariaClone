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

const float Gravity = 0.001f;

struct RigidBody {
	int w; int h;
};
struct CollisionData_Tile
{
	int x; int y;
	int Tile;
};


class PhysicsEntity : public Entity
{
public:
	RigidBody rigidbody;

	float X_Velocity = 0;
	float Y_Velocity = 0;

	bool IsSolid(int x, int y)
	{
		if (x < 0 || y < 0 || x >= TileGrid::WorldWidth || y >= TileGrid::WorldHeight)
			return false;

		return TileGrid::TileGrid[x][y].tileID != 0;
	}

	bool CheckCollision()
	{
		float left = PosX;
		float right = PosX + rigidbody.w - 1;
		float top = PosY;
		float bottom = PosY + rigidbody.h - 1;

		auto TL = TileGrid::PixelToTile(left, top);
		auto TR = TileGrid::PixelToTile(right, top);
		auto BL = TileGrid::PixelToTile(left, bottom);
		auto BR = TileGrid::PixelToTile(right, bottom);

		return IsSolid(TL.first, TL.second) ||
			IsSolid(TR.first, TR.second) ||
			IsSolid(BL.first, BL.second) ||
			IsSolid(BR.first, BR.second);
	}

	void Move(float x, float y)
	{
		PosX += x;
		if (CheckCollision())
		{
			PosX -= x;
			X_Velocity = 0;
		}

		PosY += y;
		if (CheckCollision())
		{
			PosY -= y;
			Y_Velocity = 0;
		}
	
	}

	void Simulate()
	{

		Y_Velocity += Gravity;

		Move(0, Y_Velocity);

	}

};