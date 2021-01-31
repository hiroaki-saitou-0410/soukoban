
#include"TitleScene.h"
#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"

//実行ステップ
enum 
{
	STEP_LOGO_IN,	//ロゴ入場待ち
	STEP_INPUT,		//入力待ち
	STEP_END,		//シーン終了
};

TitleScene::TitleScene()
{
	m_Step = STEP_LOGO_IN;
	Texture = LoadGraph("res/Player/player_03.png");
	Texture2 = LoadGraph("res/Crate/crate_02.png");
	m_PosX = 320;
	m_PosY = 200;
}

TitleScene::~TitleScene()
{
	DeleteGraph(Texture);
	DeleteGraph(Texture2);
}

void TitleScene::Exec()
{
	switch (m_Step)
	{
	case STEP_LOGO_IN:step_LogoIn(); break;
	case STEP_INPUT: step_Input(); break;
	default: break;
	};
	
}

void TitleScene::Draw()
{
	//画面左上にデバック用の文字を黒で表示 640,480
	DrawString(150, 200, "倉庫番！", GetColor(0, 0, 0));
	DrawString(120, 250, "EnterKeyでスタート", GetColor(0, 0, 0));
	DrawExtendGraph(m_PosX, m_PosY, m_PosX+100, m_PosY+100, Texture2, TRUE);
	DrawExtendGraph(m_PosX,110, m_PosX + 100,210, Texture,TRUE);
}

bool TitleScene::IsEnd() const
{
	//@@Dummy：確認用の仮
	return (m_Step == STEP_END);
}

void TitleScene::step_LogoIn()
{
	m_Step = STEP_INPUT;
}

void TitleScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_InGame);
	}
}
