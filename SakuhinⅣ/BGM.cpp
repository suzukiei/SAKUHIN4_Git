#include"DxLib.h"
#include"BGM.h"

MUSIC BGM_TITLE;
MUSIC BGM_PLAY;
MUSIC BGM_COMP;
MUSIC BGM_END;
MUSIC BGM_SE;

VOID TITLE_BGM(VOID)
{
	if (CheckSoundMem(BGM_TITLE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_TITLE.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	//if(()==TRUE)
	//	{
	//		if (CheckSoundMem(BGM_TITLE.GetHandle()) != 0)
	//		{
	//			StopSoundMem(BGM_TITLE.GetHandle());
	//		}
	//	}
	return;
}

VOID PLAY_BGM(VOID)
{
	if (CheckSoundMem(BGM_PLAY.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_PLAY.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	//if (() == TRUE)
	//{
	//	if (CheckSoundMem(BGM_PLAY.GetHandle()) != 0)
	//	{
	//		StopSoundMem(BGM_PLAY.GetHandle());
	//	}
	//}
	return;
}

VOID COMP_BGM(VOID)
{
	if (CheckSoundMem(BGM_COMP.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_COMP.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	//if (() == TRUE)
	//{
	//	if (CheckSoundMem(BGM_COMP.GetHandle()) != 0)
	//	{
	//		StopSoundMem(BGM_COMP.GetHandle());
	//	}
	//}
	return;
}

VOID END_BGM(VOID)
{
	if (CheckSoundMem(BGM_END.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_END.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	//if (() == TRUE)
	//{
	//	if (CheckSoundMem(BGM_END.GetHandle()) != 0)
	//	{
	//		StopSoundMem(BGM_END.GetHandle());
	//	}
	//}
	return;
}

VOID SE_BGM(VOID)
{
	if (CheckSoundMem(BGM_SE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_SE.GetHandle(), DX_PLAYTYPE_LOOP);
	}
	//if (() == TRUE)
	//{
	//	if (CheckSoundMem(BGM_SE.GetHandle()) != 0)
	//	{
	//		StopSoundMem(BGM_SE.GetHandle());
	//	}
	//}
	return;
}

//BGM読み込み処理
BOOL MY_LOAD_MUSIC(VOID)
{
	//BGM_TITLE.SetPath(MUSIC_BGM_PATH_TITLE);
	//BGM_TITLE.SetHandle = LoadSoundMem(BGM_TITLE.SetPath);
	//if (BGM_TITLE.SethHandle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH_TITLE, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return(FALSE);
	//}


	//BGM_PLAY.SetPath(MUSIC_BGM_PATH);
	//	BGM_PLAY.SetHandle = LoadSoundMem(BGM_PLAY.SetPath);
	//if (BGM_PLAY.SethHandle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return(FALSE);
	//}

	//BGM_COMP.SetPath(MUSIC_BGM_COMP_PATH);
	//	BGM_COMP.SetHandle = LoadSoundMem(BGM_COMP.SetPath);
	//if (BGM_COMP.SethHandle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return(FALSE);
	//}

	//BGM_END.SetPath(MUSIC_BGM_FAIL_PATH);
	//	BGM_END.SetHandle = LoadSoundMem(BGM_END.SetPath);
	//if (BGM_END.SethHandle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_FAIL_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return(FALSE);
	//}

	//BGM_SE.SetPath(MUSIC_BGM_SE_PATH);
	//BGM_SE.SetHandle = LoadSoundMem(BGM_SE.SetPath);
	//if (BGM_SE.SethHandle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_SE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return(FALSE);
	//}

	//ダミー
	return TRUE;
}

//BGM削除処理
BOOL MY_DELETE_MUSIC(VOID)
{
	//DeleteSoundMem(BGM_TITLE.MusicHandle);
	//DeleteSoundMem(BGM_PLAY.MusicHandle);
	//DeleteSoundMem(BGM_COMP.MusicHandle);
	//DeleteSoundMem(BGM_END.MusicHandle);
	//DeleteSoundMem(BGM_SE.MusicHandle);

	//ダミー
	return TRUE;
}