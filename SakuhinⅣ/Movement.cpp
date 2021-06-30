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
RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

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
		
			work.image.y -= CharaSpeed;	//�ړ�
		 
			if (work.kind1 >= CHARACHIP_UP_1 && work.kind1 < CHARACHIP_UP_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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

		
			return TRUE; //�ړ��ł��Ă���̂�TRUE��Ԃ�
			break;
	

	case DOWN:

	

		//if (CHARA_COLLISION == FALSE){
			if (work.kind1 >= CHARACHIP_DOWN_1 && work.kind1 < CHARACHIP_DOWN_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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
			work.image.y += CharaSpeed;	//�ړ�
			return TRUE; //�ړ��ł��Ă���̂�TRUE��Ԃ�
		//}

		

		break;

	case RIGHT:

		

		//if (CHARA_COLLISION == FALSE) {
			if (work.kind1 >= CHARACHIP_RIGHT_1 && work.kind1 < CHARACHIP_RIGHT_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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
			work.image.x += CharaSpeed;	//�ړ�

			return TRUE; //�ړ��ł��Ă���̂�TRUE��Ԃ�
		//}

		

		break;

	case LEFT:

		

		//if (CHARA_COLLISION == FALSE) {
			if (work.kind1 >= CHARACHIP_LEFT_1 && work.kind1 < CHARACHIP_LEFT_3)
			{
				//�摜�ύX�J�E���^
				if (work.imgChangeCnt < work.imgChangeCntMAX)
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
			work.image.x -= CharaSpeed;	//�ړ�
			return TRUE; //�ړ��ł��Ă���̂�TRUE��Ԃ�
		//}
		

		break;
	}

	//�Փ˂��Ȃ���΁Awork�����{�̃L�����̏��ɓ����B
	if (work.InRoom) {
		if (CHECK_COLLISION(work.coll, (MAP**)mapRoom[work.nowRoom].map) == FALSE) {
			chara->image.y = work.image.y;
			chara->image.x = work.image.x;
			chara->CenterX = work.CenterX;
			chara->CenterY = work.CenterY;
		}
	}
		


	//if (IsMove == false)
	//{
	//	chara->image.x -= CharaSpeed;//������O�ɖ߂�
	//	chara->image.y -= old_y;
	//}

	//if (IsMove == TRUE)
	//{

	//	{
	//		

	//		//�������Ă��Ȃ��Ƃ��̍��W���擾
	//		chara->collBeforePt.x = chara->CenterX;
	//		chara->collBeforePt.y = chara->CenterY;
	//	}
	//}


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
