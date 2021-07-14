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
vector<GIMMICK_OBJ> gimMove;
pair<GIMMICK_OBJ, GIMMICK_OBJ> gimWarp[GAME_GIMMICK_WARP_NUM];

GIMMICK_OBJ gimNull;

int StartTimeFps;
int CountFps;
float CalcFps;
int SampleNumFps = GAME_FPS;
BOOL canWarp = TRUE;
BOOL onMoveGimmick = FALSE;
MOVE nowMoveGimmickDir;

BOOL IsFirstTime = TRUE;
BOOL MoviePlayed = FALSE;
BOOL FirstTxetViewed = FALSE;

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
		FIRST_PLAYER_INIT();
		PLAY_PLAYER_INIT(START_POINT);
		TimeCounter.RESET();
		MoviePlayed = FALSE;
		FirstTxetViewed = FALSE;
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
	if (IsFirstTime)
	{
		if (MoviePlayed == FALSE)
		{
			MOVIE_DRAW();
			MoviePlayed = TRUE;
		}
		if (FirstTxetViewed == FALSE)
		{
			SET_TEXT_NUMBER(TEXT_OP);
			FirstTxetViewed = TRUE;
		}
	}

	if (player.InRoom)TimeCounter.START();
	if (player.InPass)TimeCounter.STOP();

	if(IsDrawText)TEXT_END_KEY();

	if (IsDrawText == FALSE) 
	{
		if (IsOpenMenu == FALSE)
		{
			if (onMoveGimmick == FALSE)
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
			}

			if (player.InRoom)
			{
				//敵の移動
				GIMMICK();
			}

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
	}

	//デバッグ用
	if (MY_KEY_UP(KEY_INPUT_Q))
	{
		GameScene = GAME_SCENE_END;
	}

	return;
}

VOID END_PROC(VOID)
{
	SET_TEXT_NUMBER(TEXT_END);
	GameScene = GAME_SCENE_START;
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
		if (!mapRoom[player.nowRoom].IsGimmickClear) {
			mapRoom[player.nowRoom].IsGimmickClear = TRUE;
			if (player.nowRoom == MAZE_ROOM)SET_TEXT_NUMBER(TEXT_STAGE2_START);
			if (player.nowRoom == NOTSEEMAZE_ROOM)SET_TEXT_NUMBER(TEXT_STAGE6_START);
		}
		break;
	}

	case GIMMICK_MINE:
	{
		if (!mapRoom[player.nowRoom].IsGimmickClear)
		{
			mapRoom[player.nowRoom].IsGimmickClear = TRUE;
			SET_TEXT_NUMBER(TEXT_STAGE4_START);
		}

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

		if (MY_KEY_UP(KEY_INPUT_RETURN))
		{
			for (int i = 0; i < (int)gimButton.size(); i++)
			{
				if (CHECK_COLLISION(target, gimButton[i].coll))
				{
					gimButton[i].flag = TRUE;
				}

				if (gimButton[i].flag)cou++;
			}
		}
		if (cou == (int)gimButton.size())
		{
			if (!mapRoom[player.nowRoom].IsGimmickClear)
			{
				mapRoom[player.nowRoom].IsGimmickClear = TRUE;
				SET_TEXT_NUMBER(TEXT_STAGE1_GMMICK_CLEAR);
			}
		}

		break;
	}

	case GIMMICK_PAZZLE:
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

		if (mapRoom[player.nowRoom].IsGimmickClear) 
		{
			mapRoom[player.nowRoom].IsGimmickClear = TRUE;
			SET_TEXT_NUMBER(TEXT_STAGE5_START);
		}

		for (int i = 0; i < GAME_GIMMICK_WARP_NUM; i++)
		{
			if (CHECK_COLLISION_JUSTCOL(player.coll, gimWarp[i].first.coll))
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
			else if (CHECK_COLLISION_JUSTCOL(player.coll, gimWarp[i].second.coll))
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
		BOOL flag = FALSE;
		mapRoom[player.nowRoom].IsGimmickClear = TRUE;


		if (CHARACHIP_DOWN_1 <= player.kind1 && player.kind1 <= CHARACHIP_DOWN_3)
		{
			nowMoveGimmickDir = DOWN;
		}
		if (CHARACHIP_LEFT_1 <= player.kind1 && player.kind1 <= CHARACHIP_LEFT_3)
		{
			nowMoveGimmickDir = LEFT;
		}
		if (CHARACHIP_RIGHT_1 <= player.kind1 && player.kind1 <= CHARACHIP_RIGHT_3)
		{
			nowMoveGimmickDir = RIGHT;
		}
		if (CHARACHIP_UP_1 <= player.kind1 && player.kind1 <= CHARACHIP_UP_3)
		{
			nowMoveGimmickDir = UP;
		}


		for (int i = 0; i < (int)gimMove.size(); i++)
		{
			if (CHECK_COLLISION_JUSTCOL(player.coll, gimMove[i].coll))
			{
				switch (gimMove[i].kind)
				{
				case MAP_BLOOD_ARROW_BACK:
					MOVEMENT(&player, DOWN);
					break;

				case MAP_BLOOD_ARROW_FRONT:
					MOVEMENT(&player, UP);
					break;

				case MAP_BLOOD_ARROW_LEFT:
					MOVEMENT(&player, LEFT);
					break;

				case MAP_BLOOD_ARROW_RIGHT:
					MOVEMENT(&player, RIGHT);
					break;
				}

				onMoveGimmick = TRUE;

				flag = TRUE;
			}
			else if (CHECK_COLLISION(player.coll, gimMove[i].coll))
			{
				switch (gimMove[i].kind)
				{
				case MAP_BLOOD_ARROW_BACK:
					if (nowMoveGimmickDir == UP || nowMoveGimmickDir == DOWN)
					{
						onMoveGimmick = TRUE;
						MOVEMENT(&player, DOWN);
					}
					break;

				case MAP_BLOOD_ARROW_FRONT:
					if (nowMoveGimmickDir == UP || nowMoveGimmickDir == DOWN)
					{
						onMoveGimmick = TRUE;
						MOVEMENT(&player, UP);
					}
					break;

				case MAP_BLOOD_ARROW_LEFT:
					if (nowMoveGimmickDir == RIGHT || nowMoveGimmickDir == LEFT)
					{
						onMoveGimmick = TRUE;
						MOVEMENT(&player, LEFT);
					}
					break;

				case MAP_BLOOD_ARROW_RIGHT:
					if (nowMoveGimmickDir == RIGHT || nowMoveGimmickDir == LEFT)
					{
						onMoveGimmick = TRUE;
						MOVEMENT(&player, RIGHT);
					}
					break;
				}

				flag = TRUE;
			}
		}

		if (!flag && onMoveGimmick)
		{
			onMoveGimmick = FALSE;
		}

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
		if (GIMMICK_OBJ_ISNULL(gimWarp[kind - WARP_1].first))
		{
			gimWarp[kind - WARP_1].first = work;
		}
		else
		{
			gimWarp[kind - WARP_1].second = work;
		}
	}
	if (WARP_8 <= kind && kind <= WARP_E)
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

	if (kind == MAP_BLOOD_ARROW_FRONT || kind == MAP_BLOOD_ARROW_BACK || kind == MAP_BLOOD_ARROW_LEFT || kind == MAP_BLOOD_ARROW_RIGHT)
	{
		gimMove.push_back(work);
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

	case GIMMICK_PAZZLE:
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
	case GIMMICK_PAZZLE:
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


			enemy.CenterX = mapRoom[player.nowRoom].StartPt.x * mapChip.width + (mapChip.width / 2);
			enemy.CenterY = mapRoom[player.nowRoom].StartPt.y * mapChip.height + (mapChip.height / 2);

			enemy.coll.left = mapRoom[player.nowRoom].StartPt.x * mapChip.width;
			enemy.coll.right = mapRoom[player.nowRoom].StartPt.x * mapChip.width + mapChip.width;
			enemy.coll.top = mapRoom[player.nowRoom].StartPt.y * mapChip.height;
			enemy.coll.bottom = mapRoom[player.nowRoom].StartPt.y * mapChip.height + mapChip.height;

			enemy.image.x = mapRoom[player.nowRoom].StartPt.x * mapChip.width;
			enemy.image.y = mapRoom[player.nowRoom].StartPt.y * mapChip.height;
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


			enemy.CenterX = mapRoom[player.nowRoom].GoalPt.x * mapChip.width + (mapChip.width / 2);
			enemy.CenterY = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + (mapChip.height / 2) + mapChip.height;

			enemy.coll.left = mapRoom[player.nowRoom].GoalPt.x * mapChip.width;
			enemy.coll.right = mapRoom[player.nowRoom].GoalPt.x * mapChip.width + mapChip.width;
			enemy.coll.top = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + mapChip.height;
			enemy.coll.bottom = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + mapChip.height + mapChip.height;

			enemy.image.x = mapRoom[player.nowRoom].GoalPt.x * mapChip.width;
			enemy.image.y = mapRoom[player.nowRoom].GoalPt.y * mapChip.height + mapChip.height;
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


VOID FIRST_PLAYER_INIT()
{
	player.CenterX = 0;
	player.CenterY = 0;
	player.nowRoom = LOADING();
	player.kind1 = CHARACHIP_UP_2;
	player.InPass = FALSE;
	player.InRoom = TRUE;

	if (player.nowRoom != -1)
	{
		player.InPass = TRUE;
		player.InRoom = FALSE;
	}
	else
	{
		player.nowRoom = 0;
	}

	enemy.CenterX = 0;
	enemy.CenterY = 0;
	enemy.nowRoom = player.nowRoom;
	enemy.kind1 = CHARACHIP_UP_2;
	enemy.InPass = FALSE;
	enemy.InRoom = TRUE;

	return;
}
