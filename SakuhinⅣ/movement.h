#include "class.h"
//�L�[�{�[�h�̎��
#define KEY_CODE_KIND		256	//256���
#define CharaSpeed 2			//�L�����N�^�[�̃X�s�[�h


BOOL MOVEMENT(CHARA *,MOVE);				//�L�����̈ړ��֐� //�ړ��ł����Ƃ�TRUE
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�
BOOL CHARA_COLLISION(CHARA,MAP[MAP_DIV_HEIGHT][MAP_DIV_WIDTH]); //�����蔻����m�F����֐��̒�` //�ǂȂǂɏՓ˂��Ă���Ƃ�TRUE


//�L�[�{�[�h�̓��͂��擾
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//���ׂẴL�[�̏�Ԃ�����
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//���ׂẴL�[�̏��(���O)������


BOOL MY_KEY_DOWN(int);				//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f���� 
BOOL MY_KEY_UP(int);				//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����

enum MOVE {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum PLAYER_KIND_1 {
	D_1, D_2, D_3, D_4,
	L_1, L_2, L_3, L_4,
	R_1, R_2, R_3, R_4,
	U_1, U_2, U_3, U_4
};//(U��/D��/R�E/L��)