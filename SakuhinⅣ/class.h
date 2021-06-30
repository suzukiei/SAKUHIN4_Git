#pragma once

#include "define.h"
#include "image.h"

//プレイヤー
class CHARA
{
public:
	IMAGE image;
	int handle[PLAYER_DIV_NUM];
	int speed;                   //キャラクタースピード
	int CenterX;                 //キャラクターX位置
	int CenterY;                 //キャラクターY位置
	int kind1;                	 //現在のキャラクター状態
	int imgChangeCnt;            //変更したい画像
	int imgChangeCntMAX;         //変更する画像の最大
	int nowRoom;                 //今いる階層
	MOVE Dire;                   //向いている方向
	BOOL InRoom = false;         //部屋にいるかどうか
	BOOL InPass = false;         //通路に居るかどうか

	RECT coll;
	IPOINT collBeforePt;
};


//マップ通路
class MAP_PASS
{
public:
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	int From;
	int To;

	IPOINT StartPt;   //スタート地点
	IPOINT GoalPt;	  //ゴール地点
};

//マップ画像配列(いらないかも)
//class MAP_CHIP
//{
//public:
//
//	MAPCHIP mapchip[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
//};
