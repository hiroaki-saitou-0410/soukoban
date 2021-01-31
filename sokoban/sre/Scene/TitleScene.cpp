
#include"TitleScene.h"
#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"

//���s�X�e�b�v
enum 
{
	STEP_LOGO_IN,	//���S����҂�
	STEP_INPUT,		//���͑҂�
	STEP_END,		//�V�[���I��
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
	//��ʍ���Ƀf�o�b�N�p�̕��������ŕ\�� 640,480
	DrawString(150, 200, "�q�ɔԁI", GetColor(0, 0, 0));
	DrawString(120, 250, "EnterKey�ŃX�^�[�g", GetColor(0, 0, 0));
	DrawExtendGraph(m_PosX, m_PosY, m_PosX+100, m_PosY+100, Texture2, TRUE);
	DrawExtendGraph(m_PosX,110, m_PosX + 100,210, Texture,TRUE);
}

bool TitleScene::IsEnd() const
{
	//@@Dummy�F�m�F�p�̉�
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
