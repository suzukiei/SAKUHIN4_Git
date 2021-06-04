#include "DxLib.h"
#include "BGM.h"
#include "class.h"
#include "define.h"
#include "enum.h"
#include "flag.h"
#include "GameProcHeader.h"
#include "menu.h"
#include "movement.h"
#include "textevent.h"
#include "title.h"
#include "variable.h"

int StartTimeFps;
int CountFps;
float CalcFps;
int SampleNumFps = GAME_FPS;

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
	return;
}

VOID RULE_PROC(VOID)
{
	return;
}

VOID PLAY_PROC(VOID)
{
	GIMMIK();
	return;
}

VOID END_PROC(VOID)
{
	return;
}

VOID GIMMIK(VOID)
{
	if (MY_KEY_DOWN(KEY_INPUT_W))
	{
		MOVEMENT(&player, UP);
	}
	else if (MY_KEY_DOWN(KEY_INPUT_S))
	{
		MOVEMENT(&player, DOWN);
	}
	else if (MY_KEY_DOWN(KEY_INPUT_A))
	{
		MOVEMENT(&player, LEFT);
	}
	else if (MY_KEY_DOWN(KEY_INPUT_D))
	{
		MOVEMENT(&player, RIGHT);
	}
}
