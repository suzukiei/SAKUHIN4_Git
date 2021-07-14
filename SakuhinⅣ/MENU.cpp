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


int SELECT = 0;
BOOL IsOpenMenu = FALSE;


VOID MENU(VOID)
{


	if (IsOpenMenu == TRUE)
	{

		if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
		{
			SELECT = MENU_TITLE;
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


			if (player.InRoom == FALSE)
			{
				if (MY_KEY_UP(KEY_INPUT_DOWN) == TRUE)
				{

					SELECT = MENU_SAVE;

				}

				if (MY_KEY_UP(KEY_INPUT_UP) == TRUE)
				{

					SELECT = MENU_SAVE;
				}

			}

			break;


		case MENU_SAVE:
			//�����ɑI�����̈͂���\��

			if (player.InRoom == FALSE)
			{
				if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
				{
					//�����ɃZ�[�u�@�\
					SAVING(player.nowRoom,TimeCounter.NOW());
					IsOpenMenu = FALSE;
					SELECT = MENU_TITLE;

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