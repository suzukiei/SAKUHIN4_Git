/*��i����W_���ł̊�*/
#include "DxLib.h"
#include "movement.h"
#include "class.h"

BOOL MOVEMENT(CHARA* chara,int move)
{

	BOOL IsMove = TRUE; //�ړ��\
	CHARA work = *chara;

	switch (move)
	{
	case UP:
		chara->IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�
		
		//if (CHARA_COLLISION() == FALSE) {
			if (chara->kind1 >= U_1 && chara->kind1 < U_4)
			{
				//�摜�ύX�J�E���^
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					chara->kind1++;			//���̉摜�ɂ���
					chara->imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				chara->kind1 = U_1;	//�ŏ��̉摜�ɂ���
			}

			chara->image.y -= CharaSpeed;	//�ړ�

			break;
		//}

	case DOWN:

		chara->IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (CHARA_COLLISION == FALSE)
		{
			if (chara->kind1 >= D_1 && chara->kind1 < D_4)
			{
				//�摜�ύX�J�E���^
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					chara->kind1++;			//���̉摜�ɂ���
					chara->imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				chara->kind1 = D_1;	//�ŏ��̉摜�ɂ���
			}
			chara->image.y += CharaSpeed;	//�ړ�
		}
		break;

	case RIGHT:

		chara->IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (CHARA_COLLISION == FALSE) {
			if (chara->kind1 >= R_1 && chara->kind1 < R_4)
			{
				//�摜�ύX�J�E���^
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					chara->kind1++;			//���̉摜�ɂ���
					chara->imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				chara->kind1 = R_1;	//�ŏ��̉摜�ɂ���
			}
			chara->image.x += CharaSpeed;	//�ړ�
		}
		break;

	case LEFT:

		chara->IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (CHARA_COLLISION == FALSE) {
			if (chara->kind1 >= L_1 && chara->kind1 < L_4)
			{
				//�摜�ύX�J�E���^
				if (chara->imgChangeCnt < chara->imgChangeCntMAX)
				{
					chara->imgChangeCnt++;
				}
				else //�摜��ς���^�C�~���O�ɂȂ�����
				{
					chara->kind1++;			//���̉摜�ɂ���
					chara->imgChangeCnt = 0;	//�ύX�J�E���^������
				}
			}
			else
			{
				chara->kind1 = L_1;	//�ŏ��̉摜�ɂ���
			}
			chara->image.x -= CharaSpeed;	//�ړ�
		}

		break;
	}



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
