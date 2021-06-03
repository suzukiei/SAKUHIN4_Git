#include "Dxlib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "movement.h"

BOOL CHARA_COLLISION(CHARA a, CHARA b)
{
	if (a.coll.left < b.coll.right &&
		a.coll.top < b.coll.bottom &&
		a.coll.right > b.coll.left &&
		a.coll.bottom > b.coll.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}

BOOL CHECK_COLLISION(CHARA P)
{

	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			//if (CHARA_COLLISION(P, mapColl[tate][yoko]) == TRUE)
			//{


			//	//プレイヤーとマップが当たっている
			//	if (mapdata3[tate][yoko] == d) { return TRUE; }
			//	if (mapdata3[tate][yoko] == B) { return TRUE; }
			//	if (mapdata2[tate][yoko] == t) { return TRUE; }
			//	if (mapdata2[tate][yoko] == s) { return TRUE; }
			//	if (mapdata2[tate][yoko] == g) { return TRUE; }

			//}
		}
	}

	return FALSE;
}