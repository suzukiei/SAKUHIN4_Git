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

//IMAGE�̓ǂݍ���
//BOOL MY_LOAD_GRAPH
//{
//	;
//}


//csv�̓ǂݍ���
BOOL MY_LOAD_CSV_MAP(VOID)
{
	//�}�b�v�`�b�v��ǂݍ���
	if (MY_LOAD_MAPCHIP() == FALSE) { return -1; }

	//csv��ǂݍ���
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_FLOOR)) { return -1; }	
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_WALL)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_BLOOD)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SBLOOD)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_ACCES)) { return -1; }
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_RECT)) { return -1; }

	return TRUE;
}


////�}�b�v�̖�����ݒ�
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
//		//�}�b�v�ʒu����
//		p->x = yoko * MAP_DIV_WIDTH;
//		p->y = tate * MAP_DIV_HEIGHT;
//		p->width = MAP_DIV_WIDTH;
//		p->height = MAP_DIV_HEIGHT;
//
//		//�}�b�v�̓����蔻��̏���
//		p->coll.left = p->x + 1;
//		p->coll.top = p->y + 1;
//		p->coll.right = p->coll.left + p->width - 1;
//		p->coll.bottom = p->coll.top + p->height - 1;
//
//		pInit = p;
//	}
//}