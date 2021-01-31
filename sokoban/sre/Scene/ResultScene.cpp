
#include"ResultScene.h"
#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"

//実行ステップ
enum
{
	STEP_INPUT,		//入力待ち
	STEP_END,		//シーン終了
};

ResultScene::ResultScene()
	:m_Counter(0)
{
	m_Step = STEP_INPUT;
	gameManger = GameManager::GetInstance();
	m_Counter = gameManger->GetCount();
}

ResultScene::~ResultScene()
{
	gameManger = nullptr;
}

void ResultScene::Exec()
{
	SceneManager::GetInstance()->SetNextScene(SceneID_Title);
	InputManager* pInputManager = InputManager::GetInstance();
	if (pInputManager->IsPush(KeyType_Enter))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_Title);
	}
}

void ResultScene::Draw()
{
	//画面左上にデバック用の文字を黒で表示
	DrawFormatString(220, 200, GetColor(0, 0, 0), "%d回でクリア", m_Counter);
	DrawString(200, 250, "EneterKeyでタイトルに戻る", GetColor(0, 0, 0));
}

bool ResultScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

void ResultScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		m_Step = STEP_END; 
		SceneManager::GetInstance()->SetNextScene(SceneID_InGame);
	}
}
