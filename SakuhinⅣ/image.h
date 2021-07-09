#pragma once

#include "DxLib.h"
#include"define.h"
#include "class.h"


//プレイー画像
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\chara.png")		//プレイヤー画像パス
#define PLAYER_CHANGE_NUM	3	//プレイヤー画像変更回数
#define PLAYER_WIDTH		32	//プレイヤー画像横
#define PLAYER_HEIGHT		32	//プレイヤー画像縦
#define PLAYER_DIV_TATE		4	//プレイヤー画像縦分割数
#define	PLAYER_DIV_YOKO		3	//プレイヤー画像横分割数
#define PLAYER_DIV_NUM		PLAYER_DIV_TATE*PLAYER_DIV_YOKO		//プレイヤー画像総分割数
#define PLAYER_ROTA			2.0	//プレイヤー拡大率
#define PLAYER_ACTWAIT		100	//プレイヤーアニメーション待ち時間
#define PLAYER_LEFT			3	//左向き
#define PLAYER_LEFT_MAX		5	//左最大
#define PLAYER_RIGHT		6	//右向き
#define	PLAYER_RIGHT_MAX	8	//右最大
#define PLAYER_BACK			9	//後ろ向き
#define PLAYER_BACK_MAX		11	//後ろ最大
#define PLAYER_RIGHT_STAY	7	//右向き待ち
#define PLAYER_LEFT_STAY	4	//左向き待ち

#define GAME_MAP_PATH		TEXT(".\\IMAGE\\mapuse.png")		//マップ画像パス

#define GAME_MAP_ROOM_NUMBER     8

//通路
#define GAME_CSV_PATH_STAGEPASS_FLOOR 		TEXT(".\\IMAGE\\csv\\turo_床.csv")//通路床
#define GAME_CSV_PATH_STAGEPASS_WALL 		TEXT(".\\IMAGE\\csv\\turo_壁.csv")//通路壁
#define GAME_CSV_PATH_STAGEPASS_RECT 		TEXT(".\\IMAGE\\csv\\turo_当たり判定.csv")//通路当たり判定
#define GAME_CSV_PATH_STAGEPASS_SG 		    TEXT(".\\IMAGE\\csv\\turo_SG.csv")//通路スタートゴール

//ステージ1
#define GAME_CSV_PATH_STAGE1_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage1_床.csv")//STAGE1床
#define GAME_CSV_PATH_STAGE1_WALL 		TEXT(".\\IMAGE\\csv\\Stage1_壁.csv")//STAGE1壁
#define GAME_CSV_PATH_STAGE1_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage1_血.csv")//STAGE1血
#define GAME_CSV_PATH_STAGE1_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage1_重ね血.csv")//STAGE1重ね血
#define GAME_CSV_PATH_STAGE1_ACCES 		TEXT(".\\IMAGE\\csv\\Stage1_小物.csv")//STAGE1小物
#define GAME_CSV_PATH_STAGE1_RECT 		TEXT(".\\IMAGE\\csv\\Stage1_当たり判定.csv")//STAGE1当たり判定
#define GAME_CSV_PATH_STAGE1_SG 		TEXT(".\\IMAGE\\csv\\Stage1_SG.csv")//STAGE1スタートゴール
#define GAME_CSV_PATH_STAGE1_GIMMICK    TEXT(".\\IMAGE\\csv\\Stage1_ギミック.csv")//STAGE1ギミック

//ステージ2
#define GAME_CSV_PATH_STAGE2_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage2_床.csv")//STAGE2床
#define GAME_CSV_PATH_STAGE2_WALL 		TEXT(".\\IMAGE\\csv\\Stage2_壁.csv")//STAGE2壁
#define GAME_CSV_PATH_STAGE2_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage2_血.csv")//STAGE2血
#define GAME_CSV_PATH_STAGE2_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage2_重ね血.csv")//STAGE重ね血
#define GAME_CSV_PATH_STAGE2_ACCES 		TEXT(".\\IMAGE\\csv\\Stage2_小物.csv")//STAGE2小物
#define GAME_CSV_PATH_STAGE2_RECT 		TEXT(".\\IMAGE\\csv\\Stage2_当たり判定.csv")//STAGE2当たり判定
#define GAME_CSV_PATH_STAGE2_SG 		TEXT(".\\IMAGE\\csv\\Stage2_SG.csv")//STAGE2スタートゴール


//ステージ3
#define GAME_CSV_PATH_STAGE3_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage4_床.csv")//STAGE3床
#define GAME_CSV_PATH_STAGE3_WALL 		TEXT(".\\IMAGE\\csv\\Stage4_壁.csv")//STAGE3壁
#define GAME_CSV_PATH_STAGE3_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage4_血.csv")//STAGE3血
#define GAME_CSV_PATH_STAGE3_GIMMICK    TEXT(".\\IMAGE\\csv\\Stage4_ギミック.csv")//STAGE3ギミック
#define GAME_CSV_PATH_STAGE3_RECT 		TEXT(".\\IMAGE\\csv\\Stage4_当たり判定.csv")//STAGE3当たり判定
#define GAME_CSV_PATH_STAGE3_SG 		TEXT(".\\IMAGE\\csv\\Stage4_SG.csv")//STAGE3スタートゴール

//ステージ4
#define GAME_CSV_PATH_STAGE4_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage5_床.csv")//STAGE4床
#define GAME_CSV_PATH_STAGE4_WALL 		TEXT(".\\IMAGE\\csv\\Stage5_壁.csv")//STAGE4壁
#define GAME_CSV_PATH_STAGE4_ACCES 		TEXT(".\\IMAGE\\csv\\Stage5_小物.csv")//STAGE4小物
#define GAME_CSV_PATH_STAGE4_GIMMICK    TEXT(".\\IMAGE\\csv\\Stage5_ギミック.csv")//STAGE4ギミック
#define GAME_CSV_PATH_STAGE4_RECT 		TEXT(".\\IMAGE\\csv\\Stage5_当たり判定.csv")//STAGE4当たり判定
#define GAME_CSV_PATH_STAGE4_SG 		TEXT(".\\IMAGE\\csv\\Stage5_SG.csv")//STAGE4スタートゴール

//ステージ5
#define GAME_CSV_PATH_STAGE5_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage6_床.csv")//STAGE5床
#define GAME_CSV_PATH_STAGE5_WALL 		TEXT(".\\IMAGE\\csv\\Stage6_壁.csv")//STAGE5壁
#define GAME_CSV_PATH_STAGE5_ACCES 		TEXT(".\\IMAGE\\csv\\Stage6_小物.csv")//STAGE5血
#define GAME_CSV_PATH_STAGE5_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage6_血.csv")//STAGE5血
#define GAME_CSV_PATH_STAGE5_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage6_重ね血.csv")//STAGE5重ね血
#define GAME_CSV_PATH_STAGE5_GIMMICK    TEXT(".\\IMAGE\\csv\\Stage6_ワープ対応.csv")//STAGE5ワープギミック
#define GAME_CSV_PATH_STAGE5_RECT 		TEXT(".\\IMAGE\\csv\\Stage6_当たり判定.csv")//STAGE5当たり判定
#define GAME_CSV_PATH_STAGE5_SG 		TEXT(".\\IMAGE\\csv\\Stage6_SG.csv")//STAGE5スタートゴール

//ステージ6
#define GAME_CSV_PATH_STAGE6_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage7_床.csv")//STAGE6床
#define GAME_CSV_PATH_STAGE6_WALL 		TEXT(".\\IMAGE\\csv\\Stage7_壁.csv")//STAGE6壁
#define GAME_CSV_PATH_STAGE6_RECT 		TEXT(".\\IMAGE\\csv\\Stage7_当たり判定.csv")//STAGE6当たり判定
#define GAME_CSV_PATH_STAGE6_SG 		TEXT(".\\IMAGE\\csv\\Stage7_SG.csv")//STAGE6スタートゴール

//ステージ7
#define GAME_CSV_PATH_STAGE7_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage8_床.csv")//STAGE7床
#define GAME_CSV_PATH_STAGE7_WALL 		TEXT(".\\IMAGE\\csv\\Stage_壁.csv")//STAGE7壁
#define GAME_CSV_PATH_STAGE7_ACCES 		TEXT(".\\IMAGE\\csv\\Stage8_小物.csv")//STAGE7血
#define GAME_CSV_PATH_STAGE7_GIMMICK    TEXT(".\\IMAGE\\csv\\Stage8_ギミック.csv")//STAGE7ギミック
#define GAME_CSV_PATH_STAGE7_RECT 		TEXT(".\\IMAGE\\csv\\Stage8_当たり判定.csv")//STAGE7当たり判定
#define GAME_CSV_PATH_STAGE7_SG 		TEXT(".\\IMAGE\\csv\\Stage8_SG.csv")//STAGE7スタートゴール

//画像
class IMAGE
{
public:
	int x;
	int y;
	int width;
	int height;

private:
	int handle;
	char path[PATH_MAX] = "";

public:
	//handleの設定
	VOID SetHandle(int Data)
	{
		handle = Data;
		return;
	}

	//handleを消す
	VOID DeleteHandle(VOID)
	{
		DeleteGraph(handle);
		return;
	}

	//パスの設定
	VOID SetPath(const char* Path)
	{
		strcpy_s(path, Path);
		return;
	}

	//ハンドルを返す
	int GetHandle(VOID)
	{
		return(handle);
	}

	//パスを返す
	char* GetPath(VOID)
	{
		return(path);
	}
};

//タイトル背景
class IMAGE_BACK : IMAGE
{
public:
	BOOL IsDraw;

};

//マップ部屋（ギミック）
typedef struct MAP_ROOM
{
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	GAME_GIMMICK_KIND gimmick;
	int x;
	int y;
	bool IsGimmickClear;

	IPOINT StartPt;   //スタート地点
	IPOINT GoalPt;	  //ゴール地点
};

typedef struct MAP_ROOM MAP_ROOM;

//マップ通路
typedef struct MAP_PASS
{

	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	int From;
	int To;

	IPOINT StartPt;   //スタート地点
	IPOINT GoalPt;	  //ゴール地点
};

typedef struct MAP_PASS MAP_PASS;

BOOL MY_LOAD_MAPCHIP(VOID);
BOOL MY_LOAD_CSV(VOID);

BOOL MY_LOAD_IMAGE(VOID);
VOID MY_DELETE_IMAGE(VOID);


//CSVのマップを読み込み
BOOL MY_LOAD_CSV_MAP(const char*, MAP_ROOM*, int Layer);
BOOL MY_LOAD_CSV_PASS(const char *, MAP_PASS*,int Layer);

VOID START_DRAW(VOID);	//スタート画面の描画
VOID RULE_DRAW(VOID);	//ルール画面の描画
VOID PLAY_DRAW(VOID);	//プレイ画面の描画
VOID MENU_DRAW(VOID);	//メニュー画面の描画
VOID END_DRAW(VOID);	    //エンド画面の描画