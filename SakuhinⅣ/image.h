#include"define.h"
 #include "DxLib.h"

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