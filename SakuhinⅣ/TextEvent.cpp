#include "DxLib.h"
#include "class.h"
#include "define.h"
#include "enum.h"
#include "flag.h"
#include "menu.h"
#include "movement.h"
#include "textevent.h"

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

			//DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH,画像ハンドル,TRUE); //テキストボックスの画像
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "ここは一体…", TEXTCOLOR); //セリフ
			//DrawGraph();//キャラの表情差分
			//まだまだ追加予定
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