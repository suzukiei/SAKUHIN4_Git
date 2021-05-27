#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "image.h"



//IMAGE_BACK ImageBack[IMAGE_BACK_NUM];

IMAGE ImageTitleBk;

//BOOL MY_LOAD_GRAPH
//{
//
//}

BOOL MY_LOAD_CSV_MAP(VOID)
{
	if (MY_LOAD_CSV_MAP(GAME_CSV_MAP_PATH)) { return -1; }

	return TRUE;
}
