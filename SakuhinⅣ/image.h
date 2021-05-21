#include"define.h"
 #include "DxLib.h"

//�摜
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
	//handle�̐ݒ�
	VOID SetHandle(int Data)
	{
		handle = Data;
		return;
	}

	//handle������
	VOID DeleteHandle(VOID)
	{
		DeleteGraph(handle);
		return;
	}

	//�p�X�̐ݒ�
	VOID SetPath(char Path[])
	{
		strcpy_s(path, Path);
		return;
	}

	//�n���h����Ԃ�
	int GetHandle(VOID)
	{
		return(handle);
	}

	//�p�X��Ԃ�
	char* GetPath(VOID)
	{
		return(path);
	}
};

//�^�C�g���w�i
class IMAGE_BACK : IMAGE
{
public:
	BOOL IsDraw;

}; 