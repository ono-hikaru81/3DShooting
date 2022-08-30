
#include "BulletFactory.h"

namespace Object
{
	void BulletFactory::CreateBullet(Utility::Vector pos_)
	{
		if (isCreateBullet)
		{
			bulletList.push_back(std::make_shared<Bullet>(pos_));
			isCreateBullet = false;
		}
	}

	void BulletFactory::ReleaseBullet()
	{
		for (auto& bullet : bulletList)
		{
			if (!bullet->GetIsAlive())
			{
				bullet.reset();
			}
		}
	}

	void BulletFactory::UpdateBullet(Utility::Vector createPos_, Utility::Vector fireDegree_)
	{
		for (auto& bullet : bulletList)
		{
			bullet->Update(createPos_, fireDegree_);
		}
	}

	void BulletFactory::DrawBullet()
	{
		for (auto& bullet : bulletList)
		{
			bullet->Draw();
		}
	}
}
