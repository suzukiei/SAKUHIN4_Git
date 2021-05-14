#include "Dxlib.h"
#include "movement.h"
#include "enum.h"
#include "define.h"
#include "menu.h"
#include "class.h"
#include "variable.h"
#include "flag.h"

VOID MENU(VOID)
{

	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		//ここにメニュー表示の関数を制作する。
		IsMove = FALSE;

		MENU();

	}

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
				GameScene = GAME_SCENE_START;
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

VOID RETURN_TITLE(VOID)
{
	//マウスを右クリックすると、タイトル画面に戻る
	if (MY_KEY_DOWN(KEY_INPUT_L) == TRUE)
	{


		//マウスを表示
		SetMouseDispFlag(TRUE);

		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YESなら、ゲームを中断する
		{
			//強制的にタイトル画面に飛ぶ
			GameScene = GAME_SCENE_START;
			return;

		}
		else if (Ret == IDNO)	//NOなら、ゲームを続行する
		{

			//マウスを非表示にする。
			SetMouseDispFlag(FALSE);
		}
	}
}