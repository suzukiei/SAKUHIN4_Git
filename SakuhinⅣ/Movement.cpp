/*��i����W_���ł̊�*/
#include "DxLib.h"
#include "BGM.h"
#include "class.h"
#include "define.h"
#include "enum.h"
#include "flag.h"
#include "GameProcHeader.h"
#include "image.h"
#include "menu.h"
#include "movement.h"
#include "textevent.h"
#include "title.h"
#include "variable.h"


//�L�[�{�[�h�̓��͂��擾
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//���ׂẴL�[�̏�Ԃ�����
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//���ׂẴL�[�̏��(���O)������
int CharaMoveCnt = 0;

//BOOL CHARA_COLLISION(CHARA, CHARA)
//{
//	return FALSE; //�_�~�[�֐�
//}

BOOL MOVEMENT(CHARA* chara,int move)
{

	BOOL IsMove = TRUE; //�ړ��\
	CHARA work = *chara;



	switch (move)
	{
	case UP:
		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{
			work.image.y -= CharaSpeed;	//�ړ�
			work.CenterY -= CharaSpeed;
			work.coll.top -= CharaSpeed;
			work.coll.bottom -= CharaSpeed;
			CharaMoveCnt = 0;
		}
		 
			if (work.kind1 >= CHARACHIP_UP_1 && work.kind1 < CHARACHIP_UP_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					work.kind1++;			//���̉摜�ɂ���
					work.imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				work.kind1 = CHARACHIP_UP_1;	//�ŏ��̉摜�ɂ���
			}

		
			break;


	

	case DOWN:

		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{

			work.image.y += CharaSpeed;	//�ړ�
			work.CenterY += CharaSpeed;
			work.coll.top += CharaSpeed;
			work.coll.bottom += CharaSpeed;
			CharaMoveCnt = 0;
		}
	
	

	
			if (work.kind1 >= CHARACHIP_DOWN_1 && work.kind1 < CHARACHIP_DOWN_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					work.kind1++;			//���̉摜�ɂ���
					work.imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				work.kind1 = CHARACHIP_DOWN_1;	//�ŏ��̉摜�ɂ���
			}
			

		

		break;

	case RIGHT:

		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{
			work.image.x += CharaSpeed;	//�ړ�
			work.CenterX += CharaSpeed;
			work.coll.left += CharaSpeed;
			work.coll.right += CharaSpeed;
			CharaMoveCnt = 0;
		}

			if (work.kind1 >= CHARACHIP_RIGHT_1 && work.kind1 < CHARACHIP_RIGHT_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					work.kind1++;			//���̉摜�ɂ���
					work.imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				work.kind1 = CHARACHIP_RIGHT_1;	//�ŏ��̉摜�ɂ���
			}
	
		

		break;

	case LEFT:


		if (CharaMoveCnt < PLAYER_MOVE_MAX)
		{
			CharaMoveCnt++;
		}
		else
		{
			work.image.x -= CharaSpeed;	//�ړ�
			work.CenterX -= CharaSpeed;
			work.coll.left -= CharaSpeed;
			work.coll.right -= CharaSpeed;
			CharaMoveCnt = 0;
		}
			if (work.kind1 >= CHARACHIP_LEFT_1 && work.kind1 < CHARACHIP_LEFT_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < PLAYER_IMG_CHANGE_MAX)
				{
					work.imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					work.kind1++;			//���̉摜�ɂ���
					work.imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				work.kind1 = CHARACHIP_LEFT_1;	//�ŏ��̉摜�ɂ���
			}
	
		

		break;
	}

	//�Փ˂��Ȃ���΁Awork�����{�̃L�����̏��ɓ����B
	if (work.InRoom) {
		if (CHARA_COLLISION(work.coll, mapRoom[work.nowRoom].map) == FALSE) {
			*chara = work;
			return TRUE;//�ړ��ł��Ă���̂�TRUE��Ԃ��B
		}
	}
	if (work.InPass) {
		if (CHARA_COLLISION(work.coll, mappass.map) == FALSE) {
			*chara = work;
			return TRUE;//�ړ��ł��Ă���̂�TRUE��Ԃ��B
		}
	}

	return FALSE;



}



	

//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
 BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//���O�͉����Ă���
		&& AllKeyState[KEY_INPUT_] == 0)	//���͉����Ă��Ȃ��Ƃ�
	{
		return TRUE;	//�L�[�������グ�Ă���
	}
	else
	{
		return FALSE;	//�L�[�������グ�Ă��Ȃ�
	}
}

//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
 BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//�L�[�R�[�h�̃L�[�������Ă��鎞
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//�L�[�������Ă���
	}
	else
	{
		return FALSE;	//�L�[�������Ă��Ȃ�
	}
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{

	//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����
	char TempKey[KEY_CODE_KIND];

	//���O�̃L�[���͂��Ƃ��Ă���
	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}
