#include"DxLib.h"
#include"BGM.h"


VOID TITLE_BGM(VOID)
{
	if (CheckSoundMem(BGM_TITLE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_TITLE.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	if(()==TRUE)
		{
			if (CheckSoundMem(BGM_TITLE.GetHandle()) != 0)
			{
				StopSoundMem(BGM_TITLE.GetHandle());
			}
		}
	return;
}

VOID PLAY_BGM(VOID)
{
	if (CheckSoundMem(BGM_PLAY.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_PLAY.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	if (() == TRUE)
	{
		if (CheckSoundMem(BGM_PLAY.GetHandle()) != 0)
		{
			StopSoundMem(BGM_PLAY.GetHandle());
		}
	}
	return;
}

VOID COMP_BGM(VOID)
{
	if (CheckSoundMem(BGM_COMP.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_COMP.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	if (() == TRUE)
	{
		if (CheckSoundMem(BGM_COMP.GetHandle()) != 0)
		{
			StopSoundMem(BGM_COMP.GetHandle());
		}
	}
	return;
}

VOID END_BGM(VOID)
{
	if (CheckSoundMem(BGM_END.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_END.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	if (() == TRUE)
	{
		if (CheckSoundMem(BGM_END.GetHandle()) != 0)
		{
			StopSoundMem(BGM_END.GetHandle());
		}
	}
	return;
}

VOID SE_BGM(VOID)
{
	if (CheckSoundMem(BGM_SE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_SE.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	if (() == TRUE)
	{
		if (CheckSoundMem(BGM_SE.GetHandle()) != 0)
		{
			StopSoundMem(BGM_SE.GetHandle());
		}
	}
	return;
}