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

#include <vector>

using namespace std;

vector<GIMMICK_OBJ> gimMain;
vector<GIMMICK_OBJ> gimBox;
vector<pair<GIMMICK_OBJ, GIMMICK_OBJ>> gimWarp;

int StartTimeFps;
int CountFps;
float CalcFps;
int SampleNumFps = GAME_FPS;

TIME_COUNT TimeCounter;

VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0)
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps)
	{
		int now = GetNowCount();

		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	TimeCounter.UPDATE();

	return;
}

VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;

	if (waitTime > 0)
	{
		WaitTimer(waitTime);
	}
	return;
}

VOID START_PROC(VOID)
{
	TITLE();
	if (GameScene == GAME_SCENE_PLAY)
	{
		PLAY_PLAYER_INIT();
	}
	/*デバッグ用
	if (MY_KEY_UP(KEY_INPUT_SPACE))
	{
		GameScene = GAME_SCENE_RULE;
	}
	if (MY_KEY_UP(KEY_INPUT_RETURN))
	{
		GameScene = GAME_SCENE_PLAY;

		PLAY_PLAYER_INIT();
	}*/

	return;
}

VOID RULE_PROC(VOID)
{
	//デバッグ用
	if (MY_KEY_UP(KEY_INPUT_RETURN))
	{
		GameScene = GAME_SCENE_START;
	}

	return;
}

VOID PLAY_PROC(VOID)
{
	GIMMIK();

	//デバッグ用
	if (MY_KEY_UP(KEY_INPUT_ESCAPE))
	{
		GameScene = GAME_SCENE_END;
	}

	return;
}

VOID END_PROC(VOID)
{
	//デバッグ用
	if (MY_KEY_UP(KEY_INPUT_RETURN))
	{
		GameScene = GAME_SCENE_START;
	}
	return;
}

VOID GIMMIK(VOID)
{
	if (MY_KEY_DOWN(KEY_INPUT_W))
	{
		MOVEMENT((CHARA*)&player, UP);
	}
	else if (MY_KEY_DOWN(KEY_INPUT_S))
	{
		MOVEMENT((CHARA*)&player, DOWN);
	}
	else if (MY_KEY_DOWN(KEY_INPUT_A))
	{
		MOVEMENT((CHARA*)&player, LEFT);
	}
	else if (MY_KEY_DOWN(KEY_INPUT_D))
	{
		MOVEMENT((CHARA*)&player, RIGHT);
	}

	switch (mapRoom[player.nowRoom].gimmick)
	{
	case GIMMICK_MAZE:
		break;

	case GIMMICK_MINE:
		break;

	case GIMMICK_BUTTON:
		break;

	case GIMMICK_PAZLE:
		break;
	}

	return;
}

VOID GIMMIK_OBJ_SET(int obj_x, int obj_y, GAME_MAP_KIND kind)
{
	return;
}

VOID PLAY_PLAYER_INIT(VOID)
{
	player.CenterX = mapRoom[player.nowRoom].StartPt.x * mapChip.width + (mapChip.width / 2);
	player.CenterY = mapRoom[player.nowRoom].StartPt.y * mapChip.height + (mapChip.height / 2);

	player.coll.left = mapRoom[player.nowRoom].StartPt.x * mapChip.width;
	player.coll.right = mapRoom[player.nowRoom].StartPt.x * mapChip.width + mapChip.width;
	player.coll.top = mapRoom[player.nowRoom].StartPt.y * mapChip.height;
	player.coll.bottom = mapRoom[player.nowRoom].StartPt.y * mapChip.height + mapChip.height;

	player.image.x = mapRoom[player.nowRoom].StartPt.x * mapChip.width;
	player.image.y = mapRoom[player.nowRoom].StartPt.y * mapChip.height;

	return;
}
