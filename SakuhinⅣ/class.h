#pragma once

#include "define.h"
#include "image.h"
//#include "movement.h"

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
	int CharaMoveCnt;            //キャラクターの移動管理
	//int  Dire;                   //向いている方向
	BOOL InRoom = false;         //部屋にいるかどうか
	BOOL InPass = false;         //通路に居るかどうか

	RECT coll;
	IPOINT collBeforePt;
};




//マップ画像配列(いらないかも)
//class MAP_CHIP
//{
//public:
//
//	MAPCHIP mapchip[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
//};
