#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{
private:
	GameManager();
	static GameManager* gameManager;//
	
public:
	static void CreateInstance();//インスタンスを生成
	static void DestroyInstance();//メモリの解放

	static GameManager* GetInstance();//インスタンスのアドレス取得

	int GetCount() const { return counter; };
	void SetCount(int a) { counter = a; };

private:
	int counter = 0;
};


#endif // !GAME_MANAGER_H

