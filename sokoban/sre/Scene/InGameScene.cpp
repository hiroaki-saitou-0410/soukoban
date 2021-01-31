
#include"InGameScene.h"
#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"

//���s�X�e�b�v
enum
{
	STEP_START_JINGLE,	//���S����҂�
	STEP_INPUT,			//���͑҂�
	STEP_CLEAR_JINGLE,	//
	STEP_END,			//�V�[���I��
};
//�q�ɔԂ̏��
const int g_SampleStage[STAGE_HEIGHT][STAGE_WIDTH] =
{
	0,0,0,1,1,1,1,1,0,0,0,
	0,0,0,1,3,3,3,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	1,1,1,1,1,0,1,1,1,1,1,
	1,0,0,4,0,0,1,0,0,0,1,
	1,0,1,0,0,4,0,4,0,0,1,
	1,0,0,0,1,1,1,0,0,0,1,
	1,1,1,0,1,0,1,0,1,1,1,
	0,0,1,0,1,0,1,0,1,0,0,
	0,0,1,0,0,0,0,0,1,0,0,
	0,0,1,0,0,2,0,0,1,0,0,
	0,0,1,1,1,0,1,1,1,0,0,
};

InGameScene::InGameScene()
	:m_PlayerX(0)
	,m_PlayerY(0)
	,m_Turn(0)
{	
	//�X�e�[�W�f�[�^��������
	/*
		g_SampleStage�̒��g��m_StageData�փR�s�[(�ǂݍ���)
		���̎��z��̒��g��Object_Player��������A����X,Y��m_PLayer(X)(Y)�֑��
		m_StageData�ւ�ObjectType_Ground����*/

	Reset();
	gameManager = GameManager::GetInstance();
	m_Step = STEP_START_JINGLE;
	m_MoveSpeed = 5;
	m_Index = 0;
	InitTexture();
}

InGameScene::~InGameScene()
{
	ReleaseTexture();
	gameManager->SetCount(m_Turn);
	gameManager = nullptr;
}

void InGameScene::Exec()
{
	switch (m_Step)
	{
	case STEP_START_JINGLE: step_StartJingle(); break;
	case STEP_INPUT: step_Input();				break;
	case STEP_CLEAR_JINGLE: step_ClearJingle(); break;
	default:									break;
	}
}

void InGameScene::Draw()
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{		
			if (m_StageData[y][x] == ObjectType_Wall)
			{
				DrawGraph(x*32,y*32, m_block, TRUE);
			}
			else if (m_StageData[y][x] == ObjectType_Target)
			{
				DrawGraph(x * 32, y * 32, m_crate[0], TRUE);
			}
			else if (m_StageData[y][x] == ObjectType_UnsetCrate)
			{
				DrawGraph(x * 32, y * 32, m_crate[2], TRUE);
			}
			else if (m_StageData[y][x] == ObjectType_SetCrate)
			{
				DrawGraph(x * 32, y * 32, m_crate[1], TRUE);
			}
		}
	}

	DrawGraph(m_PlayerX * 32, m_PlayerY * 32, m_Player[m_Move], TRUE);

	if (IsClear()==true)
	{
		DrawString(400, 240, "�_(^��^)�^", GetColor(255, 255, 0));
	}
	DrawFormatString(400, 200, GetColor(0, 0, 0), "��:%d", m_Turn);
	//��ʍ���Ƀf�o�b�N�p�̕��������ŕ\��
	DrawString(20, 20, "InGameScene", GetColor(0, 0, 0));
}

void InGameScene::InitTexture()
{
	m_block = LoadGraph("res/Ground/block.png");
	m_ground = LoadGraph("res/Ground/ground.png");
	m_crate[0] = LoadGraph("res/Crate/crate_00.png");
	m_crate[1] = LoadGraph("res/Crate/crate_01.png");
	m_crate[2] = LoadGraph("res/Crate/crate_02.png");
	m_Player[0] = LoadGraph("res/Player/player_00.png");
	m_Player[1] = LoadGraph("res/Player/player_01.png");
	m_Player[2] = LoadGraph("res/Player/player_02.png");
	m_Player[3] = LoadGraph("res/Player/player_03.png");
	m_Player[4] = LoadGraph("res/Player/player_04.png");
	m_Player[5] = LoadGraph("res/Player/player_05.png");
	m_Player[6] = LoadGraph("res/Player/player_06.png");
	m_Player[7] = LoadGraph("res/Player/player_07.png");
	m_Player[8] = LoadGraph("res/Player/player_08.png");
	m_Player[9] = LoadGraph("res/Player/player_09.png");
	m_Player[10] = LoadGraph("res/Player/player_10.png");
	m_Player[11] = LoadGraph("res/Player/player_11.png");

}

void InGameScene::ReleaseTexture()
{
	DeleteGraph(m_block);
	DeleteGraph(m_ground);
	for (int i = 0; i < m_CrateMax; i++)
	{
		DeleteGraph(m_crate[i]);
	}
	for (int i = 0; i < m_PlayerTextureMax; i++)
	{
		DeleteGraph(m_Player[i]);
	}
}

bool InGameScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

void InGameScene::step_StartJingle()
{
	m_Step = STEP_INPUT;
}

void InGameScene::step_Input()
{
	
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Reset))
	{
		Reset();
	}
	else if (pInputMng->IsPush(KeyType_Up))
	{
		m_Turn++;
		m_Move = 0;
		Move(DirType_Up);
	}
	else if (pInputMng->IsPush(KeyType_Down))
	{
		m_Turn++;
		m_Move = 3;
		Move(DirType_Down);
	}
	else if (pInputMng->IsPush(KeyType_Left))
	{
		m_Turn++;
		m_Move = 6;
		Move(DirType_Left);
	}
	else if (pInputMng->IsPush(KeyType_Right))
	{
		m_Turn++;
		m_Move = 9;
		Move(DirType_Right);
	}

	if (IsClear())
	{
		m_Step = STEP_CLEAR_JINGLE; 
	}
}

void InGameScene::step_ClearJingle()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_Result);
	}
}

bool InGameScene::IsClear() const
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (m_StageData[y][x] == ObjectType_UnsetCrate)
			{
				return false;
			}
			
		}
	}
	return true;
}

//������ԂɃ��Z�b�g
void InGameScene::Reset()
{
	//g_SampleStage���g���ăX�e�[�W�f�[�^��������
	//���O���f�[�^��ǂݍ��񂾂�A�X�e�[�W�𑝂₷�ꍇ�������e���l���c�K�v������

	//�R���X�g���N�^�̓��e�����̂܂܃R�s�[���āA�R���X�g���N�^�ł�Reset���Ăяo��
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_StageData[y][x] = g_SampleStage[y][x];
			if (m_StageData[y][x] == ObjectType_Player)
			{
				m_PlayerX = x;
				m_PlayerY = y;
				m_StageData[y][x] = ObjectType_Ground;
			}
		}
	}
}

//�ړ�����
void InGameScene::Move(DirType dir_)
{
	// DirType���͈͊O�������珈���I��
	if (dir_ < DirType_Up && dir_ >= DirType_Max)
	{
		return;
	}
	
	// ����p�̈ꎞ�ϐ�
	int next_x = m_PlayerX;	// ���̈ړ���w
	int next_y = m_PlayerY;	// ���̈ړ���x
	int next2_x = m_PlayerX;	// ���̎��w
	int next2_y = m_PlayerY;	// ���̎��x

	// �ړ������ɉ����č��W��ݒ�
	// next_x(y),next2_x(y)�̒l�����ꂼ��ݒ肷��
	switch (dir_)
	{
	case DirType_Up:
		next_y -= 1;
		next2_y -= 2;
		break;
	case DirType_Down:
		next_y += 1;
		next2_y += 2;
		break;
	case DirType_Left:
		next_x -= 1;
		next2_x -= 2;
		break;
	case DirType_Right:
		next_x += 1;
		next2_x += 2;
		break;
	}

	// �����ɓ��B�������Anext_x(y),next2_x(y)�ɂ́A
	// �㉺���E���ꂼ��̈ړ��悪�����Ă��邪�A
	// �����I�ɂ́A�����ϐ������g�������ł���

	// �ړ��悪��ʊO�Ȃ�A�֐��𔲂���
	if (next_x < 0 ||
		next_y < 0 ||
		next_x >(STAGE_WIDTH - 1) ||
		next_y >(STAGE_HEIGHT - 1))
	{
		return;
	}

	// �ʏ�ړ�
	// �ړ��悪�v���C���[�̏���}�b�v�`�b�v��������Am_PlayerX(Y)��next_x(y)�ŏ㏑��
	if (m_StageData[next_y][next_x] == ObjectType_Ground ||
		m_StageData[next_y][next_x] == ObjectType_Target)
	{
		m_PlayerX = next_x;
		m_PlayerY = next_y;
	}
	// �ړ���ɔ��i�N���[�g�j������ꍇ
	else if (m_StageData[next_y][next_x] == ObjectType_UnsetCrate ||
		m_StageData[next_y][next_x] == ObjectType_SetCrate)
	{
		// �Q�悪��ʊO���`�F�b�N
		if (next2_x < 0 ||
			next2_y < 0 ||
			next2_x >(STAGE_WIDTH - 1) ||
			next2_y >(STAGE_HEIGHT - 1))
		{
			return;
		}
		// �Q�悪�ړ��ł��Ȃ������`�F�b�N
		// �ړ��ł���}�b�v�`�b�v�łȂ��ꍇ�Ƃ�������
		if (m_StageData[next2_y][next2_x] != ObjectType_Ground &&
			m_StageData[next2_y][next2_x] != ObjectType_Target)
		{
			return;
		}

		// �����ɓ��B�����ꍇ�A�K�����������ԂɂȂ��Ă���

		// �ƂȂ�̈ʒu��ύX����
		if (m_StageData[next_y][next_x] == ObjectType_UnsetCrate)
		{
			m_StageData[next_y][next_x] = ObjectType_Ground;
		}
		else
		{
			m_StageData[next_y][next_x] = ObjectType_Target;
		}

		// �Q��ɔ���z�u����
		if (m_StageData[next2_y][next2_x] == ObjectType_Ground)
		{
			m_StageData[next2_y][next2_x] = ObjectType_UnsetCrate;
		}
		else
		{
			m_StageData[next2_y][next2_x] = ObjectType_SetCrate;
		}

		// �v���C���[���ړ�������
		m_PlayerX = next_x;
		m_PlayerY = next_y;
	}
}