
#include "SceneManager.h"

#include "../Scene/TitleScene.h"
#include "../Scene/InGameScene.h"
#include "../Scene/ResultScene.h"

namespace scene
{
    SceneManager::SceneManager() : nextScene(SceneBase::SceneKind::TitleScene), previousScene(SceneBase::SceneKind::TitleScene)
    {
        CreateNextScene();
    }

    void SceneManager::Exec()
    {
        if (!currentScene) return;

        currentScene->Exec();

        if ( previousScene != nextScene ) 
        { 
            CreateNextScene();
        }
    }

    void SceneManager::Draw()
    {
        if (currentScene == nullptr) return;

        currentScene->Draw();
    }

    void SceneManager::CreateNextScene()
    {
        switch (nextScene)
        {
        case SceneBase::SceneKind::TitleScene: currentScene.reset(new InGameScene()); break;
        case SceneBase::SceneKind::InGameScene: currentScene.reset(new InGameScene()); break;
        case SceneBase::SceneKind::ResultScene: currentScene.reset(new ResultScene()); break;
        }

        previousScene = nextScene;
    }
}  // namespace scene
