#include "Dxlib.h"
#include "movement.h"
#include "enum.h"
#include "define.h"
#include "menu.h"
#include "class.h"
#include "variable.h"
#include "flag.h"
#include "title.h"

int TITLE_SELECT_NO = 0;

VOID TITLE(VOID)
{


	while (true)
	{
		switch (TITLE_SELECT_NO)
		{
		case TITLE_START:

			//�����ɑI�����̈͂���\��





			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				GameScene = GAME_SCENE_PLAY;
			}

			if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
			{

				TITLE_SELECT_NO = TITLE_RULE;

			}

			if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
			{

				TITLE_SELECT_NO = TITLE_QUIT;
			}

			break;

		case TITLE_RULE:
			//�����ɑI�����̈͂���\��


			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				//���[����ʑJ��
				GameScene = GAME_SCENE_RULE;
				break;
			}

			if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
			{

				TITLE_SELECT_NO = TITLE_QUIT;

			}

			if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
			{

				TITLE_SELECT_NO = TITLE_START;
			}

			break;

		

		case TITLE_QUIT:

			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				//�Q�[���I��
				GameLoop = FALSE;
				break;
			}

			if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
			{

				TITLE_SELECT_NO = TITLE_START;

			}

			if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
			{

				TITLE_SELECT_NO = TITLE_RULE;
			}

			break;

		}

		break;
	}
}