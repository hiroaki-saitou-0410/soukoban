
#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include"SceneBase.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();

	void Exec();
	void Draw();

	virtual bool IsEnd() const;

private:
	//
	void step_LogoIn();

	void step_Input();
	int Texture;
	int Texture2;
	int m_PosX;
	int m_PosY;
};


#endif // !TITLE_SCENE_H
