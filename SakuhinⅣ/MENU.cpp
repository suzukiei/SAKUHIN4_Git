#include "Dxlib.h"
#include "movement.h"
#include "enum.h"
#include "define.h"
#include "menu.h"
#include "class.h"
#include "menu.h"

VOID MENU(VOID)
{
	DrawGraph(MENU_WIDTH_POSITION, MENU_HEIGHT_POSITION, /*.handle*/, TRUE); //メニュー画面背景画像
	//メニューのタイトルへ戻るボタンの位置
	DrawGraph(MENU_BUTTON_TITLE_WIDTH_POSITION, MENU_BUTTON_TITLE_HEIGHT_POSITION,/*.handle*/, TRUE);
	//セーブボタンの位置
	DrawGraph(MENU_BUTTON_SAVE_WIDTH_POSITION, MENU_BUTTON_SAVE_HEIGHT_POSITION,/*.handle*/, TRUE);

	while (true)
	{
		switch (SELECT)
		{
		case MENU_TITLE:

			//ここに選択時の囲いを表示
			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				GAME_SCENE = GAME_SCENE_START;
			}

			if (MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE)
			{

				SELECT = MENU_SAVE;

			}

			if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)
			{

				SELECT = MENU_SAVE;
			}

			break;


		case MENU_SAVE:
			//ここに選択時の囲いを表示
			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				//ここにセーブ機能
				break;
			}

			if (MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE)
			{

				SELECT = MENU_TITLE;

			}

			if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)
			{

				SELECT = MENU_TITLE;
			}
		}

		break;
	}


}