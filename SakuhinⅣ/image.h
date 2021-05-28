#include"define.h"
#include "DxLib.h"

#define GAME_MAP_PATH		TEXT(".\\IMAGE\\mapuse.png")		//マップ画像パス

#define GAME_CSV_PATH_STAGE1_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage1_床.csv")//STAGE1床
#define GAME_CSV_PATH_STAGE1_WALL 		TEXT(".\\IMAGE\\csv\\Stage1_壁.csv")//STAGE1壁
#define GAME_CSV_PATH_STAGE1_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage1_血.csv")//STAGE1血
#define GAME_CSV_PATH_STAGE1_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage1_重ね血.csv")//STAGE1重ね血
#define GAME_CSV_PATH_STAGE1_ACCES 		TEXT(".\\IMAGE\\csv\\Stage1_小物.csv")//STAGE1小物
#define GAME_CSV_PATH_STAGE1_RECT 		TEXT(".\\IMAGE\\csv\\Stage1_当たり判定.csv")//STAGE1当たり判定

//画像
class IMAGE
{
public:
	int x;
	int y;
	int width;
	int height;

private:
	int handle;
	char path[PATH_MAX];

public:
	//handleの設定
	VOID SetHandle(int Data)
	{
		handle = Data;
		return;
	}

	//handleを消す
	VOID DeleteHandle(VOID)
	{
		DeleteGraph(handle);
		return;
	}

	//パスの設定
	VOID SetPath(char Path[])
	{
		strcpy_s(path, Path);
		return;
	}

	//ハンドルを返す
	int GetHandle(VOID)
	{
		return(handle);
	}

	//パスを返す
	char* GetPath(VOID)
	{
		return(path);
	}
};

//タイトル背景
class IMAGE_BACK : IMAGE
{
public:
	BOOL IsDraw;

}; 

BOOL MY_LOAD_MAPCHIP(VOID);

BOOL MY_LOAD_IMAGE(VOID);
VOID MY_DELETE_IMAGE(VOID);

BOOL MY_LOAD_CSV_MAP(const char* path);