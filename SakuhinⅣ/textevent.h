#pragma once


#define TEXTCOLOR GetColor(255,255,255) //�e�L�X�g�̐F


extern int textNumber;

enum text {
    TEXT_OP,//�ڂ��o�܂����u��
    TEXT_OP1,//����
    TEXT_STAGE1_GMMICK_CLEAR,//�i�{�[���̒��̃M�~�b�N���N���A�����u��
    TEXT_STAGE2_START,//2�X�e�[�W�ڂɓ������u��
    TEXT_STAGE4_START,//4�X�e�[�W�ڂɓ������u��
    TEXT_STAGE5_START,//5�X�e�[�W�ڂɓ������u��
    TEXT_STAGE6_START,//6�X�e�[�W�ڂɓ������u��
    TEXT_TIMEOVER,//���Ԑ؂�ɂȂ����u��
    TEXT_END, //�E�o�ł����Ƃ�
    TEXT_TIMESTOP,//�L���ɏo���Ƃ�
    TEXT_NOTIMEADD,//�L���ɏo�����A���Ԃ����Z����Ă��Ȃ��Ƃ�
};

VOID DRAW_TEXT(VOID);
VOID SET_TEXT_NUMBER(int);
VOID TEXT_END_KEY(VOID);
