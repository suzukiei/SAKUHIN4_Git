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

int textNumber;
BOOL StringEndFlag;

VOID TEXTEVENT(VOID)
{
//###################################
//
//この項目はゲーム全体がほぼ出来上がるまで作業がストップします。
// (具体的なストーリーを決めなければ作業ができないため。)
//
//###################################

	if (StringEndFlag == TRUE) {
		switch (textNumber) {
		case TEXT_OP:
			SetFontSize(30);
			ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);

			//DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(),TRUE); //テキストボックスの画像
			//DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			//DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "ここは一体…とりあえずここから出ないと…", TEXTCOLOR); //セリフ
			//DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerFear.GetHandle());//キャラの表情差分
			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE) 
			{
				StringEndFlag = FALSE;
				textNumber++;
				SetFontSize(16);
			}
			break;
		case TEXT_STAGE1_GMMICK_CLEAR:
			SetFontSize(30);




			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				StringEndFlag = FALSE;
				textNumber++;
				SetFontSize(16);
			}
			break;

		}
	}
	return;
}