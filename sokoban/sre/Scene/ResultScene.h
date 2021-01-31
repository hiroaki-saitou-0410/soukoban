#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include"SceneBase.h"
#include"../Manager/GameManager.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	~ResultScene();

	void Exec();
	void Draw();
	virtual bool IsEnd() const;

private:
	void step_Input();
	GameManager* gameManger = nullptr;

private:
	int m_Counter;
};

#endif // !RESALT_SCENE_H
