
#include "Enemy.h"

namespace Object
{
	Enemy::Enemy(Utility::Vector pos_)
	{
		pos = pos_;

		Initialize();
	}

	Enemy::~Enemy()
	{
		Release();
	}

	void Object::Enemy::Initialize()
	{
		modelHandle.get()->LoadObjFile("Res/Model/hikouki.obj");
	}

	void Enemy::Release()
	{
		modelHandle.release();
	}

	void Object::Enemy::Update(Utility::Vector targetPos_)
	{
		distance = sqrtf(powf(pos.x - targetPos_.GetX(), 2.0f) + powf(pos.z - targetPos_.GetZ(), 2.0f));

		if (distance > 1.0f)
		{
			Move(targetPos_);
		}
	}

	void Object::Enemy::Draw()
	{
		modelHandle.get()->RenderObjFile(pos, scale, degree);
	}

	void Object::Enemy::Move(Utility::Vector targetPos_)
	{
		ChangeOfDirection(targetPos_);

		pos.x +=(cosf(degree.y)) * 0.05f;
		pos.z +=(sinf(degree.y)) * 0.05f;
	}

	void Object::Enemy::ChangeOfDirection(Utility::Vector targetPos_)
	{
		degree.y = atan2f((targetPos_.GetZ() - pos.z), targetPos_.GetX() -  pos.x);
	}

	void Enemy::CheckDistance(Utility::Vector targetPos_)
	{
		distance = sqrtf(powf(pos.x - targetPos_.GetX(), 2.0f) + powf(pos.z - targetPos_.GetZ(), 2.0f));
	}
}
