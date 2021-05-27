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
