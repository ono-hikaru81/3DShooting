
#ifndef BULLET_h
#define BULLET_h

#include <memory>

#include "../../Library/Library.h"
#include "../../Utility/Vector.h"


namespace Object
{
	class Bullet
	{
	public:
		Bullet(Utility::Vector pos_);
		~Bullet();

	public:
		void SetPos(Utility::Vector pos_) { pos = pos_; }

		bool GetIsAlive() { return isAlive; }

	private:
		void Initialize();

		void Release();

	public:
		void Update(Utility::Vector createPos_, Utility::Vector fireDegree_);

		void Draw();

		void CheckCollision(Utility::Vector pos_);

	private:
		void Move(Utility::Vector createPos_, Utility::Vector fireDegree_);

		void ChangeOfDirection(Utility::Vector fireDegree_);

	private:
		Utility::Vector pos { 0.0f, 0.0f, 0.0f };			//! 座標
		Utility::Vector scale { 0.2f, 0.2f, 0.2f };			//! 大きさ
		Utility::Vector degree { 0.0f, 0.0f, 0.0f };		//! 角度
		float distance { 0.0f };							//! 対象との距離
		bool isAlive { true };
		std::unique_ptr<Engine::Library> modelHandle {};	//! モデルハンドル
	};
}

#endif // !BULLET_h
