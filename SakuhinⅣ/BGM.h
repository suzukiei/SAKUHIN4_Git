#include "define.h"
//BGM
BGM BGM_TITLE;
BGM BGM_PLAY;
BGM BGM_COMP;
BGM BGM_END;
BGM BGM_SE;

//âπê∫
class MUSIC
{
public:
	char path[PATH_MAX];
	int handle;
	int handle2;
};