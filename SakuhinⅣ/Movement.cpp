/*作品制作�W_冥闇の眼*/
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
RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

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
		
			work.image.y -= CharaSpeed;	//移動
		 
			if (work.kind1 >= CHARACHIP_UP_1 && work.kind1 < CHARACHIP_UP_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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

		
			return TRUE; //移動できているのでTRUEを返す
			break;
	

	case DOWN:

	

		//if (CHARA_COLLISION == FALSE){
			if (work.kind1 >= CHARACHIP_DOWN_1 && work.kind1 < CHARACHIP_DOWN_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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
			work.image.y += CharaSpeed;	//移動
			return TRUE; //移動できているのでTRUEを返す
		//}

		

		break;

	case RIGHT:

		

		//if (CHARA_COLLISION == FALSE) {
			if (work.kind1 >= CHARACHIP_RIGHT_1 && work.kind1 < CHARACHIP_RIGHT_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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
			work.image.x += CharaSpeed;	//移動

			return TRUE; //移動できているのでTRUEを返す
		//}

		

		break;

	case LEFT:

		

		//if (CHARA_COLLISION == FALSE) {
			if (work.kind1 >= CHARACHIP_LEFT_1 && work.kind1 < CHARACHIP_LEFT_3)
			{
				//画像変更カウンタ
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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
			work.image.x -= CharaSpeed;	//移動
			return TRUE; //移動できているのでTRUEを返す
		//}
		

		break;
	}

	//衝突がなければ、workから大本のキャラの情報に入れる。
	if (work.InRoom) {
		if (CHECK_COLLISION(work.coll, (MAP**)mapRoom[work.nowRoom].map) == FALSE) {
			chara = &work;
		}
	}
		


	//if (IsMove == false)
	//{
	//	chara->image.x -= CharaSpeed;//当たる前に戻る
	//	chara->image.y -= old_y;
	//}

	//if (IsMove == TRUE)
	//{

	//	{
	//		

	//		//あたっていないときの座標を取得
	//		chara->collBeforePt.x = chara->CenterX;
	//		chara->collBeforePt.y = chara->CenterY;
	//	}
	//}


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
