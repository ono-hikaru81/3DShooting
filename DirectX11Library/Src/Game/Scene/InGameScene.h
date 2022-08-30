
#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include <memory>
#include <random>

#include "SceneBase.h"

#include "../Object/Enemy.h"
#include "../Object/EnemyFactory.h"
#include "../Object/BulletFactory.h"
#include "../Object/Player.h"

namespace scene
{
    class InGameScene : public SceneBase
    {
    public:
        InGameScene();

        ~InGameScene();

    public:
        void Exec();

        void Draw();

    private:
        std::unique_ptr<Object::EnemyFactory> enemyFactory;
        std::unique_ptr<Object::BulletFactory> bulletFactory;
        std::unique_ptr<Object::Player> player;

        float createTimer { 0.0f };

        std::random_device randomDevice {};
        int randomNum { 0 };
        Utility::Vector createPosOfEnemy { 0.0f,0.0f,0.0f };
    };
}  // namespace scene

#endif  // !IN_GAME_SCENE_H
