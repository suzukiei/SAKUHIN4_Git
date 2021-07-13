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

VOID TEXTEVENT(int textNumber)
{
//�K�v�Ȏ��ɌĂяo�����
		switch (textNumber) {
		case TEXT_OP:

			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(),TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�����͈�́c?���̘r�ւ̑��u�͂Ȃ�?", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerFear.GetHandle(),TRUE);//�L�����̕\���
			
			break;

		case TEXT_OP1:
		
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�J�E���g�_�E�����n�܂��Ă�A�Ƃ肠������������o�Ȃ��ƁB", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerNomal.GetHandle(), TRUE);//�L�����̕\���

			break;

		case TEXT_STAGE1_GMMICK_CLEAR:
			
			
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(),TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�u�J�`�b�v�Ƃ������������c", TEXTCOLOR); //�����J����

			break;

		case TEXT_STAGE2_START:

			
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�����͐}���فc?�ɂ��Ă��������ʌ�����������ˁc", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//�L�����̕\���

		
			break;

		case TEXT_STAGE4_START:
			
		
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "���܂ŕ����������́c", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//�L�����̕\���

			
			break;

		case TEXT_STAGE5_START:

			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "����̌��E�̂悤�Ȃ��͉̂�������c�����L���c", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//�L�����̕\���

			break;

		case TEXT_STAGE6_START:

			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "���̕����́c��������?�c", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerNomal.GetHandle(), TRUE);//�L�����̕\���

		
			break;

		case TEXT_TIMEOVER:
			
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "���Ȃ��́E�E�E!", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerTrouble.GetHandle(), TRUE);//�L�����̕\���

			
			break;
		case TEXT_END:

		
			DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH, IMAGE_TEXTBOX_HEIGHT_PATH, TextBox.GetHandle(), TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(NAME_POSITION_X, NAME_POSITION_Y, "[�i��]", TEXTCOLOR); //���O
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�悤�₭�O�ɏo�ꂽ�c�����������痣��悤", TEXTCOLOR); //�Z���t
			DrawGraph(IMAGE_PLAYER_NOMAL_WIDTH_PATH, IMAGE_PLAYER_NOMAL_HEIGHT_PATH, PlayerSmile.GetHandle(), TRUE);//�L�����̕\���

			
			break;
			

		}
	return;
}



VOID TEXTPROC(int textNumber)
{
	//�K�v�Ȏ��ɌĂяo�����
	switch (textNumber) {
	case TEXT_OP:
		IsDrawText = TRUE;
		SetFontSize(30);
		ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);

		
		break;

	case TEXT_OP1:
		IsDrawText = TRUE;
		SetFontSize(30);

		
		break;

	case TEXT_STAGE1_GMMICK_CLEAR:
		IsDrawText = TRUE;
		SetFontSize(30);
		
		break;

	case TEXT_STAGE2_START:
		IsDrawText = TRUE;
		SetFontSize(30);
	

	
		break;

	case TEXT_STAGE4_START:
		IsDrawText = TRUE;
		SetFontSize(30);

		
		break;

	case TEXT_STAGE5_START:
		IsDrawText = TRUE;
		SetFontSize(30);
	
		
		break;

	case TEXT_STAGE6_START:
		IsDrawText = TRUE;
		SetFontSize(30);
		
		
		break;

	case TEXT_TIMEOVER:
		IsDrawText = TRUE;
		SetFontSize(30);

		
		break;
	case TEXT_END:
		IsDrawText = TRUE;
		SetFontSize(30);

		
		break;


	}
	return;
}