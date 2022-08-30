
#ifndef ENEMY_H
#define ENEMY_H

#include "../../Library/Library.h"
#include "../../Utility/Vector.h"

namespace Object
{
	class Enemy
	{
	public:
		Enemy(Utility::Vector pos_);
		~Enemy();

	public:
		Utility::Vector GetPos() { return pos; }

	private:
		void Initialize();

		void Release();

	public:
		void Update(Utility::Vector targetPos_);

		void Draw();

	private:
		void Move(Utility::Vector targetPos_);

		void ChangeOfDirection(Utility::Vector targetPos_);

		void CheckDistance(Utility::Vector targetPos_);

	private:
		Utility::Vector pos { 0.0f, 0.0f, 30.0f };				//! 座標
		Utility::Vector scale { 0.5f, 0.5f, 0.5f };				//! 大きさ
		Utility::Vector degree { 0.0f, 0.0f, 0.0f };			//! 角度
		float distance { 0.0f };								//! 対象との距離
		std::unique_ptr<Engine::Library> modelHandle;			//! モデルハンドル
	};
};

#endif // !ENEMY_H
