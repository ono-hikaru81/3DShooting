
#include "../Manager/SceneManager.h"
#include "ResultScene.h"

namespace scene
{
    void ResultScene::Exec()
    {
        if (Engine::Library::IsKeyPushed(DIK_RETURN))
        {
            SceneManager::Instance().lock()->SetNextScene(SceneBase::SceneKind::TitleScene);
        }
    }

    void ResultScene::Draw()
    {
    }
}  // namespace scene
