#include"DxLib.h"
#include"BGM.h"
#include"enum.h"
#include"class.h"

VOID MY_TITLE_PROC(VOID)
{
	if (CheckSoundMem(BGM_TITLE.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_TITLE.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	return;
}

VOID MY_PLAY_PROC(VOID)
{
	if (CheckSoundMem(BGM_PLAY.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_PLAY.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	return;
}

VOID MY_END_PROC(VOID)
{
	if (CheckSoundMem(BGM_END.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_END.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	return;
}