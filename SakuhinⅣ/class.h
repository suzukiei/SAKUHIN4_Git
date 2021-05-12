//画像
class STRUCT_IMAGE
{
	char path[PATH_MAX];
	int handle;
	int x;
	int y;
	int width;
	int height;
};

//タイトル背景
class STRUCT_IMAGE_BACK
{
	IMAGE image;
	BOOL IsDraw;

};

//音声
class STRUCT_MUSIC
{
	char path[PATH_MAX];
	int handle;
	int handle2;
};

//プレイヤー
class STRUCT_CHARA
{
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;

	RECT coll;
	iPOINT collBeforePt;
};

//エネミー
class STRUCT_ENEMY
{
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;

	RECT coll;
	iPOINT collBeforePt;
};

//マップ部屋（ギミック）
class MAP_ROOM
{

};

//マップ通路
class MAP_PASS
{

};

 