#pragma once

#include "define.h"
#include "image.h"
//#include "movement.h"

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
	int imgChangeCntMAX;         //�ύX����摜�̍ő�
	int nowRoom;                 //������K�w
	int CharaMoveCnt;            //�L�����N�^�[�̈ړ��Ǘ�
	//int  Dire;                   //�����Ă������
	BOOL InRoom = false;         //�����ɂ��邩�ǂ���
	BOOL InPass = false;         //�ʘH�ɋ��邩�ǂ���

	RECT coll;
	IPOINT collBeforePt;
};




//�}�b�v�摜�z��(����Ȃ�����)
//class MAP_CHIP
//{
//public:
//
//	MAPCHIP mapchip[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
//};
