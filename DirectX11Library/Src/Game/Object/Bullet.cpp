#include "Bullet.h"

namespace Object
{
	Bullet::Bullet(Utility::Vector pos_)
	{
		pos = pos_;
		
		Initialize();
	}

	Bullet::~Bullet()
	{
		Release();
	}

	void Bullet::Initialize()
	{
		modelHandle.get()->LoadObjFile("Res/Model/hikouki.obj");
	}

	void Bullet::Release()
	{
		modelHandle.release();
	}

	void Bullet::Update(Utility::Vector createPos_, Utility::Vector fireDegree_)
	{
		Move(createPos_, fireDegree_);
		ChangeOfDirection(fireDegree_);
	}

	void Bullet::Draw()
	{
		modelHandle.get()->RenderObjFile(pos, scale, degree);
	}

	void Bullet::CheckCollision(Utility::Vector pos_)
	{
		distance = sqrtf(powf(pos.x - pos_.GetX(), 2.0f) + powf(pos.z - pos_.GetZ(), 2.0f));

		if (distance < 1.0f)
		{
			isAlive = false;
		}
	}

	void Bullet::Move(Utility::Vector createPos_, Utility::Vector fireDegree_)
	{
		pos.x += sinf(DirectX::XMConvertToRadians(fireDegree_.y)) * 1.0f;
		pos.z += cosf(DirectX::XMConvertToRadians(fireDegree_.y)) * 1.0f;
	}

	void Bullet::ChangeOfDirection(Utility::Vector fireDegree_)
	{
		degree = fireDegree_;
	}
}
