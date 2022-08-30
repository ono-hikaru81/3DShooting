
#include "Definition.h"
#include "Library/Library.h"
#include "Game/Manager/SceneManager.h"

int APIENTRY WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT)
{
	// エンジン初期化
	if (!Engine::Library::Initialize("DirectX11Library", static_cast<int>(WindowInfo::size.GetX()), static_cast<int>(WindowInfo::size.GetY()))) return 0;

	// 音楽ファイル読み込み
	Engine::Library::LoadSoundFile(Engine::Sound::File::TestBGM, "Res/Sound/loop1.wav");

	// シーン作成
	auto sceneManager = scene::SceneManager::Instance();

	// メインループ
	while (true)
	{
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// 描画開始
			Engine::Library::StartRendering();

			// 入力更新
			Engine::Library::InputUpdate();

			// シーン更新
			sceneManager.lock()->Update();

			if (Engine::Library::IsKeyHeld(DIK_R))
			{
				// 音楽ファイル再生
				Engine::Library::PlaySoundFile(Engine::Sound::File::TestBGM, true);
			}

			if (Engine::Library::IsKeyHeld(DIK_S))
			{
				// 音楽ファイル停止
				Engine::Library::StopSoundFile(Engine::Sound::File::TestBGM);
			}

			// 描画終了
			Engine::Library::FinishRendering();
		}
	}

	// エンジン解放
	Engine::Library::Release();

	return 0;
}
