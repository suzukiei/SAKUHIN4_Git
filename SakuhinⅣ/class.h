#include "define.h"

//画像
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

//タイトル背景
class IMAGE_BACK : IMAGE
{
	BOOL IsDraw;

};

//音声
class MUSIC
{
	char path[PATH_MAX];
	int handle;
	int handle2;
};

//プレイヤー
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
	BOOL InRoom = false;
	BOOL InPass = false;
	BOOL IsMoveNaname;

	RECT coll;
	IPOINT collBeforePt;
};

//マップ部屋（ギミック）
class MAP_ROOM
{
public:
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

};

//マップ通路
class MAP_PASS
{
public:
	int From;
	int To;

};



