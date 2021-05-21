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