#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include"SceneBase.h"
#include"../Definition.h"
#include"../Manager/GameManager.h"

class InGameScene : public SceneBase
{
public:
	InGameScene();
	~InGameScene();

	void Exec();
	void Draw();
	void InitTexture();
	void ReleaseTexture();
	virtual bool IsEnd() const;

private:
	void step_StartJingle();
	void step_Input();
	void step_ClearJingle();
	GameManager* gameManager = nullptr;

	//‘qŒÉ”Ô‚ÉŠÖ‚·‚éŠÖ”ŒR
private:
	//ƒNƒŠƒA”»’è
	bool IsClear() const;
	//‰Šúó‘Ô‰»
	void Reset();
	//ˆÚ“®ˆ—
	void Move(DirType dir_);

private:
	int m_StageData[STAGE_HEIGHT][STAGE_WIDTH];
	int m_PlayerX;
	int m_PlayerY;

	//‰æ‘œ•Û‘¶
	static const int m_CrateMax = 3;
	static const int m_MoveMax = 4;
	static const int m_PlayerTextureMax = 12;
	int m_Turn;
	int m_ground;
	int m_block;
	int m_Index;
	int m_WaitTime;
	int m_Move;
	int m_MoveSpeed;
	int m_crate[m_CrateMax];
	int m_UpMove[m_MoveMax] = { 0,1,0,2 };
	int m_DownMove[m_MoveMax] = { 3, 4,3, 5 };
	int m_LeftMove[m_MoveMax] = { 6, 7,6, 8 };
	int m_RightMove[m_MoveMax] = { 9,10,9,11 };
	int m_Player[m_PlayerTextureMax];
};

#endif // !INGAME_SCENE_H

