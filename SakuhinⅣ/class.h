#include "define.h"
#include "image.h"

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
	int nowRoom;
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
	GAME_GIMMICK_KIND gimmick;

};

//マップ通路
class MAP_PASS
{
public:
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	int From;
	int To;

};

//マップ画像配列
class MAP_CHIP
{
public:
	MAPCHIP mapchip[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
};
