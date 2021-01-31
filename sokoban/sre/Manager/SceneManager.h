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

	
	void SetNextScene(SceneID next_);//���̃V�[��

private:
	class SceneBase* create_NextScene();

private:
	class SceneBase* m_pScene;			//���s���̃V�[��
	static SceneID m_NextSceneID;		//���̍��V�[��
};
#if 0
//-------------------------------------------------------------------
	//�V���O���g���f�U�C���p�^�[��

private:
	//�������g�Ń|�C���^�[�ϐ�(�B��̎���)
	static SceneManager* m_pInstance;

	public:
	static void CreateInstance()
	{
		//��������Ă���Ȃ���Ȃ�(�K���P����)
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManager();
		}
	}

	//���̂�j�󂷂�֐�
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	//���̂��擾����֐�
	static SceneManager* GetInstance()
	{
		return m_pInstance;
	}

	//���̂����݂��Ȃ����m�F����
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};

//
SceneManager* SceneManager::m_pInstance = nullptr;
#endif
#endif // !SCENE_MANAGER_H

