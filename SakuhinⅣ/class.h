//�摜
class IMAGE
{
	char path[PATH_MAX];
	int handle;
	int x;
	int y;
	int width;
	int height;
};

//�^�C�g���w�i
class IMAGE_BACK
{
	IMAGE image;
	BOOL IsDraw;

};

//����
class MUSIC
{
	char path[PATH_MAX];
	int handle;
	int handle2;
};

//�v���C���[
class CHARA
{
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;

	RECT coll;
	iPOINT collBeforePt;
};

//�}�b�v�����i�M�~�b�N�j
class MAP_ROOM
{

};

//�}�b�v�ʘH
class MAP_PASS
{

};

 