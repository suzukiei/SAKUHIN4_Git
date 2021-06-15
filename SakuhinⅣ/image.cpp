#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "image.h"

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

MAP_ROOM mapRoom[8]; //マップ

MAP_PASS mappass;
//---------------------------------------------------画像の読み込み↓----------------------------------------------------------


//IMAGEの読み込み
BOOL MY_LOAD_IMAGE(VOID)
{
	//タイトル背景の読み込み
	ImageTitleBk.SetPath(IMAGE_TITLE_BK_PATH);
	ImageTitleBk.SetHandle(LoadGraph(ImageTitleBk.GetPath()) );
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
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//メニューボタン2の読み込み
	ButtonMenu2.SetPath(IMAGE_MENU_BUTTON_END_PATH);
	ButtonMenu2.SetHandle(LoadGraph(ButtonMenu1.GetPath()));
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

}


//csvの読み込み
BOOL MY_LOAD_CSV(VOID)
{
	//マップチップを読み込む
	if (MY_LOAD_MAPCHIP() == FALSE) { return -1; }

	//csvを読み込む
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_FLOOR)) { return -1; }	  //ステージ1床
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_WALL)) { return -1; }    //ステージ1壁
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_BLOOD)) { return -1; }   //ステージ1血
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SBLOOD)) { return -1; }  //ステージ1重ね血
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_ACCES)) { return -1; }   //ステージ1小物
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_RECT)) { return -1; }    //ステージ1当たり判定
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SG)) { return -1; }    //ステージ1スタートゴール
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_FLOOR)) { return -1; }	  //ステージ2床
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_WALL)) { return -1; }    //ステージ2壁
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_BLOOD)) { return -1; }   //ステージ2血
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SBLOOD)) { return -1; }  //ステージ2重ね血
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_ACCES)) { return -1; }   //ステージ2小物
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_RECT)) { return -1; }    //ステージ2当たり判定
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SG)) { return -1; }    //ステージ2スタートゴール


	return TRUE;
}

BOOL MY_LOAD_MAPCHIP()
{


	return TRUE;
}

//マップの読み込み
BOOL MY_LOAD_CSV_MAP(const char* path)
{
	//csvファイルを開く
	FILE* fp;
	
	//MAP_ROOM Room[8];

	if ((fp = fopen(path, "r")) == NULL) 
	{
		return FALSE;
	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		char buff[256];
		fgets(buff, 255, fp);
		for (int yoko = 0; yoko < MAP_WIDTH_MAX - 1; yoko++)
		{
			sscanf(buff, "%d,", mapRoom[0].map[tate][yoko].kind);
			//後x,y,WIDTH,HEIHGTを決める
		}
	}
	return TRUE;
}

//---------------------------------------------------画像描画↓----------------------------------------------------------

//スタート画面の描画処理
VOID START_DRAW(VOID)
{
	DrawGraph(0, 0, ImageTitleBk.GetHandle(), TRUE);
	DrawGraph(0, 0, ImageTitleRogo.GetHandle(), TRUE);
	DrawGraph(TITLE_BUTTON_PLAY_WIDTH_POSITION, TITLE_BUTTON_PLAY_HEIGHT_POSITION, ButtonPlay.GetHandle(), TRUE);
	DrawGraph(TITLE_BUTTON_LULE_TITLE_WIDTH_POSITION, TITLE_BUTTON_LULE_TITLE_HEIGHT_POSITION, ButtonRule.GetHandle(), TRUE);
	//DrawGraph(TITLE_BUTTON_END_WIDTH_POSITION, TITLE_BUTTON_END_HEIGHT_POSITION, ButtonEnd.GetHandle(), TRUE);

	return;
}

//ルール画面の描画処理
VOID RULE_DRAW(VOID)
{
	//DrawGraph(0, 0, , TRUE);

	return;
}

//プレイ画面の描画処理
VOID PLAY_DRAW(VOID)
{
	//マップの描画
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{

			DrawGraph(mapRoom[player.nowRoom].map[tate][yoko].x - player.CenterX,
				mapRoom[player.nowRoom].map[tate][yoko].y - player.CenterY,
				mapChip.handle[mapRoom[player.nowRoom].map[tate][yoko].kind],
				TRUE
			);
		}
	}

	//プレイヤー表示
	DrawGraph(
		player.CenterX,
		player.CenterY,
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

