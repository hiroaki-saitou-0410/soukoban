#ifndef KEY_DEFINITION_H
#define  KEY_DEFINITION_H

#include"DxLib.h"

//�L�[�̎��
enum KeyType
{
	KeyType_Up,		//��
	KeyType_Down,	//��
	KeyType_Left,	//��
	KeyType_Right,	//��
	KeyType_Enter,	//����
	KeyType_Reset,	//���Z�b�g
	
	KeyType_Max,	//�L�[�̎�ނ̐�
};

//�L�[�̎�ނɑΉ�����A���ۂ̓��͔z��
const int KEY_ASSIGN[KeyType_Max] =
{
	KEY_INPUT_W,
	KEY_INPUT_S,
	KEY_INPUT_A,
	KEY_INPUT_D,
	KEY_INPUT_RETURN,
	KEY_INPUT_R,
};
#endif // !KEY_DEFINITION_H

