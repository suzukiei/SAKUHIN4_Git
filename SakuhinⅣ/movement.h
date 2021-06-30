#pragma once

#include "class.h"
//キーボードの種類
#define KEY_CODE_KIND		256	//256種類
#define CharaSpeed 2			//キャラクターのスピード
#define PLAYER_IMG_CHANGE_MAX 16


BOOL MOVEMENT(CHARA*,int);				//キャラの移動関数 //移動できたときTRUE
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数
BOOL CHARA_COLLISION(CHARA,MAP[MAP_DIV_HEIGHT][MAP_DIV_WIDTH]); //当たり判定を確認する関数の定義 //壁などに衝突しているときTRUE
VOID CHECK_COLLISION_GOAL(VOID);
VOID CHECK_COLLISION_ENEMY(VOID);
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//領域の当たり判定をする関数

//キーボードの入力を取得
extern char AllKeyState[KEY_CODE_KIND];		//すべてのキーの状態が入る
extern char OldAllKeyState[KEY_CODE_KIND];	//すべてのキーの状態(直前)が入る


BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する 
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する

RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

enum MOVE {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum PLAYER_KIND_1 {
	CHARACHIP_DOWN_1, CHARACHIP_DOWN_2, CHARACHIP_DOWN_3,
	CHARACHIP_LEFT_1, CHARACHIP_LEFT_2, CHARACHIP_LEFT_3,
	CHARACHIP_RIGHT_1, CHARACHIP_RIGHT_2, CHARACHIP_RIGHT_3,
	CHARACHIP_UP_1, CHARACHIP_UP_2, CHARACHIP_UP_3,
};//(U上/D下/R右/L左)