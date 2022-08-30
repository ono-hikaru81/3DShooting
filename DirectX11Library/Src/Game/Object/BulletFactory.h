
#ifndef BULLET_FACTORY_H
#define BULLET_FACTORY_H

#include <memory>

#include "../Object/Bullet.h"
#include "../../Utility/Singleton.h"
#include "../../Utility/Vector.h"

namespace Object
{
	class BulletFactory : public Utility::Singleton<BulletFactory>
	{
	public:
		BulletFactory() = default;
		~BulletFactory() = default;

	public:
		void SetIsCreateBullet(bool isCreateBullet_) { isCreateBullet = isCreateBullet_; }

	public:
		void CreateBullet(Utility::Vector pos_);

		void ReleaseBullet();

		void UpdateBullet(Utility::Vector createPos_, Utility::Vector fireDegree_);

		void DrawBullet();

	private:
		bool isCreateBullet { false };
		std::vector<std::shared_ptr<Bullet>> bulletList{};
	};
}

#endif // !BULLET_FACTORY_H
