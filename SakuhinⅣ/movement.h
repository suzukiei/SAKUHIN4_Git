#pragma once

#include "class.h"
//�L�[�{�[�h�̎��
#define KEY_CODE_KIND		256	//256���
#define CharaSpeed 8			//�L�����N�^�[�̃X�s�[�h
#define PLAYER_IMG_CHANGE_MAX 16
#define PLAYER_MOVE_MAX 4 //�L�����̈ړ��J�E���g�̏��



BOOL MOVEMENT(CHARA*,int);				//�L�����̈ړ��֐� //�ړ��ł����Ƃ�TRUE
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�
BOOL CHECK_COLLISION(RECT,RECT); //�����蔻����m�F����֐��̒�` //�ǂȂǂɏՓ˂��Ă���Ƃ�TRUE
VOID CHECK_COLLISION_GOAL(VOID); //�S�[�������ۂ̓����蔻��
VOID CHECK_COLLISION_BACK(VOID); 
VOID CHECK_COLLISION_ENEMY(VOID);
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//�̈�̓����蔻�������֐�
BOOL CHARA_COLLISION(RECT, MAP[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]);

//�L�[�{�[�h�̓��͂��擾
extern char AllKeyState[KEY_CODE_KIND];		//���ׂẴL�[�̏�Ԃ�����
extern char OldAllKeyState[KEY_CODE_KIND];	//���ׂẴL�[�̏��(���O)������


BOOL MY_KEY_DOWN(int);				//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f���� 
BOOL MY_KEY_UP(int);				//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����

extern RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
extern RECT mapPassColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];


enum MOVE {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum PLAYER_KIND_1 {
	CHARACHIP_DOWN_1, CHARACHIP_DOWN_2, CHARACHIP_DOWN_3,
	CHARACHIP_LEFT_1, CHARACHIP_LEFT_2, CHARACHIP_LEFT_3,
	CHARACHIP_RIGHT_1, CHARACHIP_RIGHT_2, CHARACHIP_RIGHT_3,
	CHARACHIP_UP_1, CHARACHIP_UP_2, CHARACHIP_UP_3,
};//(U��/D��/R�E/L��)