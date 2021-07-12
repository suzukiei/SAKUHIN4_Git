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

VOID TEXTEVENT(int textNumber)
{
//必要な時に呼び出される
		switch (textNumber) {
		case TEXT_OP:
			SetFontSize(30);
			ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);

			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(),TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "ここは一体…?この腕輪の装置はなに?", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerFear.GetHandle(),TRUE);//キャラの表情差分
			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE) 

			SetFontSize(16);
			break;

		case TEXT_OP1:
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "カウントダウンが始まってる、とりあえずここから出ないと。", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerNomal.GetHandle(), TRUE);//キャラの表情差分

			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)

				SetFontSize(16);
			break;

		case TEXT_STAGE1_GMMICK_CLEAR:
			
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(),TRUE); //テキストボックスの画像
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "「カチッ」という音がした…", TEXTCOLOR); //扉が開いた

			while(MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)
			
			SetFontSize(16);
			break;

		case TEXT_STAGE2_START:

			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "ここは図書館…?にしてもあたり一面血がすごいわね…", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//キャラの表情差分
			
			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)
		
			SetFontSize(16);
			break;

		case TEXT_STAGE4_START:
			
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "いつまで部屋が続くの…", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//キャラの表情差分

			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)

				SetFontSize(16);
			break;

		case TEXT_STAGE5_START:

			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "周りの結界のようなものは何かしら…血生臭い…", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//キャラの表情差分

			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)

				SetFontSize(16);
			break;

		case TEXT_STAGE6_START:

			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "この部屋は…何も無い?…", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerNomal.GetHandle(), TRUE);//キャラの表情差分

			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)

				SetFontSize(16);
			break;

		case TEXT_TIMEOVER:
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "あなたは・・・!", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//キャラの表情差分

			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)

				SetFontSize(16);
			break;
		case TEXT_END:

			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //テキストボックスの画像
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[永依]", TEXTCOLOR); //名前
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "ようやく外に出れた…早くここから離れよう", TEXTCOLOR); //セリフ
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerSmile.GetHandle(), TRUE);//キャラの表情差分

			while (MY_KEY_DOWN(KEY_INPUT_RETURN) != TRUE)

				SetFontSize(16);
			break;
			

		}
	return;
}