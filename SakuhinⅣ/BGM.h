#pragma once

#include"DxLib.h"
#include"define.h"
#include"BGM.h"

class MUSIC
{
public:
	int x;
	int y;

public:
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
	VOID SetPath(const char* MusicPath)
	{
		strcpy_s(path, MusicPath);
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

VOID TITLE_BGM(VOID);
VOID PLAY_BGM(VOID);
VOID COMP_BGM(VOID);
VOID END_BGM(VOID);
VOID SE_BGM(VOID);

//BGM
extern MUSIC BGM_TITLE;
extern MUSIC BGM_PLAY;
extern MUSIC BGM_COMP;
extern MUSIC BGM_END;
extern MUSIC BGM_SE;
