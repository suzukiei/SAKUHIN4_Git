#pragma once

#define TEXT_POSITION_X 380 //�e�L�X�g�|�W�V����X�̒l
#define TEXT_POSITION_Y 300 //�e�L�X�g�|�W�V����Y�̒l
#define NAME_POSITION_X 380 //�e�L�X�g�{�b�N�X���̖��O�̈ʒuX
#define NAME_POSITION_Y 280 //�e�L�X�g�{�b�N�X���̖��O�̈ʒuY
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
    TEXT_END //�E�o�ł����Ƃ�
};

VOID TEXTEVENT(VOID);

