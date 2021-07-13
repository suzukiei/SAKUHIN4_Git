#include "Dxlib.h"
#include "movement.h"
#include "enum.h"
#include "define.h"
#include "menu.h"
#include "class.h"
#include "variable.h"
#include "flag.h"

int SELECT = 0;
BOOL IsOpenMenu = FALSE;


VOID MENU(VOID)
{


	if (IsOpenMenu == TRUE)
	{

		if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
		{
			IsOpenMenu = FALSE;
		}

		switch (SELECT)
		{
		case MENU_TITLE:

			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				GameScene = GAME_SCENE_START;
				IsOpenMenu = FALSE;
			}

			if (MY_KEY_UP(KEY_INPUT_DOWN) == TRUE)
			{

				SELECT = MENU_SAVE;

			}

			if (MY_KEY_UP(KEY_INPUT_UP) == TRUE)
			{

				SELECT = MENU_SAVE;
			}
			
			

			break;


		case MENU_SAVE:
			//�����ɑI�����̈͂���\��


			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				//�����ɃZ�[�u�@�\
				SAVING(player.nowRoom);
				IsOpenMenu = FALSE;
				break;
			}

			if (MY_KEY_UP(KEY_INPUT_DOWN) == TRUE)
			{

				SELECT = MENU_TITLE;

			}

			if (MY_KEY_UP(KEY_INPUT_UP) == TRUE)
			{

				SELECT = MENU_TITLE;
			}
			

			
			break;
		}

	}


}

VOID RETURN_TITLE(VOID)
{
	//�}�E�X���E�N���b�N����ƁA�^�C�g����ʂɖ߂�
	if (MY_KEY_UP(KEY_INPUT_L) == TRUE)
	{


		//�}�E�X��\��
		SetMouseDispFlag(TRUE);

		//�I���_�C�A���O��\��
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YES�Ȃ�A�Q�[���𒆒f����
		{
			//�����I�Ƀ^�C�g����ʂɔ��
			GameScene = GAME_SCENE_START;
			return;

		}
		else if (Ret == IDNO)	//NO�Ȃ�A�Q�[���𑱍s����
		{

			//�}�E�X���\���ɂ���B
			SetMouseDispFlag(FALSE);
		}
	}
}