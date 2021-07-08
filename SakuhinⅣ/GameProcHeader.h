#pragma once

#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"

#define GAME_GIMMICK_WARP_KIND 13

//--------経過時間カウントクラス--------
class TIME_COUNT
{
private:int TimeCou = 0;
private:BOOL CountFlag = false;

public:
	   //----カウント初期化----
	   VOID RESET(VOID)
	   {
		   TimeCou = 0;
		   return;
	   }
	   //----カウント開始----
	   VOID START(VOID)
	   {
		   CountFlag = TRUE;
		   return;
	   }
	   //----現在の経過時間----
	   int NOW(VOID)
	   {
		   return(TimeCou / GAME_FPS);
	   }
	   //----カウント停止----
	   VOID STOP(VOID)
	   {
		   CountFlag = FALSE;
		   return;
	   }
	   //----カウント---
	   VOID UPDATE(VOID)
	   {
		   if (CountFlag)TimeCou++;
		   return;
	   }
};

typedef struct STR_GIMMICK_OBJECT
{
	GAME_MAP_KIND kind;
	int x;
	int y;

	BOOL flag;

	RECT coll;

}GIMMICK_OBJ;

VOID MY_FPS_UPDATE(VOID);
VOID MY_FPS_WAIT(VOID);

VOID START_PROC(VOID);
VOID RULE_PROC(VOID);
VOID PLAY_PROC(VOID);
VOID END_PROC(VOID);

BOOL GIMMICK_OBJ_ISNULL(GIMMICK_OBJ);
VOID GIMMICK_OBJ_ALL_INIT();
VOID GIMMICK_OBJ_SET(int, int, GAME_MAP_KIND);
VOID GIMMICK_DRAW();

VOID GIMMICK(VOID);

VOID PLAY_PLAYER_INIT(VOID);
