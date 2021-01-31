#ifndef SCENE_BASE_H
#define SCENE_BASE_H

class SceneBase
{
public:
	SceneBase();
	virtual~SceneBase();

	//処理内容は派生クラス毎に違うので純粋仮想関数として宣言
	virtual void Exec() = 0;//処理
	virtual void Draw() = 0;//描画

	virtual bool IsEnd() const = 0;//シーンが終了したかどうかを返す

protected:
	int m_Step;//処理使用を管理する変数
};

#endif // !SCENE_BASE_H

