/*作品制作Ⅳ_冥闇の眼*/
#include "DxLib.h"
#include "movement.h"
#include "class.h"

BOOL MOVEMENT(CHARA* chara,int move)
{

	BOOL IsMove = TRUE; //移動可能
	CHARA work = *chara;

	switch (move)
	{
	case UP:
		chara->IsMoveNaname = FALSE;	//斜め移動していない
		
		//if (CHARA_COLLISION() == FALSE) {
			if (chara->kind1 >= U_1 && chara->kind1 < U_4)
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
				chara->kind1 = U_1;	//最初の画像にする
			}

			chara->image.y -= CharaSpeed;	//移動

			break;
		//}

	case DOWN:

		chara->IsMoveNaname = FALSE;	//斜め移動していない

		if (CHARA_COLLISION == FALSE)
		{
			if (chara->kind1 >= D_1 && chara->kind1 < D_4)
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
				chara->kind1 = D_1;	//最初の画像にする
			}
			chara->image.y += CharaSpeed;	//移動
		}
		break;

	case RIGHT:

		chara->IsMoveNaname = FALSE;	//斜め移動していない

		if (CHARA_COLLISION == FALSE) {
			if (chara->kind1 >= R_1 && chara->kind1 < R_4)
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
				chara->kind1 = R_1;	//最初の画像にする
			}
			chara->image.x += CharaSpeed;	//移動
		}
		break;

	case LEFT:

		chara->IsMoveNaname = FALSE;	//斜め移動していない

		if (CHARA_COLLISION == FALSE) {
			if (chara->kind1 >= L_1 && chara->kind1 < L_4)
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
				chara->kind1 = L_1;	//最初の画像にする
			}
			chara->image.x -= CharaSpeed;	//移動
		}

		break;
	}



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
