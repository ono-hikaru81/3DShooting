
#include "../Manager/SceneManager.h"
#include "TitleScene.h"

namespace scene 
{
    void TitleScene::Exec()
    {
        if (Engine::Library::IsKeyPushed(DIK_RETURN))
        {
            SceneManager::Instance().lock()->SetNextScene(SceneBase::SceneKind::InGameScene);
        }
    }
    
    void TitleScene::Draw()
    {
    }
}  // namespace scene
