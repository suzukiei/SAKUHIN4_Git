#include "Dxlib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "movement.h"

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