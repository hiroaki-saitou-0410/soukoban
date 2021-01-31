#include"DxLib.h"
#include"Manager/SceneManager.h"
#include"Manager/GameManager.h"
#include"Manager/InputManager.h"

const int WINDOW_W = 640;
const int WINDOW_H = 480;
const int COLOR_BIT = 32;

int WINAPI WinMain(_In_ HINSTANCE hIstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, COLOR_BIT);
	SetBackgroundColor(125, 125, 125);
	SetMainWindowText("血だらけの倉庫番");
	if (DxLib_Init() == -1){return - 1;}//エラー発生時即終了

	//描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);
	
	//管理クラスの作成
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	GameManager::CreateInstance();

	//複数インスタンス化しないようにしたい
	//Singleton singleton1;
	//Singleton singleton2;
	

	while (true)
	{
		if (ProcessMessage() != 0) { break; }//Windowsのメッセージ処理か、閉じられたら

		//DxLibのお約束：画面クリア
		ClearDrawScreen();
		clsDx();

		//処理
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();
		//描画
		SceneManager::GetInstance()->Draw();

		ScreenFlip();	//DxLibのお約束：画面更新
	}

	
	//管理クラスの後始末
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();

	DxLib_End();//DXライブラリ使用の終了

	return 0;
}