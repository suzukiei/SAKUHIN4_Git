#pragma once

#include "define.h"
#include "image.h"

//�v���C���[
class CHARA
{
public:
	IMAGE image;
	int handle[PLAYER_DIV_NUM];
	int speed;                   //�L�����N�^�[�X�s�[�h
	int CenterX;                 //�L�����N�^�[X�ʒu
	int CenterY;                 //�L�����N�^�[Y�ʒu
	int kind1;                	 //���݂̃L�����N�^�[���
	int imgChangeCnt;            //�ύX�������摜
	int imgChangeCntMAX;
	int nowRoom;
	double angle;
	double rate;
	BOOL InRoom = false;        //�����ɂ��邩�ǂ���
	BOOL InPass = false;        //�ʘH�ɋ��邩�ǂ���
	BOOL IsMoveNaname;

	RECT coll;
	IPOINT collBeforePt;
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
class MAP_PASS
{
public:
	MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	int From;
	int To;

	IPOINT StartPt;   //�X�^�[�g�n�_
	IPOINT GoalPt;	  //�S�[���n�_
};

//�}�b�v�摜�z��(����Ȃ�����)
//class MAP_CHIP
//{
//public:
//
//	MAPCHIP mapchip[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
//};
