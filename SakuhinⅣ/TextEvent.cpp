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
//���̍��ڂ̓Q�[���S�̂��قڏo���オ��܂ō�Ƃ��X�g�b�v���܂��B
// (��̓I�ȃX�g�[���[�����߂Ȃ���΍�Ƃ��ł��Ȃ����߁B)
//
//###################################

	if (StringEndFlag == TRUE) {
		switch (textNumber) {
		case TEXT_OP:
			SetFontSize(30);
			ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);

			//DrawGraph(IMAGE_TEXTBOX_WIDTH_PATH,IMAGE_TEXTBOX_HEIGHT_PATH,�摜�n���h��,TRUE); //�e�L�X�g�{�b�N�X�̉摜
			DrawString(TEXT_POSITION_X, TEXT_POSITION_Y, "�����͈�́c", TEXTCOLOR); //�Z���t
			//DrawGraph();//�L�����̕\���
			//�܂��܂��ǉ��\��
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