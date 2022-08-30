
#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "SceneBase.h"

namespace scene
{
    class ResultScene : public SceneBase
    {
    public:
        ResultScene() = default;
        
        ~ResultScene() = default;
        
    public:
        void Exec();
        
        void Draw();
    };
}  // namespace scene

#endif  // !RESULT_SCENE_H
