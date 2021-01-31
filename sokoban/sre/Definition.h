
#ifndef DEFINITION_H
#define DEFINITION_H

enum SceneID
{
	SceneID_Title,		//�^�C�g��
	SceneID_InGame,		//�Q�[��
	SceneID_Result,		//���U���g

	SceneID_Max,
	SceneID_Invalid,	//�����l
};
//-------
//�q�ɔ�
//�X�e�[�W���
const int STAGE_WIDTH = 11;
const int STAGE_HEIGHT = 13;

//�}�b�v�`�b�v�̏c���̃T�C�Y
const int CHIP_WIDTH = 32;
const int CHIP_HEIGHT = 32;

/*�I�u�W�F�N�g���
�O�n��
�P��
�Q�v���C���[�����l
�R�N���[�g�z�u�ꏊ
�S���z�u�̃N���[�g
�V�z�u�ς݂̃N���[�g
(�z�u�ꏊ'�R'+���z�u�N���[�g'�S'=7)*/
enum ObjectType
{
	ObjectType_Ground,			//0
	ObjectType_Wall,			//1
	ObjectType_Player,			//2
	ObjectType_Target,			//3
	ObjectType_UnsetCrate,		//4
	ObjectType_SetCrate = 7,	//7
};

//�ړ�����
enum DirType
{
	DirType_Up,		//��
	DirType_Down,	//��
	DirType_Left,	//��
	DirType_Right,	//��

	//�摜�ǂݍ��݂Ŏg�p
	DirType_Max,
};

#endif // !DEFINITION_H
