#pragma once

#define TEXT_POSITION_X 380 //�e�L�X�g�|�W�V����X�̒l
#define TEXT_POSITION_Y 300 //�e�L�X�g�|�W�V����Y�̒l
#define TEXTCOLOR GetColor(255,255,255) //�e�L�X�g�̐F


extern int textNumber;

enum text {
    TEXT_OP,
    TEXT_OP_1,//�܂��܂��ǉ��\��
    TEXT_STAGE1_GMMICK_CLEAR,
    TEXT_END
};

VOID TEXTEVENT(VOID);

