
#include"ResultScene.h"
#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"

//���s�X�e�b�v
enum
{
	STEP_INPUT,		//���͑҂�
	STEP_END,		//�V�[���I��
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
	//��ʍ���Ƀf�o�b�N�p�̕��������ŕ\��
	DrawFormatString(220, 200, GetColor(0, 0, 0), "%d��ŃN���A", m_Counter);
	DrawString(200, 250, "EneterKey�Ń^�C�g���ɖ߂�", GetColor(0, 0, 0));
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
