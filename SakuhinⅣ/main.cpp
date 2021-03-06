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
#include "resource.h"

//ゲーム本体
VOID GameMain(VOID);
//画面遷移
VOID GameSceneMove(VOID);
//各画面
VOID MY_START(VOID);
VOID MY_RULE(VOID);
VOID MY_PLAY(VOID);
VOID MY_END(VOID);
//初期化
VOID MY_INIT(VOID);

int GameScene = GAME_SCENE_START; //ゲームシーン

int GameEndkind;  //エンド画面

BOOL GameLoop = TRUE;	//ゲーム繰り返し

CHARA player;   //プレイヤー
CHARA enemy;   //エネミー

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//--------------------------------初期設定設定---------------------------------
	ChangeWindowMode(TRUE);	
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_COLOR);
	SetWindowStyleMode(GAME_WINDOW_BAR);
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));

	SetWindowIconID(IDI_ICON1);

	MY_INIT();

	if (DxLib_Init() == -1) { return(-1); }
	if (MY_LOAD_IMAGE() == -1) { return(-1); }
	if (MY_LOAD_MUSIC() == -1) { return(-1); }

	SetMouseDispFlag(FALSE);

	SetDrawScreen(DX_SCREEN_BACK);


	//--------------------------------ゲームループ---------------------------------
	while (GameLoop)
	{
		if (ProcessMessage() != 0) { break; }

		if (ClearDrawScreen() != 0) { break; }

		MY_ALL_KEYDOWN_UPDATE();

		//MY_MOUSE_UPDATE();

		MY_FPS_UPDATE();

		GameMain();

		ScreenFlip();

		MY_FPS_WAIT();
	}
	ScreenFlip();

	//--------------------------------終了処理---------------------------------


	MY_DELETE_IMAGE();
	MY_DELETE_MUSIC();

	DxLib_End();

	return 0;
}

void GameMain(void)
{
	GameSceneMove();
	return;
}

void GameSceneMove(void)
{
	switch (GameScene)
	{
	case GAME_SCENE_START:
		MY_START();
		break;
	case GAME_SCENE_PLAY:
		MY_PLAY();
		break;
	case GAME_SCENE_END:
		MY_END();
		break;
	case GAME_SCENE_RULE:
		MY_RULE();
		break;
	}

	return;
}

VOID MY_START(VOID)
{
	START_PROC();
	START_DRAW();
	TITLE_BGM();
	return;
}

VOID MY_RULE(VOID)
{
	RULE_PROC();
	RULE_DRAW();
	return;
}

VOID MY_PLAY(VOID)
{
	PLAY_PROC();
	PLAY_DRAW();
	if (IsOpenMenu)MENU_DRAW();
	PLAY_BGM();
	return;
}

VOID MY_END(VOID)
{
	END_PROC();
	END_DRAW();
	END_BGM();
	return;
}

VOID MY_INIT(VOID)
{
	//マップの初期化
	for (int room = 0; room < ROOM_NUM; room++)
	{
		for (int layer = 0; layer < LAYER_MAP_DRAWKIND; layer++)
		{
			for (int y = 0; y < MAP_HEIGHT_MAX; y++)
			{
				for (int x = 0; x < MAP_WIDTH_MAX; x++)
				{
					mapRoom[room].map[y][x].kind[LAYER_MAP_UNDER] = (GAME_MAP_KIND)-1;
					mapRoom[room].map[y][x].kind[LAYER_MAP_MIDDLE] = (GAME_MAP_KIND)-1;
					mapRoom[room].map[y][x].kind[LAYER_MAP_TOP] = (GAME_MAP_KIND)-1;
					mapRoom[room].map[y][x].x = -1;
					mapRoom[room].map[y][x].y = -1;
					mapRoom[room].map[y][x].width = -1;
					mapRoom[room].map[y][x].height = -1;
					mapRoom[room].map[y][x].IsCollisionNo = FALSE;
				}
			}
		}
		mapRoom[room].IsGimmickClear = FALSE;
		mapRoom[room].IsTimeAdd = FALSE;
	}

	for (int y = 0; y < MAP_HEIGHT_MAX; y++)
	{
		for (int x = 0; x < MAP_WIDTH_MAX; x++)
		{
			mappass.map[y][x].kind[LAYER_MAP_UNDER] = (GAME_MAP_KIND)-1;
			mappass.map[y][x].kind[LAYER_MAP_MIDDLE] = (GAME_MAP_KIND)-1;
			mappass.map[y][x].kind[LAYER_MAP_TOP] = (GAME_MAP_KIND)-1;
			mappass.map[y][x].x = -1;
			mappass.map[y][x].y = -1;
			mappass.map[y][x].width = -1;
			mappass.map[y][x].height = -1;
			mappass.map[y][x].IsCollisionNo = FALSE;
		}
	}

	//キャラの初期化
	player.CenterX = 0;
	player.CenterY = 0;
	player.nowRoom = -1;
	player.kind1 = CHARACHIP_UP_2;
	player.InPass = FALSE;
	player.InRoom = TRUE;
	player.CharaMoveCnt = 0;

	if (player.nowRoom != 0)
	{
		player.InPass = TRUE;
		player.InRoom = FALSE;
	}

	enemy.CenterX = 0;
	enemy.CenterY = 0;
	enemy.nowRoom = -1;
	enemy.kind1 = CHARACHIP_UP_2;
	enemy.InPass = FALSE;
	enemy.InRoom = TRUE;
	enemy.CharaMoveCnt = 0;

	return;
}
