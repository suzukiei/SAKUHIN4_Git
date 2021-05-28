#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "image.h"

MAPCHIP mapChip;


//IMAGE_BACK ImageBack[IMAGE_BACK_NUM];

IMAGE ImageTitleBk;
IMAGE ImageEndBk;

//IMAGEの読み込み
//BOOL MY_LOAD_GRAPH
//{
//	;
//}


//csvの読み込み
BOOL MY_LOAD_CSV_MAP(VOID)
{
	//マップチップを読み込む
	if (MY_LOAD_MAPCHIP() == FALSE) { return -1; }

	//csvを読み込む
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_FLOOR)) { return -1; }	
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_WALL)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_BLOOD)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SBLOOD)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_ACCES)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_RECT)) { return -1; }

	return TRUE;
}


////マップの役割を設定
//for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++) {
//	for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++) {
//		MAP* p = m + tate * GAME_MAP_YOKO_MAX + yoko;
//		MAP* pInit = mInit + tate * GAME_MAP_YOKO_MAX + yoko;
//
//		p->kind = MAP_KIND_TURO;
//
//		for (int cnt = 0; cnt < MAP_JIMEN_KIND; cnt++) {
//			if (p->value == MapJimenID[cnt]) {
//				p->kind = MAP_KIND_KABE;
//				break;
//			}
//		}
//
//		for (int cnt = 0; cnt < MAP_GUILD_KIND; cnt++) {
//			if (p->value == MapGuildID[cnt]) {
//				p->kind = MAP_KIND_GUILD;
//				break;
//			}
//		}
//
//		if (p->value == MapKanbanID)
//		{
//			p->kind = MAP_KIND_KANBAN;
//		}
//
//		//マップ位置処理
//		p->x = yoko * MAP_DIV_WIDTH;
//		p->y = tate * MAP_DIV_HEIGHT;
//		p->width = MAP_DIV_WIDTH;
//		p->height = MAP_DIV_HEIGHT;
//
//		//マップの当たり判定の処理
//		p->coll.left = p->x + 1;
//		p->coll.top = p->y + 1;
//		p->coll.right = p->coll.left + p->width - 1;
//		p->coll.bottom = p->coll.top + p->height - 1;
//
//		pInit = p;
//	}
//}