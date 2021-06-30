#pragma once

#include "DxLib.h"
#include"define.h"
#include "class.h"


//�v���C�[�摜
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\chara.png")		//�v���C���[�摜�p�X
#define PLAYER_CHANGE_NUM	3	//�v���C���[�摜�ύX��
#define PLAYER_WIDTH		32	//�v���C���[�摜��
#define PLAYER_HEIGHT		32	//�v���C���[�摜�c
#define PLAYER_DIV_TATE		4	//�v���C���[�摜�c������
#define	PLAYER_DIV_YOKO		3	//�v���C���[�摜��������
#define PLAYER_DIV_NUM		PLAYER_DIV_TATE*PLAYER_DIV_YOKO		//�v���C���[�摜��������
#define PLAYER_ROTA			2.0	//�v���C���[�g�嗦
#define PLAYER_ACTWAIT		100	//�v���C���[�A�j���[�V�����҂�����
#define PLAYER_LEFT			3	//������
#define PLAYER_LEFT_MAX		5	//���ő�
#define PLAYER_RIGHT		6	//�E����
#define	PLAYER_RIGHT_MAX	8	//�E�ő�
#define PLAYER_BACK			9	//������
#define PLAYER_BACK_MAX		11	//���ő�
#define PLAYER_RIGHT_STAY	7	//�E�����҂�
#define PLAYER_LEFT_STAY	4	//�������҂�

#define GAME_MAP_PATH		TEXT(".\\IMAGE\\mapuse.png")		//�}�b�v�摜�p�X

#define GAME_MAP_ROOM_NUMBER     8

#define GAME_CSV_PATH_STAGE1_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage1_��.csv")//STAGE1��
#define GAME_CSV_PATH_STAGE1_WALL 		TEXT(".\\IMAGE\\csv\\Stage1_��.csv")//STAGE1��
#define GAME_CSV_PATH_STAGE1_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage1_��.csv")//STAGE1��
#define GAME_CSV_PATH_STAGE1_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage1_�d�ˌ�.csv")//STAGE1�d�ˌ�
#define GAME_CSV_PATH_STAGE1_ACCES 		TEXT(".\\IMAGE\\csv\\Stage1_����.csv")//STAGE1����
#define GAME_CSV_PATH_STAGE1_RECT 		TEXT(".\\IMAGE\\csv\\Stage1_�����蔻��.csv")//STAGE1�����蔻��
#define GAME_CSV_PATH_STAGE1_SG 		TEXT(".\\IMAGE\\csv\\Stage1_SG.csv")//STAGE1�X�^�[�g�S�[��
#define GAME_CSV_PATH_STAGE1_GIMMICK    TEXT(".\\IMAGE\\csv\\Stage1_�M�~�b�N.csv")//STAGE1�M�~�b�N

#define GAME_CSV_PATH_STAGE2_FLOOR 		TEXT(".\\IMAGE\\csv\\Stage2_��.csv")//STAGE2��
#define GAME_CSV_PATH_STAGE2_WALL 		TEXT(".\\IMAGE\\csv\\Stage2_��.csv")//STAGE2��
#define GAME_CSV_PATH_STAGE2_BLOOD 		TEXT(".\\IMAGE\\csv\\Stage2_��.csv")//STAGE2��
#define GAME_CSV_PATH_STAGE2_SBLOOD 	TEXT(".\\IMAGE\\csv\\Stage2_�d�ˌ�.csv")//STAGE�d�ˌ�
#define GAME_CSV_PATH_STAGE2_ACCES 		TEXT(".\\IMAGE\\csv\\Stage2_����.csv")//STAGE2����
#define GAME_CSV_PATH_STAGE2_RECT 		TEXT(".\\IMAGE\\csv\\Stage2_�����蔻��.csv")//STAGE2�����蔻��
#define GAME_CSV_PATH_STAGE2_SG 		TEXT(".\\IMAGE\\csv\\Stage2_SG.csv")//STAGE2�X�^�[�g�S�[��

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
	char path[PATH_MAX] = "";

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
	VOID SetPath(const char* Path)
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

//�}�b�v�����i�M�~�b�N�j
typedef struct MAP_ROOM
{
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	GAME_GIMMICK_KIND gimmick;
	int x;
	int y;

	IPOINT StartPt;   //�X�^�[�g�n�_
	IPOINT GoalPt;	  //�S�[���n�_
};

typedef struct MAP_ROOM MAP_ROOM;

//�}�b�v�ʘH
typedef struct MAP_PASS
{

	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	int From;
	int To;

	IPOINT StartPt;   //�X�^�[�g�n�_
	IPOINT GoalPt;	  //�S�[���n�_
};

typedef struct MAP_PASS MAP_PASS;

BOOL MY_LOAD_MAPCHIP(VOID);
BOOL MY_LOAD_CSV(VOID);

BOOL MY_LOAD_IMAGE(VOID);
VOID MY_DELETE_IMAGE(VOID);


//CSV�̃}�b�v��ǂݍ���
BOOL MY_LOAD_CSV_MAP(const char *, MAP_ROOM*,int Layer);

VOID START_DRAW(VOID);	//�X�^�[�g��ʂ̕`��
VOID RULE_DRAW(VOID);	//���[����ʂ̕`��
VOID PLAY_DRAW(VOID);	//�v���C��ʂ̕`��
VOID END_DRAW(VOID);	    //�G���h��ʂ̕`��