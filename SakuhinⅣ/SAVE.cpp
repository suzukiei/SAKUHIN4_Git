#define _CRT_SECURE_NO_WARNINGS
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


FILE* fp = NULL; //�t�@�C���|�C���^
VOID SAVING(int)
{

	fp = fopen("/GAMEDATA.txt", "w");
    if (fp == NULL) {
            return;
    }
    //fprintf(fp, mapRoom,"player.X.100","player.Y.100"); //�����Ń}�b�v�̔ԍ��ƃv���C���[�̍��W���������ށB
    fclose(fp);

    return;
}

int LOADING(VOID)
{
    fp = fopen("/GAMEDATA.txt", "r");
        if (fp == NULL) {
            return 0;
        }
        //fscanf(fp, "%d", "player.X.100", "player.Y.100",/*&�����ԍ�,//&�v���C���[�̍��W,//&�v���C���[�̍��W*/);

         fclose(fp);

        return 0;

}