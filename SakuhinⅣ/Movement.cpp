/*作品制作Ⅳ_冥闇の眼*/
#include "DxLib.h"
#include "movement.h"



VOID MOVEMENT(VOID)
{
	/*

	BOOL IsMove = TRUE; //移動可能


	//上に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE
		&& IsMove == TRUE)
	{
		//player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = U_1;	//最初の画像にする
		}

		player.image.y -= CharaSpeed;	//移動
	}

	//右に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE
		&& IsMove == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = R_1;	//最初の画像にする
		}
		player.image.x += CharaSpeed;	//移動
	}

	//左に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE
		&& IsMove == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = L_1;	//最初の画像にする
		}
		player.image.x -= CharaSpeed;	//移動
	}

	//下に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE
		&& IsMove == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = D_1;	//最初の画像にする
		}
		player.image.y += CharaSpeed;	//移動
	}
	*/

	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
	   //ここにメニュー表示の関数を制作する。
		IsMove = FALSE;

		MENU();

	}


}
	

//キーを押し上げたか、キーコードで判断する
extern BOOL MY_KEY_UP(int KEY_INPUT_)
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
extern BOOL MY_KEY_DOWN(int KEY_INPUT_)
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
extern VOID MY_ALL_KEYDOWN_UPDATE(VOID)
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
