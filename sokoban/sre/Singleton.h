#ifndef SINGLETON_H
#define SINGLETON_H

//シングルトン・デザパタ
template< class T>
class Singleton
{
protected:
	Singleton(){}				//コンストラクタ制限
	virtual ~Singleton(){}		//デストラクタ制限

private:
	//自分自身でポインター変数(唯一の実体)
	static T* m_pInstance;

public:
	//実体を作る
	static void CreateInstance()
	{
		//もう作られているなら作らない(必ず１つだけ)
		if (m_pInstance == nullptr)
		{
			m_pInstance = new T();
		}
	}

	//実体を破壊する関数
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	//実体を取得する関数
	static T* GetInstance()
	{
		return m_pInstance;
	}

	//実体が存在しないか確認する
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};
//staticなメンバ変数を初期化(コンストラクトではやらない)
template<class T>
T* Singleton<T>::m_pInstance = nullptr;

#endif // !SINGLETON_H

