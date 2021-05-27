#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "movement.h"

using namespace std;

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

VOID ENEMY_MOVE(VOID)
{
	int workx = player.CenterX - enemy.CenterX;
	int worky = player.CenterY - enemy.CenterY;

	BOOL moved = FALSE;

	if (workx > 0)
	{
		moved =  MOVEMENT(&enemy, RIGHT);
	}
	if (workx < 0 && !moved)
	{
		MOVEMENT(&enemy, LEFT);
	}
	if (worky > 0 && !moved)
	{
		MOVEMENT(&enemy, DOWN);
	}
	if(worky < 0 && !moved)
	{
		MOVEMENT(&enemy, UP);
	}

	return;
}
