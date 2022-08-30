
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>

#include "../Scene/SceneBase.h"
#include "../../Utility/Singleton.h"

namespace scene
{
    class SceneManager : public Utility::Singleton<SceneManager>
    {
    public:
        SceneManager();
        ~SceneManager() = default;

    public:
        /*
        * @brief 遷移先のシーン
        */
        SceneBase::SceneKind SetNextScene(SceneBase::SceneKind nextScene_)
        {
            nextScene = nextScene_;
            return nextScene;
        }

    public:
        /*
        * @brief シーンの更新
        */
        void Update()
        {
            Exec();
            Draw();
        }

    private:
        /*
        * @brief 処理
        */
        void Exec();
        
        /*
        * @brief 描画
        */
        void Draw();
        
        /*
        * @brief nextSceneを参照してcurrentSceneを更新する
        */
        void CreateNextScene();

    private:
        std::unique_ptr<SceneBase> currentScene;
        SceneBase::SceneKind previousScene;
        SceneBase::SceneKind nextScene;
    };
}  // namespace scene

#endif  // !SCENEMANAGER_H
