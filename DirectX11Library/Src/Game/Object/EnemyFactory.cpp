
#include "EnemyFactory.h"

namespace Object
{
	void EnemyFactory::CreateEnemy(Utility::Vector pos_)
	{
		if (isCreateEnemy)
		{
			enemyList.push_back(std::make_shared<Enemy>(pos_));
			isCreateEnemy = false;
		}
	}

	void EnemyFactory::ReleaseEnemy()
	{
		enemyList.clear();
	}

	void EnemyFactory::UpdateEnemy(Utility::Vector targetPos_)
	{
		for (auto& enemy : enemyList)
		{
			enemy->Update(targetPos_);
		}
	}

	void EnemyFactory::DrawEnemy()
	{
		for (auto& enemy : enemyList)
		{
			enemy->Draw();
		}
	}
}
