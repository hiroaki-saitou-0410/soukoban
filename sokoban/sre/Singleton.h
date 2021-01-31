#ifndef SINGLETON_H
#define SINGLETON_H

//�V���O���g���E�f�U�p�^
template< class T>
class Singleton
{
protected:
	Singleton(){}				//�R���X�g���N�^����
	virtual ~Singleton(){}		//�f�X�g���N�^����

private:
	//�������g�Ń|�C���^�[�ϐ�(�B��̎���)
	static T* m_pInstance;

public:
	//���̂����
	static void CreateInstance()
	{
		//��������Ă���Ȃ���Ȃ�(�K���P����)
		if (m_pInstance == nullptr)
		{
			m_pInstance = new T();
		}
	}

	//���̂�j�󂷂�֐�
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	//���̂��擾����֐�
	static T* GetInstance()
	{
		return m_pInstance;
	}

	//���̂����݂��Ȃ����m�F����
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};
//static�ȃ����o�ϐ���������(�R���X�g���N�g�ł͂��Ȃ�)
template<class T>
T* Singleton<T>::m_pInstance = nullptr;

#endif // !SINGLETON_H

