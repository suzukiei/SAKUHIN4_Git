/*作品制作Ⅳ_冥闇の眼*/
#include "DxLib.h"
#include "BGM.h"
#include "class.h"
#include "define.h"
#include "enum.h"
#include "flag.h"
#include "GameProcHeader.h"
#include "image.h"
#include "menu.h"
#include "movement.h"
#include "textevent.h"
#include "title.h"
#include "variable.h"


//キーボードの入力を取得
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//すべてのキーの状態(直前)が入る
int CharaMoveCnt = 0;

//BOOL CHARA_COLLISION(CHARA, CHARA)
//{
//	return FALSE; //ダミー関数
//}

BOOL MOVEMENT(CHARA* chara,int move)
{

	BOOL IsMove = TRUE; //移動可能
	CHARA work = *chara;



	switch (move)
	{
	case UP:
		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{
			work.image.y -= CharaSpeed;	//移動
			work.CenterY -= CharaSpeed;
			work.coll.top -= CharaSpeed;
			work.coll.bottom -= CharaSpeed;
			CharaMoveCnt = 0;
		}
		 
			if (work.kind1 >= CHARACHIP_UP_1 && work.kind1 < CHARACHIP_UP_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					work.kind1++;			//次の画像にする
					work.imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				work.kind1 = CHARACHIP_UP_1;	//最初の画像にする
			}

		
			break;


	

	case DOWN:

		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{

			work.image.y += CharaSpeed;	//移動
			work.CenterY += CharaSpeed;
			work.coll.top += CharaSpeed;
			work.coll.bottom += CharaSpeed;
			CharaMoveCnt = 0;
		}
	
	

	
			if (work.kind1 >= CHARACHIP_DOWN_1 && work.kind1 < CHARACHIP_DOWN_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					work.kind1++;			//次の画像にする
					work.imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				work.kind1 = CHARACHIP_DOWN_1;	//最初の画像にする
			}
			

		

		break;

	case RIGHT:

		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{
			work.image.x += CharaSpeed;	//移動
			work.CenterX += CharaSpeed;
			work.coll.left += CharaSpeed;
			work.coll.right += CharaSpeed;
			CharaMoveCnt = 0;
		}

			if (work.kind1 >= CHARACHIP_RIGHT_1 && work.kind1 < CHARACHIP_RIGHT_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					work.kind1++;			//次の画像にする
					work.imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				work.kind1 = CHARACHIP_RIGHT_1;	//最初の画像にする
			}
	
		

		break;

	case LEFT:


		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{
			work.image.x -= CharaSpeed;	//移動
			work.CenterX -= CharaSpeed;
			work.coll.left -= CharaSpeed;
			work.coll.right -= CharaSpeed;
			CharaMoveCnt = 0;
		}
			if (work.kind1 >= CHARACHIP_LEFT_1 && work.kind1 < CHARACHIP_LEFT_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					work.kind1++;			//次の画像にする
					work.imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				work.kind1 = CHARACHIP_LEFT_1;	//最初の画像にする
			}
	
		

		break;
	}

	//衝突がなければ、workから大本のキャラの情報に入れる。
	if (work.InRoom) {
		if (CHARA_COLLISION(work.coll, mapRoom[work.nowRoom].map) == FALSE) {
			*chara = work;
			return TRUE;//移動できているのでTRUEを返す。
		}
	}
	if (work.InPass) {
		if (CHARA_COLLISION(work.coll, mappass.map) == FALSE) {
			*chara = work;
			return TRUE;//移動できているのでTRUEを返す。
		}
	}

	return FALSE;



}



	

//キーを押し上げたか、キーコードで判断する
 BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//直前は押していて
		&& AllKeyState[KEY_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//キーを押し上げている
	}
	else
	{
		return FALSE;	//キーを押し上げていない
	}
}

//キーを押しているか、キーコードで判断する
 BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//キーコードのキーを押している時
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//キーを押している
	}
	else
	{
		return FALSE;	//キーを押していない
	}
}

//########## キーの入力状態を更新する関数 ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{

	//一時的に、現在のキーの入力状態を格納する
	char TempKey[KEY_CODE_KIND];

	//直前のキー入力をとっておく
	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}
