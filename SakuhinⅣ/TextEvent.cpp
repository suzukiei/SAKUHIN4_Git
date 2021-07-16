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
BOOL IsDrawText; //�`�撆��
BOOL IsComingDarkness;

VOID DRAW_TEXT(VOID)
{
//�K�v�Ȏ��ɌĂяo�����
		switch (textNumber) {
		case TEXT_OP:
			ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(),TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�����͈�́c?���̎��̑��u�͂Ȃ�?", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerFear.GetHandle(),TRUE);//�L�����̕\���
			
			
			break;

		case TEXT_OP1:
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X -20, TEXT_POSITION_Y, "�J�E���g�_�E�����n�܂��Ă�A�Ƃ肠������������o�Ȃ��Ɓc", TEXTCOLOR); //�Z���t
			DrawString(TEXT_POSITION_X -20, TEXT_POSITION_Y + 30, "��|�����T�����B", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerNomal.GetHandle(), TRUE);//�L�����̕\���

			break;

		case TEXT_STAGE1_GMMICK_CLEAR:
			SetFontSize(30);
			
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(),TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�u�J�`�b�v�Ƃ������������c", TEXTCOLOR); //�����J����

			break;

		case TEXT_STAGE2_START:
			SetFontSize(30);
			
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�����͐}���فc?�ɂ��Ă��������ʌ�����������ˁc", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//�L�����̕\���

		
			break;

		case TEXT_STAGE4_START:
			SetFontSize(30);
		
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "���܂ŕ����������́c", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//�L�����̕\���

			
			break;

		case TEXT_STAGE5_START:
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "����̖��@�w�̂悤�Ȃ��͉̂�������c�����L���c", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//�L�����̕\���

			break;

		case TEXT_STAGE6_START:
			SetFontSize(30);
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "���̕����́c��������?�c", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerNomal.GetHandle(), TRUE);//�L�����̕\���

		
			break;

		case TEXT_TIMEOVER:
			SetFontSize(30);
			
				DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
				DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "���E�����܂��Ă��Ă���悤���c", TEXTCOLOR); //�Z���t
				
			
			break;
		case TEXT_END:
			SetFontSize(30);
		
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�悤�₭�O�ɏo�ꂽ�c�����������痣��悤", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerSmile.GetHandle(), TRUE);//�L�����̕\���

			
			break;

		case TEXT_TIMESTOP:
			SetFontSize(30);

			

			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�J�E���g�_�E�����~�܂����A���Ԃ������Ă���B", TEXTCOLOR); //�Z���t
			break;

		case TEXT_NOTIMEADD:

			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�J�E���g�_�E�����~�܂����B", TEXTCOLOR); //�Z���t
			break;
			

		}
	return;
}



VOID SET_TEXT_NUMBER(int Number)
{
	//�K�v�Ȏ��ɌĂяo�����
	switch (Number) {
	case TEXT_OP:
		IsDrawText = TRUE;

		textNumber = TEXT_OP;
		
		break;

	case TEXT_OP1:
		IsDrawText = TRUE;
		
		textNumber = TEXT_OP1;
		
		break;

	case TEXT_STAGE1_GMMICK_CLEAR:
		IsDrawText = TRUE;
		
		textNumber = TEXT_STAGE1_GMMICK_CLEAR;
		break;

	case TEXT_STAGE2_START:
		IsDrawText = TRUE;
	
		textNumber = TEXT_STAGE2_START;

	
		break;

	case TEXT_STAGE4_START:
		IsDrawText = TRUE;
		
		textNumber = TEXT_STAGE4_START;
		
		break;

	case TEXT_STAGE5_START:
		IsDrawText = TRUE;
		
		textNumber = TEXT_STAGE5_START;
		
		break;

	case TEXT_STAGE6_START:
		IsDrawText = TRUE;
		
		textNumber = TEXT_STAGE6_START;
		
		break;

	case TEXT_TIMEOVER:
		IsDrawText = TRUE;
		
		textNumber = TEXT_TIMEOVER;

		if (IsComingDarkness == TRUE) {

			IsDrawText = FALSE;


		}
		
		break;
	case TEXT_END:
		IsDrawText = TRUE;
	
		textNumber = TEXT_END;
		
		break;

	case TEXT_TIMESTOP:

		IsDrawText = TRUE;
		textNumber = TEXT_TIMESTOP;

		break;

	case TEXT_NOTIMEADD:

		IsDrawText = TRUE;
		textNumber = TEXT_NOTIMEADD;

		break;


	}
	return;
}

VOID TEXT_END_KEY(VOID)
{
	if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
	{
		if (textNumber == TEXT_OP) {
			
			IsDrawText = TRUE;
			textNumber = TEXT_OP1;
		}
		else {
			IsDrawText = FALSE;
		}

		if (textNumber == TEXT_TIMEOVER )
		{
			

			

			
			if(IsComingDarkness == FALSE)
			{
				IsComingDarkness = TRUE;
			}

		}
	
		
	}

	return;
}