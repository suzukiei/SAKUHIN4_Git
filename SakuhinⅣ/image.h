#include"define.h"
#include "DxLib.h"

#define GAME_MAP_PATH		TEXT(".\\IMAGE\\mapuse.png")		//�}�b�v�摜�p�X

#define GAME_CSV_PATH_STAGE1_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage1_��.csv")//STAGE1��
#define GAME_CSV_PATH_STAGE1_WALL 		TEXT(".\\IMAGE\\csv\\Stage1_��.csv")//STAGE1��
#define GAME_CSV_PATH_STAGE1_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage1_��.csv")//STAGE1��
#define GAME_CSV_PATH_STAGE1_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage1_�d�ˌ�.csv")//STAGE1�d�ˌ�
#define GAME_CSV_PATH_STAGE1_ACCES 		TEXT(".\\IMAGE\\csv\\Stage1_����.csv")//STAGE1����
#define GAME_CSV_PATH_STAGE1_RECT 		TEXT(".\\IMAGE\\csv\\Stage1_�����蔻��.csv")//STAGE1�����蔻��

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

BOOL MY_LOAD_MAPCHIP(VOID);

BOOL MY_LOAD_IMAGE(VOID);
VOID MY_DELETE_IMAGE(VOID);

BOOL MY_LOAD_CSV_MAP(const char* path);