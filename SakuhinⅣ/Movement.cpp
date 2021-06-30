/*作品制作Ⅳ_冥闇の眼*/
#include "DxLib.h"
#include "movement.h"
#include "class.h"

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

	int old_x = chara->image.x;
	int old_y = chara->image.y;

	switch (move)
	{
	case UP:
		
		
		//if (CHARA_COLLISION() == FALSE) {
			if (chara->kind1 >= CHARACHIP_UP_1 && chara->kind1 < CHARACHIP_UP_3)
			{
				//画像変更カウンタ
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					chara->kind1++;			//次の画像にする
					chara->imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				chara->kind1 = CHARACHIP_UP_1;	//最初の画像にする
			}

			chara->image.y -= CharaSpeed;	//移動
			return TRUE; //移動できているのでTRUEを返す
			break;
		//}

	case DOWN:

	

		//if (CHARA_COLLISION == FALSE){
			if (chara->kind1 >= CHARACHIP_DOWN_1 && chara->kind1 < CHARACHIP_DOWN_3)
			{
				//画像変更カウンタ
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					chara->kind1++;			//次の画像にする
					chara->imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				chara->kind1 = CHARACHIP_DOWN_1;	//最初の画像にする
			}
			chara->image.y += CharaSpeed;	//移動
			return TRUE; //移動できているのでTRUEを返す
		//}

		

		break;

	case RIGHT:

		

		//if (CHARA_COLLISION == FALSE) {
			if (chara->kind1 >= CHARACHIP_RIGHT_1 && chara->kind1 < CHARACHIP_RIGHT_3)
			{
				//画像変更カウンタ
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					chara->kind1++;			//次の画像にする
					chara->imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				chara->kind1 = CHARACHIP_RIGHT_1;	//最初の画像にする
			}
			chara->image.x += CharaSpeed;	//移動

			return TRUE; //移動できているのでTRUEを返す
		//}

		

		break;

	case LEFT:

		

		//if (CHARA_COLLISION == FALSE) {
			if (chara->kind1 >= CHARACHIP_LEFT_1 && chara->kind1 < CHARACHIP_LEFT_3)
			{
				//画像変更カウンタ
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //画像を変えるタイミングになったら
				{
					chara->kind1++;			//次の画像にする
					chara->imgChangeCnt = 0;	//変更カウンタ初期化
				}
			}
			else
			{
				chara->kind1 = CHARACHIP_LEFT_1;	//最初の画像にする
			}
			chara->image.x -= CharaSpeed;	//移動
			return TRUE; //移動できているのでTRUEを返す
		//}
		

		break;
	}

	if (IsMove == false)
	{
		chara->image.x = old_x;//当たる前に戻る
		chara->image.y = old_y;
	}

	if (IsMove == TRUE)
	{

		{
			

			//あたっていないときの座標を取得
			chara->collBeforePt.x = chara->CenterX;
			chara->collBeforePt.y = chara->CenterY;
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
