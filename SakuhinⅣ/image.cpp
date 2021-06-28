#define _CRT_SECURE_NO_WARNINGS

#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "image.h"

#include<stdio.h>

#define ERR ("")

MAPCHIP mapChip;

IMAGE ImageTitleBk;
IMAGE ImageTitleRogo;
IMAGE ImageEndBk;
IMAGE ImageEndComp;
IMAGE ImageEndFail;
IMAGE ImageRule;
IMAGE ImageMenu;
IMAGE ButtonPlay;
IMAGE ButtonEnd;
IMAGE ButtonRule;
IMAGE ButtonNow;
IMAGE ButtonMenu1;
IMAGE ButtonMenu2;


//MAP_CHIP mapChipRoom[8];  //ルームマップチップ
//MAP_CHIP mapChipPass;  //通路マップチップ

CHARA charaChip;

MAP_ROOM mapRoom[8]; //マップ

MAP_PASS mappass;
//---------------------------------------------------画像の読み込み↓----------------------------------------------------------


//IMAGEの読み込み
BOOL MY_LOAD_IMAGE(VOID)
{
	//タイトル背景の読み込み
	ImageTitleBk.SetPath(IMAGE_TITLE_BK_PATH);
	ImageTitleBk.SetHandle(LoadGraph(ImageTitleBk.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//タイトルロゴの読み込み
	ImageTitleRogo.SetPath(IMAGE_TITLE_ROGO_PATH);
	ImageTitleRogo.SetHandle(LoadGraph(ImageTitleRogo.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//ルール背景の読み込み
	ImageRule.SetPath(IMAGE_RULE_PATH);
	ImageRule.SetHandle(LoadGraph(ImageRule.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_RULE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//メニューの読み込み
	ImageMenu.SetPath(IMAGE_MENU_PATH);
	ImageMenu.SetHandle(LoadGraph(ImageMenu.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	////エンド背景の読み込み
	//ImageEndBk.SetPath(IMAGE_END_BK_PATH);
	//ImageEndBk.SetHandle(LoadGraph(ImageEndBk.GetPath()));
	//if (ImageEndBk.GetPath() == ERR)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_END_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	////エンド成功の読み込み
	ImageEndComp.SetPath(IMAGE_END_COMP_PATH);
	ImageEndComp.SetHandle(LoadGraph(ImageEndComp.GetPath()));
	if (ImageEndComp.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	////エンド失敗の読み込み
	ImageEndFail.SetPath(IMAGE_END_FAIL_PATH);
	ImageEndFail.SetHandle(LoadGraph(ImageEndFail.GetPath()));
	if (ImageEndFail.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_FAIL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//プレイ画面へ遷移するためのボタンの読み込み
	ButtonPlay.SetPath(IMAGE_TITLE_BUTTON_PLAY_PATH);
	ButtonPlay.SetHandle(LoadGraph(ButtonPlay.GetPath()));
	if (ButtonPlay.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_PLAY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//エンド画面へ遷移するためのボタンの読み込み
	ButtonEnd.SetPath(IMAGE_TITLE_BUTTON_END_PATH);
	ButtonEnd.SetHandle(LoadGraph(ButtonEnd.GetPath()));
	if (ButtonEnd.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//ルール画面へ遷移するためのボタンの読み込み
	ButtonRule.SetPath(IMAGE_TITLE_BUTTON_RULE_PATH);
	ButtonRule.SetHandle(LoadGraph(ButtonRule.GetPath()));
	if (ButtonRule.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_RULE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//ボタン選択画像の読み込み
	ButtonNow.SetPath(IMAGE_TITLE_BUTTON_NOW_PATH);
	ButtonNow.SetHandle(LoadGraph(ButtonNow.GetPath()));
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_NOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//ボタン選択画像の読み込み
	ButtonNow.SetPath(IMAGE_TITLE_BUTTON_NOW_PATH);
	ButtonNow.SetHandle(LoadGraph(ButtonNow.GetPath()));
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_NOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//メニューボタン１の読み込み
	ButtonMenu1.SetPath(IMAGE_MENU_BUTTON_PATH);
	ButtonMenu1.SetHandle(LoadGraph(ButtonMenu1.GetPath()));
	if (ButtonMenu1.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//メニューボタン2の読み込み
	ButtonMenu2.SetPath(IMAGE_MENU_BUTTON_END_PATH);
	ButtonMenu2.SetHandle(LoadGraph(ButtonMenu1.GetPath()));
	if (ButtonMenu2.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//プレイヤーの読み込み
	int charaChip = LoadDivGraph(
		IMAGE_PLAYER_PATH,
		PLAYER_DIV_NUM, PLAYER_DIV_YOKO, PLAYER_DIV_TATE,
		PLAYER_WIDTH, PLAYER_HEIGHT,
		player.handle);

	//if (charaChip == ERR) {
	//	MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	//マップチップの読み込み

	if (MY_LOAD_MAPCHIP() == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}



	//csvの読み込み

	//-----------------------------ステージ１----------------------------------------------
	//床
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_FLOOR, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}
	//壁
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_WALL, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}
	//小物
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_ACCES, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}
	//血
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_BLOOD, &mapRoom[0], LAYER_MAP_MIDDLE) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}
	//重ね血
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SBLOOD, &mapRoom[0], LAYER_MAP_TOP) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}
	////当たり判定
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_RECT, &mapRoom[0], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}
	////スタートゴール
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SG, &mapRoom[0], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}
	//ギミック
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_GIMMICK, &mapRoom[0], GIMMICK_BUTTON) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
		return -1;
	}

	//-----------------------------ステージ2----------------------------------------------
	////床
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_FLOOR, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
	//	return -1;
	//}
	////壁
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_WALL, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
	//	return -1;
	//}
	////小物
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_ACCES, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
	//	return -1;
	//}
	////血
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_BLOOD, &mapRoom[0], LAYER_MAP_MIDDLE) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
	//	return -1;
	//}
	////重ね血
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SBLOOD, &mapRoom[0], LAYER_MAP_TOP) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
	//	return -1;
	//}
	//////当たり判定
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_RECT, &mapRoom[0], LAYER_MAP_RECT) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
	//	return -1;
	//}
	//////スタートゴール
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SG, &mapRoom[0], LAYER_MAP_SG) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "えらー", "えらー", MB_OK);
	//	return -1;
	//}


	return TRUE;
}


//csvの読み込み
BOOL MY_LOAD_CSV(VOID)
{
	//マップチップを読み込む
	if (MY_LOAD_MAPCHIP() == FALSE) { return -1; }

	return TRUE;
}

BOOL MY_LOAD_MAPCHIP()
{
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,
		mapChip.handle);

	if (mapRes == -1)
	{
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);
	//mapChip.width = MAP
	return TRUE;
}

/// <summary>
/// マップの読み込み
/// </summary>
/// <param name="room">階層の構造体のポインタ</param>
/// <param name="path">マップのパス</param>
/// <returns></returns>
BOOL MY_LOAD_CSV_MAP(const char* path,MAP_ROOM* room,int Layer)
{
	FILE* fp;

	errno_t error;
	int result = 0;			//ファイルの最後かチェック
	int LoopCnt = 0;        //ループカウンタ

	//csvファイルを開く
	error = fopen_s(&fp, path, "r");
	if (error != 0)
	{
		MessageBox(GetMainWindowHandle(), path, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	else
	{
		result = 0;
		LoopCnt = 0;

		while (result != EOF)    //End Of File（ファイルの最後）ではないとき繰り返す
		{
			GAME_MAP_KIND mapData;
			
			if (Layer == LAYER_MAP_UNDER || Layer == LAYER_MAP_MIDDLE || Layer == LAYER_MAP_TOP)
			{
				mapData = room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind;

				//ファイルから数値を一つ読み込み(%d,)、配列に格納する
				result = fscanf(fp, "%d,", &room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind);

				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].width = mapChip.width;
				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].height = mapChip.height;

				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x = LoopCnt % MAP_WIDTH_MAX * mapChip.width;
				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y = LoopCnt / MAP_WIDTH_MAX * mapChip.height;

				if (room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind == -1)
				{
					room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind = mapData;
				}
			}
			
			//ギミック
			else if (Layer == LAYER_MAP_GIMMICK)
			{
				result = fscanf(fp, "%d,", &mapData);
			}
			//スタートゴール
			else if (Layer == LAYER_MAP_SG)
			{
				result = fscanf(fp, "%d,", &mapData);
			}
			//当たり判定
			else if (Layer == LAYER_MAP_RECT)
			{
				result = fscanf(fp, "%d,", &mapData);
			}
			LoopCnt++;
		}

		fclose(fp);
	}

	return TRUE;
}

//---------------------------------------------------画像描画↓----------------------------------------------------------
//スタート画面の描画処理
VOID START_DRAW(VOID)
{
	DrawGraph(0, 0, ImageTitleBk.GetHandle(), TRUE);
	DrawGraph(IMAGE_TITLE_ROGO_WIDTH_POSITION, IMAGE_TITLE_ROGO_HEIGHT_POSITION, ImageTitleRogo.GetHandle(), TRUE);
	DrawGraph(TITLE_BUTTON_PLAY_WIDTH_POSITION, TITLE_BUTTON_PLAY_HEIGHT_POSITION, ButtonPlay.GetHandle(), TRUE);
	DrawGraph(TITLE_BUTTON_LULE_TITLE_WIDTH_POSITION, TITLE_BUTTON_LULE_TITLE_HEIGHT_POSITION, ButtonRule.GetHandle(), TRUE);
	DrawGraph(TITLE_BUTTON_END_WIDTH_POSITION, TITLE_BUTTON_END_HEIGHT_POSITION, ButtonEnd.GetHandle(), TRUE);

	return;
}

//ルール画面の描画処理
VOID RULE_DRAW(VOID)
{
	DrawGraph(0, 0, ImageRule.GetHandle(), TRUE);

	return;
}

//プレイ画面の描画処理
VOID PLAY_DRAW(VOID)
{
	player.nowRoom = 0;
	//マップの描画
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			if (mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].kind != -1)
			{
				//床のレイヤー
				DrawGraph
				(
					mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].x,
					mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].y,
					mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].kind],
					TRUE
				);
			}
			if(mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].kind != -1)
			{ 
			//血のレイヤー
			DrawGraph
			(
				mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].x,
				mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].y,
				mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].kind],
				TRUE
			);
			}

			if (mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].kind != -1)
			{
				//重ね血のレイヤー
				DrawGraph
				(
					mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].x,
					mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].y,
					mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].kind],
					TRUE
				);
			}

			if (mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].kind != -1)
			{
				//ギミックのレイヤー？
				DrawGraph
				(
					mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].x,
					mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].y,
					mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].kind],
					TRUE
				);
			}

		}
	}

	//プレイヤー表示
	DrawGraph(
		player.CenterX ,
		player.CenterY ,
		player.handle[player.kind1],
		TRUE
	);

	return;
}

//エンド画面の描画処理
VOID END_DRAW(VOID)
{
	//DrawGraph(0, 0, ImageEndBk.GetHandle(), TRUE); //エンド背景

	switch (GameEndkind)
	{
	case GAME_END_COMP: //成功画面
		DrawGraph(0, 0, ImageEndComp.GetHandle(), TRUE);
		break;

	case GAME_END_FAIL: //失敗画面
		DrawGraph(0, 0, ImageEndFail.GetHandle(), TRUE);
		break;

	default:
		break;
	}

	return;
}



//----------------------------------------------------画像の削除↓-----------------------------------------------------------

//画像の削除
VOID MY_DELETE_IMAGE(VOID)
{
	ImageTitleBk.DeleteHandle();
	ImageTitleRogo.DeleteHandle();
	ImageEndBk.DeleteHandle();
	ImageEndComp.DeleteHandle();
	ImageEndFail.DeleteHandle();
	ImageRule.DeleteHandle();
	ImageMenu.DeleteHandle();
	ButtonPlay.DeleteHandle();
	ButtonEnd.DeleteHandle();
	ButtonRule.DeleteHandle();
	ButtonNow.DeleteHandle();
	ButtonMenu1.DeleteHandle();
	ButtonMenu2.DeleteHandle();
}

