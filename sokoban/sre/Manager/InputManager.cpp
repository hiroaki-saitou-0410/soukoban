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
		//Œ»İ‚Ìó‘Ô‚ğæ“¾
		const bool now = (CheckHitKey(KEY_ASSIGN[i]) == 1);

		//‘O‰ñ‚Ìó‘Ô‚Æ”äŠr‚µ‚ÄŒ»İ‚Ìó‘Ô‚ğXV
		m_State[i].on = now;
		m_State[i].pull = (now == true) &&(m_State[i].old == false);
		m_State[i].push = (now == false)&&(m_State[i].old == true);
		//m_State[i].pull =  now & !m_State[i].old;
		//m_State[i].push = !now &  m_State[i].old;

		//Œ»İ‚Ìó‘Ô‚ğold‚É‘ã“ü
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
