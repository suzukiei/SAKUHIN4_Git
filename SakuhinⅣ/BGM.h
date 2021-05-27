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