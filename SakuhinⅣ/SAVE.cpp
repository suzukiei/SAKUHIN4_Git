#include "Dxlib.h"
#include "menu.h"


FILE* fp = NULL; //ファイルポインタ
VOID SAVING(int)
{

	fp = fopen("/GAMEDATA.txt", "w");
    if (fp == NULL) {
            return;
    }
    //fprintf(fp, "1","player.X.100","player.Y.100"); //ここでマップの番号とプレイヤーの座標を書き込む。
    fclose(fp);

    return;
}

int LOADING(VOID)
{
    fp = fopen("/GAMEDATA.txt", "r");
        if (fp == NULL) {
            return;
        }
        fscanf(fp, "%d", "player.X.100", "player.Y.100",/*&部屋番号,//&プレイヤーの座標,//&プレイヤーの座標*/);

         fclose(fp);

        return;

}