#pragma once

#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"

#define GAME_GIMMICK_WARP_NUM 14

//--------�o�ߎ��ԃJ�E���g�N���X--------
class TIME_COUNT
{
private:int TimeCou = 0;
private:BOOL CountFlag = false;

public:
	   //----�J�E���g������----
	   VOID RESET(VOID)
	   {
		   TimeCou = 0;
		   return;
	   }
	   //----�J�E���g�J�n----
	   VOID START(VOID)
	   {
		   CountFlag = TRUE;
		   return;
	   }
	   //----���݂̌o�ߎ���----
	   int NOW(VOID)
	   {
		   return(TimeCou / GAME_FPS);
	   }
	   //----�J�E���g��~----
	   VOID STOP(VOID)
	   {
		   CountFlag = FALSE;
		   return;
	   }
	   //----�J�E���g---
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

enum FIRST_POINT
{
	START_POINT,
	GOAL_POINT
};

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
BOOL CHECK_COLLISION_GIMMICK(RECT);
VOID GIMMICK(VOID);

VOID PLAY_PLAYER_INIT(FIRST_POINT);
VOID FIRST_PLAYER_INIT();

extern TIME_COUNT TimeCounter;

enum GIMMIK_ROOM_TABLE
{
	BUTTON_ROOM,
	MAZE_ROOM,
	MOVE_ROOM,
	MINE_ROOM,
	WARP_ROOM,
	NOTSEEMAZE_ROOM,
	PAZZLE_ROOM
};
