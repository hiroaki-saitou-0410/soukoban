
#ifndef DEFINITION_H
#define DEFINITION_H

enum SceneID
{
	SceneID_Title,		//タイトル
	SceneID_InGame,		//ゲーム
	SceneID_Result,		//リザルト

	SceneID_Max,
	SceneID_Invalid,	//無効値
};
//-------
//倉庫番
//ステージ情報
const int STAGE_WIDTH = 11;
const int STAGE_HEIGHT = 13;

//マップチップの縦横のサイズ
const int CHIP_WIDTH = 32;
const int CHIP_HEIGHT = 32;

/*オブジェクト種類
０地面
１壁
２プレイヤー初期値
３クレート配置場所
４未配置のクレート
７配置済みのクレート
(配置場所'３'+未配置クレート'４'=7)*/
enum ObjectType
{
	ObjectType_Ground,			//0
	ObjectType_Wall,			//1
	ObjectType_Player,			//2
	ObjectType_Target,			//3
	ObjectType_UnsetCrate,		//4
	ObjectType_SetCrate = 7,	//7
};

//移動方向
enum DirType
{
	DirType_Up,		//↑
	DirType_Down,	//↓
	DirType_Left,	//←
	DirType_Right,	//→

	//画像読み込みで使用
	DirType_Max,
};

#endif // !DEFINITION_H
