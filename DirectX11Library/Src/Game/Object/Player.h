
#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "../../Library/Library.h"
#include "../../Utility/Vector.h"

namespace Object
{
	class Player
	{
	public:
		Player();
		~Player();

	public:
		Utility::Vector GetPos() const { return pos; }
		Utility::Vector GetDegree() const { return degree; }

	private:
		void Initialize();

		void Release();

	public:
		void Update(bool isTurnRight_, bool isTurnLeft_);

		void Draw();

	private:
		void ChangeOfDirection(bool isTurnRight_, bool isTurnLeft_);

	private:
		Utility::Vector pos { 0.0f, 0.0f, 0.0f };				//! 座標
		Utility::Vector scale { 0.5f, 0.5f, 0.5f };				//! 大きさ
		Utility::Vector degree { 0.0f, 0.0f, 0.0f };			//! 角度
		std::unique_ptr<Engine::Library> modelHandle {};		//! モデルハンドル
	};
}

#endif // !PLAYER_H
