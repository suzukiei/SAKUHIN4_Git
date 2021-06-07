#include "Dxlib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "movement.h"
#include "variable.h"

BOOL MY_CHECK_RECT_COLL(RECT, RECT)	//�̈�̓����蔻�������֐�
{
	return FALSE;
}

BOOL CHARA_COLLISION(CHARA a, CHARA b)
{
	if (a.coll.left < b.coll.right &&
		a.coll.top < b.coll.bottom &&
		a.coll.right > b.coll.left &&
		a.coll.bottom > b.coll.top
		)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;		//�������Ă��Ȃ�
}

BOOL CHECK_COLLISION(CHARA P)
{

	//�}�b�v�̓����蔻���ݒ肷��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�v���C���[�ƃ}�b�v���������Ă���Ƃ�
			//if (CHARA_COLLISION(P, mapColl[tate][yoko]) == TRUE)
			//{


			//	//�v���C���[�ƃ}�b�v���������Ă���
			//	if (mapdata3[tate][yoko] == d) { return TRUE; }
			//	if (mapdata3[tate][yoko] == B) { return TRUE; }
			//	if (mapdata2[tate][yoko] == t) { return TRUE; }
			//	if (mapdata2[tate][yoko] == s) { return TRUE; }
			//	if (mapdata2[tate][yoko] == g) { return TRUE; }

			//}
		}
	}

	return FALSE;
}

VOID CHECK_COLLISION_GOAL(VOID)
{
	//�v���C���[�̓����蔻��̐ݒ�
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

	//�S�[���ɐG��Ă��邩�`�F�b�N
	//if (MY_CHECK_RECT_COLL(PlayerRect, /*GoalRect �S�[���̔���*/) == TRUE)
	//{



	//	//�X�^�[�g�|�C���g�ɐݒ肵�J��
	//	/*player.CenterX = startPt2.x;
	//	player.CenterY = startPt2.y;


	//	player.image.x = player.CenterX;
	//	player.image.y = player.CenterY;*/

	//	//GameScene = GAME_SCENE_PLAY2;



	//	return;	//�����I�ɃG���h��ʂɔ��
	//}
}


VOID CHECK_COLLISION_ENEMY(VOID)
{
	//�v���C���[�ƓG�̓����蔻��̐ݒ�
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

	RECT EnemyRect;
	EnemyRect.left = player.CenterX - 40 / 20 + 5;
	EnemyRect.top = player.CenterY + 200 / 20 + 5;
	EnemyRect.right = player.CenterX + 650 / 20 - 5;
	EnemyRect.bottom = player.CenterY + 1000 / 20 - 5;

	//�S�[���ɐG��Ă��邩�`�F�b�N
	if (MY_CHECK_RECT_COLL(PlayerRect,EnemyRect) == TRUE)
	{

		GameScene = GAME_SCENE_END;//�{���̓Q�[���I�[�o��ʂ֑J�ڂ������B



		return;	//�����I�ɃG���h��ʂɔ��
	}
}