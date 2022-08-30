
#include <fstream>

#include "../Manager/SceneManager.h"
#include "InGameScene.h"

namespace scene
{
    InGameScene::InGameScene()
    {
        enemyFactory = std::make_unique<Object::EnemyFactory>();
        player = std::make_unique<Object::Player>();
        bulletFactory = std::make_unique<Object::BulletFactory>();
    }

    InGameScene::~InGameScene()
    {
        enemyFactory.reset();
        player.reset();
        bulletFactory.reset();
    }

    void InGameScene::Exec()
    {
        if (Engine::Library::IsKeyPushed(DIK_RETURN))
        {
            SceneManager::Instance().lock()->SetNextScene(SceneBase::SceneKind::ResultScene);
        }

        // 敵生成タイマー
        createTimer++;

        // 一定時間ごとに敵生成 a
        if (createTimer > 60.0f)
        {
            enemyFactory.get()->SetIsCreateEnemy(true);
            createTimer = 0.0f;
        }


        std::default_random_engine randomEngine(randomDevice());

        std::uniform_int_distribution<> distribution(0, 3);

        std::ofstream resultFile("uniform_int_distribution.tsv");

        randomNum = distribution(randomEngine);

        // 敵生成
        switch (randomNum)
        {
        case 0: createPosOfEnemy = {  0.0f, 0.0f,  50.0f}; break;
        case 1: createPosOfEnemy = { 50.0f, 0.0f,   0.0f}; break;
        case 2: createPosOfEnemy = {  0.0f, 0.0f, -50.0f}; break;
        case 3: createPosOfEnemy = {-50.0f, 0.0f,   0.0f}; break;
        }
        enemyFactory.get()->CreateEnemy(createPosOfEnemy);

        // 弾発射
        if (Engine::Library::IsKeyPushed(DIK_SPACE))
        {
            bulletFactory.get()->SetIsCreateBullet(true);
        }

        // プレイヤーの位置から弾生成
        bulletFactory.get()->CreateBullet(player->GetPos());

        // プレイヤーを注視点にカメラ更新
        Engine::Library::UpdateCamera(player->GetPos(), player->GetDegree());

        // 敵更新
        enemyFactory.get()->UpdateEnemy(player->GetPos());

        // 弾更新
        bulletFactory.get()->UpdateBullet(player->GetPos(), player->GetDegree());

        // プレイヤー更新
        player.get()->Update(Engine::Library::IsKeyHeld(DIK_A), Engine::Library::IsKeyHeld(DIK_D));
    }

    void InGameScene::Draw()
    {
        //// ポリゴン描画
        //Engine::Library::RenderTriangle(0.0f, 0.0f, 100.0f, 100.0f);
        //Engine::Library::RenderRect(0.0f, 50.0f, 100.0f, 100.0f, 0.0f);

        // テクスチャ描画
        //Engine::Library::DrawTexture(L"Res/Texture/miniball.png", 0.0f, 0.0f, 32.0f, 32.0f);

        // 敵描画
        enemyFactory.get()->DrawEnemy();

        // 弾描画
        bulletFactory.get()->DrawBullet();

        // プレイヤー描画
        player.get()->Draw();
    }
}  // namespace scene
