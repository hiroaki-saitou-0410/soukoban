#include"InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	for (int i = 0; i < KeyType_Max; i++)
	{
		//現在の状態を取得
		const bool now = (CheckHitKey(KEY_ASSIGN[i]) == 1);

		//前回の状態と比較して現在の状態を更新
		m_State[i].on = now;
		m_State[i].pull = (now == true) &&(m_State[i].old == false);
		m_State[i].push = (now == false)&&(m_State[i].old == true);
		//m_State[i].pull =  now & !m_State[i].old;
		//m_State[i].push = !now &  m_State[i].old;

		//現在の状態をoldに代入
		m_State[i].old = now;
	}
}

bool InputManager::IsPush(KeyType Key) const
{
	if (Key == KeyType_Max) { return false;}
	return m_State[Key].push;
}

bool InputManager::IsOn(KeyType Key) const
{
	if (Key == KeyType_Max) { return false; }
	return m_State[Key].on;
}

bool InputManager::IsPull(KeyType Key) const
{
	if (Key == KeyType_Max) { return false; }
	return m_State[Key].pull;
}
