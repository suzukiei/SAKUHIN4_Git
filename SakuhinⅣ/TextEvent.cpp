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
			//DrawString();
			//DrawGraph();
			//�܂��܂��ǉ��\��
			StringEndFlag = FALSE;
			textNumber++;
			break;
		}
	}
	return;
}