#ifndef KEY_DEFINITION_H
#define  KEY_DEFINITION_H

#include"DxLib.h"

//キーの種類
enum KeyType
{
	KeyType_Up,		//↑
	KeyType_Down,	//↓
	KeyType_Left,	//←
	KeyType_Right,	//→
	KeyType_Enter,	//決定
	KeyType_Reset,	//リセット
	
	KeyType_Max,	//キーの種類の数
};

//キーの種類に対応する、実際の入力配列
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

