#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include"../KeyDefinition.h"
#include"../Singleton.h"

//���͊Ǘ��N���X
class InputManager : public Singleton<InputManager>
{
private:
	//�L�[�̏�ԍ\����
	struct KeyState
	{
		bool old;	//�O��check���̃t���O���

		bool push;	//�����ꂽ�u��
		bool on;	//�������Ă���
		bool pull;	//�����ꂽ�u��

		KeyState()
			:old(false)
			, push(false)
			, on(false)
			, pull(false)
		{}
	};
public:
	InputManager();
	~InputManager();

	//�L�[���͍X�V
	void Update();

	//�L�[�������ꂽ�u��
	bool IsPush(KeyType Key)const;
	//�������Ă��邩
	bool IsOn(KeyType Key)const;
	//�����ꂽ�u��
	bool IsPull(KeyType Key)const;

private:
	KeyState m_State[KeyType_Max];
};


#endif // !INPUT_MANAGER_H
