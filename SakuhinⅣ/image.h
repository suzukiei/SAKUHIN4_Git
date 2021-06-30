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

#define GAME_CSV_PATH_STAGE1_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage1_床.csv")//STAGE1床
#define GAME_CSV_PATH_STAGE1_WALL 		TEXT(".\\IMAGE\\csv\\Stage1_壁.csv")//STAGE1壁
#define GAME_CSV_PATH_STAGE1_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage1_血.csv")//STAGE1血
#define GAME_CSV_PATH_STAGE1_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage1_重ね血.csv")//STAGE1重ね血
#define GAME_CSV_PATH_STAGE1_ACCES 		TEXT(".\\IMAGE\\csv\\Stage1_小物.csv")//STAGE1小物
#define GAME_CSV_PATH_STAGE1_RECT 		TEXT(".\\IMAGE\\csv\\Stage1_当たり判定.csv")//STAGE1当たり判定
#define GAME_CSV_PATH_STAGE1_SG 		TEXT(".\\IMAGE\\csv\\Stage1_SG.csv")//STAGE1スタートゴール
#define GAME_CSV_PATH_STAGE1_GIMMICK    TEXT(".\\IMAGE\\csv\\Stage1_ギミック.csv")//STAGE1ギミック

#define GAME_CSV_PATH_STAGE2_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage2_床.csv")//STAGE2床
#define GAME_CSV_PATH_STAGE2_WALL 		TEXT(".\\IMAGE\\csv\\Stage2_壁.csv")//STAGE2壁
#define GAME_CSV_PATH_STAGE2_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage2_血.csv")//STAGE2血
#define GAME_CSV_PATH_STAGE2_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage2_重ね血.csv")//STAGE重ね血
#define GAME_CSV_PATH_STAGE2_ACCES 		TEXT(".\\IMAGE\\csv\\Stage2_小物.csv")//STAGE2小物
#define GAME_CSV_PATH_STAGE2_RECT 		TEXT(".\\IMAGE\\csv\\Stage2_当たり判定.csv")//STAGE2当たり判定
#define GAME_CSV_PATH_STAGE2_SG 		TEXT(".\\IMAGE\\csv\\Stage2_SG.csv")//STAGE2スタートゴール

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
BOOL MY_LOAD_CSV_MAP(const char *, MAP_ROOM*,int Layer);

VOID START_DRAW(VOID);	//スタート画面の描画
VOID RULE_DRAW(VOID);	//ルール画面の描画
VOID PLAY_DRAW(VOID);	//プレイ画面の描画
VOID END_DRAW(VOID);	    //エンド画面の描画