#include "Dxlib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "movement.h"
#include "variable.h"

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

BOOL CHARA_COLLISION(RECT P,MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX])
{

	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (CHECK_COLLISION(P, mapColl[tate][yoko]) == TRUE)
			{
				//プレイヤーとマップが当たっている
				//MAP構造体のIsCollisionNoを返す
				return  map[tate][yoko].IsCollisionNo;

					

			}
		}
	}

	return FALSE;
}

VOID CHECK_COLLISION_GOAL(VOID)
{

	//ゴールに触れているかチェック
	//if (MY_CHECK_RECT_COLL(PlayerRect, /*GoalRect ゴールの判定*/) == TRUE)
	//{



	//	//スタートポイントに設定し遷移
	//	/*player.CenterX = startPt2.x;
	//	player.CenterY = startPt2.y;


	//	player.image.x = player.CenterX;
	//	player.image.y = player.CenterY;*/

	//	//GameScene = GAME_SCENE_PLAY2;



	//	return;	//強制的にエンド画面に飛ぶ
	//}
}


VOID CHECK_COLLISION_ENEMY(VOID)
{
	//プレイヤーと敵の当たり判定の設定
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

	RECT EnemyRect;
	EnemyRect.left = player.CenterX - 40 / 20 + 5;
	EnemyRect.top = player.CenterY + 200 / 20 + 5;
	EnemyRect.right = player.CenterX + 650 / 20 - 5;
	EnemyRect.bottom = player.CenterY + 1000 / 20 - 5;

	//ゴールに触れているかチェック
	if (MY_CHECK_RECT_COLL(PlayerRect,EnemyRect) == TRUE)
	{

		GameScene = GAME_SCENE_END;//本当はゲームオーバ画面へ遷移したい。



		return;	//強制的にエンド画面に飛ぶ
	}
}