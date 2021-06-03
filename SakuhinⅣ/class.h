#include "define.h"
#include "image.h"

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
	int nowRoom;
	BOOL InRoom = false;
	BOOL InPass = false;
	BOOL IsMoveNaname;

	RECT coll;
	IPOINT collBeforePt;
};

//�}�b�v�����i�M�~�b�N�j
class MAP_ROOM
{
public:
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	GAME_GIMMICK_KIND gimmick;

};

//�}�b�v�ʘH
class MAP_PASS
{
public:
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	int From;
	int To;

};

//�}�b�v�摜�z��
class MAP_CHIP
{
public:
	MAPCHIP mapchip[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
};
