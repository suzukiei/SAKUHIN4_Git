#include "class.h"
//キーボードの種類
#define KEY_CODE_KIND		256	//256種類
#define CharaSpeed 2			//キャラクターのスピード


BOOL MOVEMENT(CHARA *,MOVE);				//キャラの移動関数 //移動できたときTRUE
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数
BOOL CHARA_COLLISION(CHARA,MAP[MAP_DIV_HEIGHT][MAP_DIV_WIDTH]); //当たり判定を確認する関数の定義 //壁などに衝突しているときTRUE


//キーボードの入力を取得
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//すべてのキーの状態(直前)が入る


BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する 
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する

enum MOVE {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum PLAYER_KIND_1 {
	D_1, D_2, D_3, D_4,
	L_1, L_2, L_3, L_4,
	R_1, R_2, R_3, R_4,
	U_1, U_2, U_3, U_4
};//(U上/D下/R右/L左)