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
public:
	BOOL IsDraw;

};

//音声
class MUSIC
{
public:
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
	BOOL IsMoveNaname;

	RECT coll;
	IPOINT collBeforePt;
};

//マップ部屋（ギミック）
class MAP_ROOM
{
public:

};

//マップ通路
class MAP_PASS
{
public:

};
