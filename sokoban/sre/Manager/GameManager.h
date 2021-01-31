#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{
private:
	GameManager();
	static GameManager* gameManager;//
	
public:
	static void CreateInstance();//�C���X�^���X�𐶐�
	static void DestroyInstance();//�������̉��

	static GameManager* GetInstance();//�C���X�^���X�̃A�h���X�擾

	int GetCount() const { return counter; };
	void SetCount(int a) { counter = a; };

private:
	int counter = 0;
};


#endif // !GAME_MANAGER_H

