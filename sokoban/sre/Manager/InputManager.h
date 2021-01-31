#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include"../KeyDefinition.h"
#include"../Singleton.h"

//入力管理クラス
class InputManager : public Singleton<InputManager>
{
private:
	//キーの状態構造体
	struct KeyState
	{
		bool old;	//前回check時のフラグ状態

		bool push;	//押された瞬間
		bool on;	//押下している
		bool pull;	//離された瞬間

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

	//キー入力更新
	void Update();

	//キーが押された瞬間
	bool IsPush(KeyType Key)const;
	//押下しているか
	bool IsOn(KeyType Key)const;
	//離された瞬間
	bool IsPull(KeyType Key)const;

private:
	KeyState m_State[KeyType_Max];
};


#endif // !INPUT_MANAGER_H

