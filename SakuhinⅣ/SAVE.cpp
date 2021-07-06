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


FILE* fp = NULL; //ファイルポインタ
VOID SAVING(int)
{

	fp = fopen("/GAMEDATA.txt", "w");
    if (fp == NULL) {
            return;
    }
    //fprintf(fp, mapRoom,"player.X.100","player.Y.100"); //ここでマップの番号とプレイヤーの座標を書き込む。
    fclose(fp);

    return;
}

int LOADING(VOID)
{
    fp = fopen("/GAMEDATA.txt", "r");
        if (fp == NULL) {
            return 0;
        }
        //fscanf(fp, "%d", "player.X.100", "player.Y.100",/*&部屋番号,//&プレイヤーの座標,//&プレイヤーの座標*/);

         fclose(fp);

        return 0;

}