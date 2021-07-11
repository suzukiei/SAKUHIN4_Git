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

RECT mapPassColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

BOOL MY_CHECK_RECT_COLL(RECT, RECT)	//領域の当たり判定をする関数
{
	return FALSE;
}

BOOL CHECK_COLLISION(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}

BOOL CHECK_COLLISION_EVENT(RECT p, RECT d)
{
	if (p.left == d.left &&
		p.top == d.top &&
		p.right == d.right &&
		p.bottom == d.bottom
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}

BOOL CHARA_COLLISION(RECT P,MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX])
{
	BOOL ret = FALSE;
	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーが部屋にいるとき
			if (player.InRoom == TRUE) {
				if (CHECK_COLLISION(P, mapColl[tate][yoko]) == TRUE)
				{
					//プレイヤーとマップが当たっている
					//MAP構造体のIsCollisionNoを返す
					if (ret == FALSE)ret = map[tate][yoko].IsCollisionNo;



				}
			}
			//プレイヤーが廊下にいるとき
			if (player.InPass == TRUE)
			{
				if (CHECK_COLLISION(P, mapPassColl[tate][yoko]) == TRUE)
				{
					//プレイヤーと廊下のマップが当たっている
					if (ret == FALSE)ret = map[tate][yoko].IsCollisionNo;
				}
			}
		}
	}

	return ret;
}

VOID CHECK_COLLISION_GOAL(VOID)
{
	
	
		if (player.InRoom == TRUE)
		{
			if (CHECK_COLLISION(player.coll, mapColl[mapRoom[player.nowRoom].GoalPt.y][mapRoom[player.nowRoom].GoalPt.x]))
			{
				player.InRoom = FALSE;
				player.InPass = TRUE;

				PLAY_PLAYER_INIT(START_POINT);
			}
		}
		else if (player.InPass == TRUE)
		{
			if (CHECK_COLLISION(player.coll, mapPassColl[mappass.GoalPt.y][mappass.GoalPt.x]))
			{
				player.InRoom = TRUE;
				player.nowRoom++;
				player.InPass = FALSE;

				PLAY_PLAYER_INIT(START_POINT);

			}
		}
	
}



VOID CHECK_COLLISION_BACK(VOID)
{
	if (player.InRoom == TRUE)
	{
		if (player.image.y + mapChip.height > MAP_HEIGHT_MAX * mapChip.height)
		{
			if (player.nowRoom != 0) {
				player.InRoom = FALSE;
				player.nowRoom--;
				player.InPass = TRUE;
				PLAY_PLAYER_INIT(GOAL_POINT);
			}
			else {
				MOVEMENT(&player,UP);
			}

			
		}
	}
	else if (player.InPass == TRUE)
	{
		if (player.image.y + mapChip.height > MAP_HEIGHT_MAX * mapChip.height)
		{
			player.InRoom = TRUE;		
			player.InPass = FALSE;

			PLAY_PLAYER_INIT(GOAL_POINT);

		}
	}
}


//VOID CHECK_COLLISION_ENEMY(VOID)
//{
//	//プレイヤーと敵の当たり判定の設定
//	player.coll.left = player.CenterX - 40 / 20 + 5;
//	player.coll.top = player.CenterY + 200 / 20 + 5;
//	player.coll.right = player.CenterX + 650 / 20 - 5;
//	player.coll.bottom = player.CenterY + 1000 / 20 - 5;
//
//	RECT PlayerRect;
//	PlayerRect.left = player.CenterX - 40 / 20 + 5;
//	PlayerRect.top = player.CenterY + 200 / 20 + 5;
//	PlayerRect.right = player.CenterX + 650 / 20 - 5;
//	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;
//
//	RECT EnemyRect;
//	EnemyRect.left = player.CenterX - 40 / 20 + 5;
//	EnemyRect.top = player.CenterY + 200 / 20 + 5;
//	EnemyRect.right = player.CenterX + 650 / 20 - 5;
//	EnemyRect.bottom = player.CenterY + 1000 / 20 - 5;
//
//	//ゴールに触れているかチェック
//	if (MY_CHECK_RECT_COLL(PlayerRect,EnemyRect) == TRUE)
//	{
//
//		GameScene = GAME_SCENE_END;//本当はゲームオーバ画面へ遷移したい。
//
//
//
//		return;	//強制的にエンド画面に飛ぶ
//	}
//}