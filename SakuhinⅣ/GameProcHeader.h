#pragma once

#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"

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
	IMAGE image;
	int CenterX;                 //Warp�n�_X�ʒu
	int CenterY;                 //Warp�n�_Y�ʒu

	RECT coll;
}GIMMICK_OBJ;

VOID MY_FPS_UPDATE(VOID);
VOID MY_FPS_WAIT(VOID);

VOID START_PROC(VOID);
VOID RULE_PROC(VOID);
VOID PLAY_PROC(VOID);
VOID END_PROC(VOID);

VOID GIMMIK_OBJ_SET(int, int, GAME_MAP_KIND);

VOID GIMMIK(VOID);

VOID PLAY_PLAYER_INIT(VOID);
