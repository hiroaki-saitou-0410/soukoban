#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../Definition.h"
#include"../Singleton.h"

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();


	void Exec();
	void Draw();

	
	void SetNextScene(SceneID next_);//次のシーン

private:
	class SceneBase* create_NextScene();

private:
	class SceneBase* m_pScene;			//実行中のシーン
	static SceneID m_NextSceneID;		//次の作るシーン
};
#if 0
//-------------------------------------------------------------------
	//シングルトンデザインパターン

private:
	//自分自身でポインター変数(唯一の実体)
	static SceneManager* m_pInstance;

	public:
	static void CreateInstance()
	{
		//もう作られているなら作らない(必ず１つだけ)
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManager();
		}
	}

	//実体を破壊する関数
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	//実体を取得する関数
	static SceneManager* GetInstance()
	{
		return m_pInstance;
	}

	//実体が存在しないか確認する
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};

//
SceneManager* SceneManager::m_pInstance = nullptr;
#endif
#endif // !SCENE_MANAGER_H

