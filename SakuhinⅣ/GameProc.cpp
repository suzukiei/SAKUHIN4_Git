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
pair<GIMMICK_OBJ, GIMMICK_OBJ> gimWarp[GAME_GIMMICK_WARP_NUM];

GIMMICK_OBJ gimNull;

int StartTimeFps;
int CountFps;
float CalcFps;
int SampleNumFps = GAME_FPS;
BOOL canWarp = TRUE;

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
		PLAY_PLAYER_INIT(START_POINT);
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
	if (IsOpenMenu == FALSE)
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

		GIMMICK();

		CHECK_COLLISION_BACK();
		if (mapRoom[player.nowRoom].IsGimmickClear)
		{
			CHECK_COLLISION_GOAL();
		}
	}

	if (MY_KEY_UP(KEY_INPUT_ESCAPE))
	{
		IsOpenMenu = TRUE;
	}

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
	switch (mapRoom[player.nowRoom].gimmick)
	{

	case GIMMICK_MAZE:
	{
		mapRoom[player.nowRoom].IsGimmickClear = TRUE;
		break;
	}

	case GIMMICK_MINE:
	{
		mapRoom[player.nowRoom].IsGimmickClear = TRUE;

		for (int i = 0; i < (int)gimMine.size(); i++)
		{
			if (CHECK_COLLISION(player.coll, gimMine[i].coll))
			{
				GameScene = GAME_SCENE_END;
				GameEndkind = GAME_END_FAIL;
			}
		}
		break;
	}

	case GIMMICK_BUTTON:
	{
		RECT target = player.coll;
		int cou = 0;

		if (CHARACHIP_DOWN_1 <= player.kind1 && player.kind1 <= CHARACHIP_DOWN_3)
		{
			target.top += CharaSpeed;
			target.bottom += CharaSpeed;
		}
		if (CHARACHIP_LEFT_1 <= player.kind1 && player.kind1 <= CHARACHIP_LEFT_3)
		{
			target.left -= CharaSpeed;
			target.right -= CharaSpeed;
		}
		if (CHARACHIP_RIGHT_1 <= player.kind1 && player.kind1 <= CHARACHIP_RIGHT_3)
		{
			target.left += CharaSpeed;
			target.right += CharaSpeed;
		}
		if (CHARACHIP_UP_1 <= player.kind1 && player.kind1 <= CHARACHIP_UP_3)
		{
			target.top -= CharaSpeed;
			target.bottom -= CharaSpeed;
		}

		if (MY_KEY_DOWN(KEY_INPUT_RETURN))
		{
			for (int i = 0; i < (int)gimButton.size(); i++)
			{
				if (CHECK_COLLISION(target, gimButton[i].coll))
				{
					cou++;
				}
			}
		}
		if (cou == (int)gimButton.size())
		{
			mapRoom[player.nowRoom].IsGimmickClear = TRUE;
		}

		break;
	}

	case GIMMICK_PAZLE:
	{
		RECT target = player.coll;
		RECT work;

		if (CHARACHIP_DOWN_1 <= player.kind1 && player.kind1 <= CHARACHIP_DOWN_3)
		{
			target.top += mapChip.height;
			target.bottom += mapChip.height;
		}
		if (CHARACHIP_LEFT_1 <= player.kind1 && player.kind1 <= CHARACHIP_LEFT_3)
		{
			target.left -= mapChip.width;
			target.right -= mapChip.width;
		}
		if (CHARACHIP_RIGHT_1 <= player.kind1 && player.kind1 <= CHARACHIP_RIGHT_3)
		{
			target.left += mapChip.width;
			target.right += mapChip.width;
		}
		if (CHARACHIP_UP_1 <= player.kind1 && player.kind1 <= CHARACHIP_UP_3)
		{
			target.top -= mapChip.height;
			target.bottom -= mapChip.height;
		}

		for (int i = 0; i < (int)gimPazzle.size(); i++)
		{
			work = gimPazzle[i].coll;

			if (CHARACHIP_DOWN_1 <= player.kind1 && player.kind1 <= CHARACHIP_DOWN_3)
			{
				work.top += mapChip.height;
				work.bottom += mapChip.height;
			}
			if (CHARACHIP_LEFT_1 <= player.kind1 && player.kind1 <= CHARACHIP_LEFT_3)
			{
				work.left -= mapChip.width;
				work.right -= mapChip.width;
			}
			if (CHARACHIP_RIGHT_1 <= player.kind1 && player.kind1 <= CHARACHIP_RIGHT_3)
			{
				work.left += mapChip.width;
				work.right += mapChip.width;
			}
			if (CHARACHIP_UP_1 <= player.kind1 && player.kind1 <= CHARACHIP_UP_3)
			{
				work.top -= mapChip.height;
				work.bottom -= mapChip.height;
			}

			if (MY_KEY_DOWN(KEY_INPUT_RETURN))
			{
				if (CHECK_COLLISION_JUSTCOL(target, gimPazzle[i].coll) &&
					!CHARA_COLLISION(work, mapRoom[player.nowRoom].map) &&
					!CHECK_COLLISION_GIMMICK(work) &&
					work.bottom < mapChip.height * MAP_HEIGHT_MAX &&
					work.top > mapChip.height)
				{
					gimPazzle[i].coll = work;
					gimPazzle[i].x = gimPazzle[i].coll.left;
					gimPazzle[i].y = gimPazzle[i].coll.top;
				}
			}
		}

		break;
	}

	case GIMMICK_WARP:
	{
		int cou = 0;

		mapRoom[player.nowRoom].IsGimmickClear = TRUE;

		for (int i = 0; i < GAME_GIMMICK_WARP_NUM; i++)
		{
			if (CHECK_COLLISION(player.coll, gimWarp[i].first.coll))
			{
				if (canWarp)
				{
					player.image.x = gimWarp[i].second.x;
					player.image.y = gimWarp[i].second.y;
					player.CenterX = gimWarp[i].second.x + (mapChip.width / 2);
					player.CenterY = gimWarp[i].second.y + (mapChip.height / 2);
					player.coll = gimWarp[i].second.coll;

					canWarp = FALSE;
				}
				break;
			}
			else if (CHECK_COLLISION(player.coll, gimWarp[i].second.coll))
			{
				if (canWarp)
				{
					player.image.x = gimWarp[i].first.x;
					player.image.y = gimWarp[i].first.y;
					player.CenterX = gimWarp[i].first.x + (mapChip.width / 2);
					player.CenterY = gimWarp[i].first.y + (mapChip.height / 2);
					player.coll = gimWarp[i].first.coll;

					canWarp = FALSE;
				}
				break;
			}
			else
			{
				cou++;
			}
		}
		if (cou == GAME_GIMMICK_WARP_NUM)
		{
			canWarp = TRUE;
		}

		break;
	}

	case GIMMICK_MOVE:
	{
		mapRoom[player.nowRoom].IsGimmickClear = TRUE;
		break;
	}

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
	for (int i = 0; i < GAME_GIMMICK_WARP_NUM; i++)
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

	if (kind == MAP_DOLL)
	{
		work.kind = MAP_CARDBOARD;
		gimButton.push_back(work);
	}
	
	if (kind == MAP_MINE)
	{
		gimMine.push_back(work);
	}

	if (kind == MAP_CARDBOARD)
	{
		gimPazzle.push_back(work);
	}

	if (WARP_1 <= kind && kind <= WARP_7)
	{
		work.coll.top++;
		work.coll.left++;
		work.coll.right--;
		work.coll.bottom--;

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
		work.coll.top++;
		work.coll.left++;
		work.coll.right--;
		work.coll.bottom--;

		if (GIMMICK_OBJ_ISNULL(gimWarp[(kind - WARP_8) + (WARP_7 - WARP_1 + 1)].first))
		{
			gimWarp[(kind - WARP_8) + (WARP_7 - WARP_1 + 1)].first = work;
		}
		else
		{
			gimWarp[(kind - WARP_8) + (WARP_7 - WARP_1 + 1)].second = work;
		}
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
			DrawGraph(gimMine[i].x - (player.image.x - (GAME_WIDTH / 2)),
				gimMine[i].y - (player.image.y - (GAME_HEIGHT / 2)),
				mapChip.handle[gimMine[i].kind],
				TRUE);
		}
		break;

	case GIMMICK_BUTTON:
		for (int i = 0; i < (int)gimButton.size(); i++)
		{
			DrawGraph(gimButton[i].x - (player.image.x - (GAME_WIDTH / 2)),
				gimButton[i].y - (player.image.y - (GAME_HEIGHT / 2)),
				mapChip.handle[gimButton[i].kind],
				TRUE);
		}
		break;

	case GIMMICK_PAZLE:
		for (int i = 0; i < (int)gimPazzle.size(); i++)
		{
			DrawGraph(gimPazzle[i].x - (player.image.x - (GAME_WIDTH / 2)),
				gimPazzle[i].y - (player.image.y - (GAME_HEIGHT / 2)),
				mapChip.handle[gimPazzle[i].kind],
				TRUE);
		}
		break;
	}

	return;
}

VOID PLAY_PLAYER_INIT(FIRST_POINT point)
{
	switch (point)
	{
	case START_POINT:
		if (player.InRoom)
		{
			player.CenterX = mapRoom[player.nowRoom].StartPt.x * mapChip.width + (mapChip.width / 2);
			player.CenterY = mapRoom[player.nowRoom].StartPt.y * mapChip.height + (mapChip.height / 2);

			player.coll.left = mapRoom[player.nowRoom].StartPt.x * mapChip.width;
			player.coll.right = mapRoom[player.nowRoom].StartPt.x * mapChip.width + mapChip.width;
			player.coll.top = mapRoom[player.nowRoom].StartPt.y * mapChip.height;
			player.coll.bottom = mapRoom[player.nowRoom].StartPt.y * mapChip.height + mapChip.height;

			player.image.x = mapRoom[player.nowRoom].StartPt.x * mapChip.width;
			player.image.y = mapRoom[player.nowRoom].StartPt.y * mapChip.height;
		}
		else if (player.InPass)
		{
			player.CenterX = mappass.StartPt.x * mapChip.width + (mapChip.width / 2);
			player.CenterY = mappass.StartPt.y * mapChip.height + (mapChip.height / 2);

			player.coll.left = mappass.StartPt.x * mapChip.width;
			player.coll.right = mappass.StartPt.x * mapChip.width + mapChip.width;
			player.coll.top = mappass.StartPt.y * mapChip.height;
			player.coll.bottom = mappass.StartPt.y * mapChip.height + mapChip.height;

			player.image.x = mappass.StartPt.x * mapChip.width;
			player.image.y = mappass.StartPt.y * mapChip.height;
		}
		break;

	case GOAL_POINT:
		if (player.InRoom)
		{
			player.CenterX = mapRoom[player.nowRoom].GoalPt.x * mapChip.width + (mapChip.width / 2);
			player.CenterY = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + (mapChip.height / 2) + mapChip.height;

			player.coll.left = mapRoom[player.nowRoom].GoalPt.x * mapChip.width;
			player.coll.right = mapRoom[player.nowRoom].GoalPt.x * mapChip.width + mapChip.width;
			player.coll.top = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + mapChip.height;
			player.coll.bottom = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + mapChip.height + mapChip.height;

			player.image.x = mapRoom[player.nowRoom].GoalPt.x * mapChip.width;
			player.image.y = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + mapChip.height;
		}
		else if (player.InPass)
		{
			player.CenterX = mappass.GoalPt.x * mapChip.width + (mapChip.width / 2);
			player.CenterY = mappass.GoalPt.y * mapChip.height + (mapChip.height / 2) + mapChip.height;

			player.coll.left = mappass.GoalPt.x * mapChip.width;
			player.coll.right = mappass.GoalPt.x * mapChip.width + mapChip.width;
			player.coll.top = mappass.GoalPt.y * mapChip.height + mapChip.height;
			player.coll.bottom = mappass.GoalPt.y * mapChip.height + mapChip.height + mapChip.height;

			player.image.x = mappass.GoalPt.x * mapChip.width;
			player.image.y = mappass.GoalPt.y * mapChip.height + mapChip.height;
		}

		break;
	}

	return;
}

BOOL CHECK_COLLISION_GIMMICK(RECT r)
{
	BOOL ret = FALSE;

	switch (mapRoom[player.nowRoom].gimmick)
	{

	case GIMMICK_BUTTON:
	{
		for (int i = 0; i < (int)gimButton.size(); i++)
		{
			if (CHECK_COLLISION(r, gimButton[i].coll))
			{
				ret = TRUE;
			}
		}

		break;
	}
	case GIMMICK_PAZLE:
	{
		for (int i = 0; i < (int)gimPazzle.size(); i++)
		{
			if (CHECK_COLLISION(r, gimPazzle[i].coll))
			{
				ret = TRUE;
			}
		}
		break;
	}

	}

	return(ret);
}
