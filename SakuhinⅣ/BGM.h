#include "define.h"
#include "Dxlib.h"

//BGM
MUSIC BGM_TITLE;
MUSIC BGM_PLAY;
MUSIC BGM_COMP;
MUSIC BGM_END;
MUSIC BGM_SE;

class MUSIC
{
public:
	int x;
	int y;

private:
	int MusicHandle;
	char path[PATH_MAX];

public:
	VOID SetHandle(int Date)
	{
		MusicHandle = Date;
		return;
	}
	VOID DeleteHandle(VOID)
	{
		DeleteMusicMem(MusicHandle);
		return;
	}
	VOID SetPath(char MusicPath[])
	{
		strcpy(MusicPath, MusicPath);
		return;
	}
	int GetHandle(VOID)
	{
		return(MusicHandle);
	}
	char* GetPath(VOID)
	{
		return(path);
	}
};

BOOL MY_LOAD_MUSIC(VOID);
BOOL MY_DELETE_MUSIC(VOID);

//BGMì«Ç›çûÇ›èàóù
BOOL MY_LOAD_MUSIC(VOID)
{
	BGM_TITLE.SetPath(MUSIC_BGM_TITLE_PATH);
	BGM_TITLE.SetHandle = LoadSoundMem(BGM_TITLE.SetPath);
	if (BGM_TITLE.SethHandle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_TITLE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}


	BGM_PLAY.SetPath(MUSIC_BGM_PLAY_PATH)
		BGM_PLAY.SetHandle = LoadSoundMem(BGM_PLAY.SetPath);
	if (BGM_PLAY.SethHandle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PLAY_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_COMP.SetPath(MUSIC_BGM_COMP_PATH)
		BGM_COMP.SetHandle = LoadSoundMem(BGM_COMP.SetPath);
	if (BGM_COMP.SethHandle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_END.SetPath(MUSIC_BGM_END_PATH)
		BGM_END.SetHandle = LoadSoundMem(BGM_END.SetPath);
	if (BGM_END.SethHandle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_END_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	return TRUE;
}

//BGMçÌèúèàóù
BOOL MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM_TITLE.MusicHandle);
	DeleteSoundMem(BGM_PLAY.MusicHandle);
	DeleteSoundMem(BGM_COMP.MusicHandle);
	DeleteSoundMem(BGM_END.MusicHandle);
	DeleteSoundMem(BGM_SE.MusicHandle);

	return;
}