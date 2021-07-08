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

vector<GIMMICK_OBJ> gimButton;
vector<GIMMICK_OBJ> gimMine;
vector<GIMMICK_OBJ> gimPazzle;
pair<GIMMICK_OBJ, GIMMICK_OBJ> gimWarp[GAME_GIMMICK_WARP_KIND];

GIMMICK_OBJ gimNull;

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
	GIMMICK();
	MENU();

	//デバッグ用
	if (MY_KEY_UP(KEY_INPUT_Q))
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

VOID GIMMICK(VOID)
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

VOID GIMMICK_OBJ_ALL_INIT()
{
	gimNull.coll = { -1,-1,-1,-1};
	gimNull.x = -1;
	gimNull.y = -1;
	gimNull.flag = FALSE;
	gimNull.kind = (GAME_MAP_KIND)-1;

	gimButton.clear();
	gimMine.clear();
	gimPazzle.clear();
	for (int i = 0; i < GAME_GIMMICK_WARP_KIND; i++)
	{
		gimWarp[i].first = gimNull;
		gimWarp[i].second = gimNull;
	}

	return;
}

BOOL GIMMICK_OBJ_ISNULL(GIMMICK_OBJ obj)
{
	BOOL ret = TRUE;

	if (obj.coll.left != gimNull.coll.left)ret = FALSE;
	if (obj.coll.top != gimNull.coll.top)ret = FALSE;
	if (obj.coll.right != gimNull.coll.right)ret = FALSE;
	if (obj.coll.bottom != gimNull.coll.bottom)ret = FALSE;
	if (obj.flag != gimNull.flag)ret = FALSE;
	if (obj.kind != gimNull.kind)ret = FALSE;
	if (obj.x != gimNull.x)ret = FALSE;
	if (obj.y != gimNull.y)ret = FALSE;

	return ret;
}

VOID GIMMICK_OBJ_SET(int obj_x, int obj_y, GAME_MAP_KIND kind)
{
	GIMMICK_OBJ work;

	work.kind = kind;
	work.x = obj_x * mapChip.width;
	work.y = obj_y * mapChip.height;
	work.flag = FALSE;
	work.coll.left = obj_x * mapChip.width;
	work.coll.top = obj_y * mapChip.height;
	work.coll.right = obj_x * mapChip.width + mapChip.width;
	work.coll.bottom = obj_y * mapChip.height + mapChip.height;

	switch (kind)
	{
	case GIMMICK_BUTTON:
		gimButton.push_back(work);
		break;

	case GIMMICK_MINE:
		gimMine.push_back(work);
		break;

	case GIMMICK_PAZLE:
		gimPazzle.push_back(work);
		break;

	case GIMMICK_WARP:

		if (WARP_1 <= kind && kind <= WARP_7)
		{
			if (GIMMICK_OBJ_ISNULL(gimWarp[kind - WARP_1].first))
			{
				gimWarp[kind - WARP_1].first = work;
			}
			else
			{
				gimWarp[kind - WARP_1].second = work;
			}
		}
		if (WARP_8 <= kind && kind <= WARP_D)
		{
			if (GIMMICK_OBJ_ISNULL(gimWarp[(kind - WARP_8) + (WARP_7 - WARP_1 + 1)].first))
			{
				gimWarp[(kind - WARP_8) + (WARP_7 - WARP_1 + 1)].first = work;
			}
			else
			{
				gimWarp[(kind - WARP_8) + (WARP_7 - WARP_1 + 1)].second = work;
			}
		}

		break;
	}

	return;
}

VOID GIMMICK_DRAW()
{
	switch (mapRoom[player.nowRoom].gimmick)
	{
	case GIMMICK_MINE:
		for (int i = 0; i < (int)gimMine.size(); i++)
		{
			DrawGraph(gimMine[i].x - player.image.x - (player.image.x - (GAME_WIDTH / 2)),
				gimMine[i].y - player.image.y - (player.image.y - (GAME_HEIGHT / 2)),
				mapChip.handle[gimMine[i].kind],
				TRUE);
		}
		break;

	case GIMMICK_BUTTON:
		for (int i = 0; i < (int)gimButton.size(); i++)
		{
			DrawGraph(gimButton[i].x - player.image.x - (player.image.x - (GAME_WIDTH / 2)),
				gimButton[i].y - player.image.y - (player.image.y - (GAME_HEIGHT / 2)),
				mapChip.handle[gimButton[i].kind],
				TRUE);
		}
		break;

	case GIMMICK_PAZLE:
		for (int i = 0; i < (int)gimPazzle.size(); i++)
		{
			DrawGraph(gimPazzle[i].x - player.image.x - (player.image.x - (GAME_WIDTH / 2)),
				gimPazzle[i].y - player.image.y - (player.image.y - (GAME_HEIGHT / 2)),
				mapChip.handle[gimPazzle[i].kind],
				TRUE);
		}
		break;
	}

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
