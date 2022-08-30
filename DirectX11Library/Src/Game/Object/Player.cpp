
#include "Player.h"

#include <DirectXMath.h>

#include "../../Library/Library.h"

namespace Object
{
	Player::Player()
	{
		Initialize();
	}

	Player::~Player()
	{
		Release();
	}

	void Player::Initialize()
	{
		modelHandle.get()->LoadObjFile("Res/Model/hikouki.obj");
	}

	void Player::Release()
	{
		modelHandle.release();
	}

	void Player::Update(bool isTurnRight_, bool isTurnLeft_)
	{
		ChangeOfDirection(isTurnRight_, isTurnLeft_);
	}

	void Player::Draw()
	{
		modelHandle.get()->RenderObjFile(pos, scale, degree);
	}

	void Player::ChangeOfDirection(bool isTurnRight_, bool isTurnLeft_)
	{
		if (isTurnRight_)
		{
			degree.y -= 1.0f;
		}
		else if (isTurnLeft_)
		{
			degree.y += 1.0f;
		}
	}
}
