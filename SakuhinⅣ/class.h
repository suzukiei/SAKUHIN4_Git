#include "define.h"

//�摜
class IMAGE
{
public:
	char path[PATH_MAX];
	int handle;
	int x;
	int y;
	int width;
	int height;
};

//�^�C�g���w�i
class IMAGE_BACK : IMAGE
{
public:
	BOOL IsDraw;

};

//����
class MUSIC
{
public:
	char path[PATH_MAX];
	int handle;
	int handle2;
};

//�v���C���[
class CHARA
{
public:
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;
	int kind1;
	int imgChangeCnt;
	int imgChangeCntMAX;
	BOOL IsMoveNaname;

	RECT coll;
	IPOINT collBeforePt;
};

//�}�b�v�����i�M�~�b�N�j
class MAP_ROOM
{
public:

};

//�}�b�v�ʘH
class MAP_PASS
{
public:

};
