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