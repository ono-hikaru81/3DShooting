
#ifndef ENEMY_FACTORY
#define ENEMY_FACTORY

#include <memory>

#include "../Object/Enemy.h"
#include "../../Utility/Singleton.h"
#include "../../Utility/Vector.h"

namespace Object
{
	class EnemyFactory : public Utility::Singleton<EnemyFactory>
	{
	public:
		EnemyFactory() = default;
		~EnemyFactory() = default;

	public:
		void SetIsCreateEnemy(bool isCreateEnemy_) { isCreateEnemy = isCreateEnemy_; }

	public:
		void CreateEnemy(Utility::Vector pos_);

		void ReleaseEnemy();

		void UpdateEnemy(Utility::Vector targetPos_);

		void DrawEnemy();

	private:
		bool isCreateEnemy { false };
		std::vector<std::shared_ptr<Enemy>> enemyList {};
	};
}

#endif // !ENEMY_FACTORY

