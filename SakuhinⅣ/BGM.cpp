#include "DxLib.h"
#include "BGM.h"
#include "class.h"
#include "define.h"
#include "enum.h"
#include "flag.h"
#include "GameProcHeader.h"
#include "image.h"
#include "menu.h"
#include "movement.h"
#include "textevent.h"
#include "title.h"
#include "variable.h"
#include "resource.h"

MUSIC BGM_TITLE;
MUSIC BGM_PLAY;
//MUSIC BGM_COMP;
MUSIC BGM_END;
MUSIC BGM_SE;
MUSIC BGM_SE_OPEN;
MUSIC BGM_SE_MENU;

VOID TITLE_BGM(VOID)
{
	//もしBGMが流れていないなら流す
	if (CheckSoundMem(BGM_TITLE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_TITLE.GetHandle(), DX_PLAYTYPE_LOOP);
	}

	//もしBGM_PLAYが流れていたら止める
	if (CheckSoundMem(BGM_PLAY.GetHandle() != 0))
	{
		StopSoundMem(BGM_PLAY.GetHandle());
	}
	//もしBGM_COMPが流れていたら止める
	//if (CheckSoundMem(BGM_COMP.GetHandle() != 0))
	//{
	//	StopSoundMem(BGM_COMP.GetHandle());
	//}
	//もしBGM_ENDが流れていたら止める
	if (CheckSoundMem(BGM_END.GetHandle() != 0))
	{
		StopSoundMem(BGM_END.GetHandle());
	}

	return;
}

VOID PLAY_BGM(VOID)
{
	if (TimeCounter.NOW() > GAME_TIME_LIMIT) {
		if (CheckSoundMem(BGM_PLAY.GetHandle()) == 0)
		{
			PlaySoundMem(BGM_PLAY.GetHandle(), DX_PLAYTYPE_LOOP);
		}
	}

	//タイトルBGMが流れていたら止める
	if (CheckSoundMem(BGM_TITLE.GetHandle() != 0))
	{
		StopSoundMem(BGM_TITLE.GetHandle());
	}

	return;
}

VOID END_BGM(VOID)
{
	//もしBGM_PLAYが流れていたら止める
	if (CheckSoundMem(BGM_PLAY.GetHandle() != 0))
	{
		StopSoundMem(BGM_PLAY.GetHandle());
	}

	switch (GameEndkind)
	{
	//case GAME_END_COMP:
	//	if (CheckSoundMem(BGM_COMP.GetHandle()) == 0)
	//	{
	//		PlaySoundMem(BGM_COMP.GetHandle(), DX_PLAYTYPE_LOOP);
	//	}
	//	break;

	case GAME_END_FAIL:
		if (CheckSoundMem(BGM_END.GetHandle()) == 0)
		{
			PlaySoundMem(BGM_END.GetHandle(), DX_PLAYTYPE_LOOP);
		}
	}
	return;
}

VOID SE_BGM(VOID)
{
	if (CheckSoundMem(BGM_SE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_SE.GetHandle(), DX_PLAYTYPE_BACK);
	}

	return;
}

VOID SE_OPEN_BGM(VOID)
{
	if (CheckSoundMem(BGM_SE_OPEN.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_SE_OPEN.GetHandle(), DX_PLAYTYPE_BACK);
	}

	return;
}

VOID SE_MENU_BGM(VOID)
{
	if (CheckSoundMem(BGM_SE_MENU.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_SE_MENU.GetHandle(), DX_PLAYTYPE_BACK);
	}

	return;
}

//BGM読み込み処理
BOOL MY_LOAD_MUSIC(VOID)
{
	BGM_TITLE.SetPath(MUSIC_BGM_PATH_TITLE);
	BGM_TITLE.SetHandle(LoadSoundMem(BGM_TITLE.GetPath()));
	if (BGM_TITLE.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH_TITLE, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}


	BGM_PLAY.SetPath(MUSIC_BGM_PATH);
	BGM_PLAY.SetHandle(LoadSoundMem(BGM_PLAY.GetPath()));
	if (BGM_PLAY.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	//BGM_COMP.SetPath(MUSIC_BGM_COMP_PATH);
	//BGM_COMP.SetHandle(LoadSoundMem(BGM_COMP.GetPath()));
	//if (BGM_COMP.GetHandle() == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return(FALSE);
	//}

	BGM_END.SetPath(MUSIC_BGM_FAIL_PATH);
	BGM_END.SetHandle(LoadSoundMem(BGM_END.GetPath()));
	if (BGM_END.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_FAIL_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_SE.SetPath(MUSIC_BGM_SE_PATH);
	BGM_SE.SetHandle(LoadSoundMem(BGM_SE.GetPath()));
	if (BGM_SE.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_SE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_SE_OPEN.SetPath(MUSIC_BGM_SE_OPEN_PATH);
	BGM_SE_OPEN.SetHandle(LoadSoundMem(BGM_SE_OPEN.GetPath()));
	if (BGM_SE_OPEN.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_SE_OPEN_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_SE_MENU.SetPath(MUSIC_BGM_SE_MENU_PATH);
	BGM_SE_MENU.SetHandle(LoadSoundMem(BGM_SE_MENU.GetPath()));
	if (BGM_SE_MENU.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_SE_MENU_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	//正常終了するためのTRUE
	return TRUE;
}

//BGM削除処理
BOOL MY_DELETE_MUSIC(VOID)
{
	BGM_TITLE.DeleteHandle();
	BGM_PLAY.DeleteHandle();
	//BGM_COMP.DeleteHandle();
	BGM_END.DeleteHandle();
	BGM_SE.DeleteHandle();
	BGM_SE_OPEN.DeleteHandle();
	BGM_SE_MENU.DeleteHandle();

	//正常終了するためのTRUE
	return TRUE;
}