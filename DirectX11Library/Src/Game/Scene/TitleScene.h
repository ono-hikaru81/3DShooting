
#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "../Scene/SceneBase.h"

namespace scene
{
    class TitleScene : public SceneBase 
    {
    public:
        TitleScene() = default;
        
        ~TitleScene() = default;

    public:
        void Exec();
        
        void Draw();
    };
}  // namespace scene

#endif  // !TITLE_SCENE_H
