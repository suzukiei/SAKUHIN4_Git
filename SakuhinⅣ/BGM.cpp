#include"DxLib.h"
#include"BGM.h"
#include"enum.h"
#include"class.h"

VOID TITLE_BGM(VOID)
{
	if (CheckSoundMem(BGM_TITLE.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_TITLE.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	if(()==TRUE)
		{
			if (CheckSoundMem(BGM_TITLE.handle) != 0)
			{
				StopSoundMem(BGM_TITLE.handle);
			}
		}
	return;
}

VOID PLAY_BGM(VOID)
{
	if (CheckSoundMem(BGM_PLAY.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_PLAY.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	return;
}

VOID COMP_BGM(VOID)
{
	if (CheckSoundMem(BGM_COMP.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_COMP.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	return;
}

VOID END_BGM(VOID)
{
	if (CheckSoundMem(BGM_END.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_END.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	return;
}

VOID SE_BGM(VOID)
{
	if (CheckSoundMem(BGM_SE.MusicHandle) == 0)
	{
		PlaySoundMem(BGM_SE.MusicHandle, DX_PLAYTYPE_LOOP);
	}
	return;
}