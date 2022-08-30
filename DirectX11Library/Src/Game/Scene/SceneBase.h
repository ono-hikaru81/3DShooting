
#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <memory>

#include "../../Library/Library.h"

namespace scene
{
	class SceneBase
	{
	public:
		enum class SceneKind
		{
			TitleScene,		// タイトルシーン
			InGameScene,	// インゲームシーン
			ResultScene		// リザルトシーン
		};

	public:
		SceneBase() = default;
		
		virtual ~SceneBase() = default;

	public:
		virtual void Exec() = 0;
		
		virtual void Draw() = 0;
	};
}  // namespace scene

#endif  // !SCENE_BASE_H
