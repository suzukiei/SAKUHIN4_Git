#include "Dxlib.h"
#include "menu.h"


FILE* fp = NULL; //�t�@�C���|�C���^
VOID SAVING(int)
{

	fp = fopen("/GAMEDATA.txt", "w");
    if (fp == NULL) {
            return;
    }
    //fprintf(fp, "1","player.X.100","player.Y.100"); //�����Ń}�b�v�̔ԍ��ƃv���C���[�̍��W���������ށB
    fclose(fp);

    return;
}

int LOADING(VOID)
{
    fp = fopen("/GAMEDATA.txt", "r");
        if (fp == NULL) {
            return;
        }
        fscanf(fp, "%d", "player.X.100", "player.Y.100",/*&�����ԍ�,//&�v���C���[�̍��W,//&�v���C���[�̍��W*/);

         fclose(fp);

        return;

}