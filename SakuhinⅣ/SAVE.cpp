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
VOID SAVING(int NOWROOM,int TIME)
{

    fp = fopen(".\\SAVEDATA.\\gamedata.txt", "w");
    if (fp == NULL) {
        return;
    }

   /* fwrite(&NOWROOM, sizeof(NOWROOM), 1, fp);*/ //ここでマップの番号とプレイヤーの座標を書き込む。
    fprintf(fp, "%d %d", NOWROOM, TIME);
    fclose(fp);

    return;
}

int LOADING(VOID)
{
    fp = fopen(".\\SAVEDATA\\gamedata.txt", "r");
    if (fp == NULL) {
        IsFirstTime = TRUE;
        return -1;
    }
    int DATAWORK;
    int TIME;
    
    if (fscanf(fp, "%d %d", &DATAWORK, &TIME) == EOF) {
        return -1;
    }
    /*if (fread(&DATAWORK, sizeof(DATAWORK), 1, fp) < 1) {
        return -1;
    }*/

    fclose(fp);
    IsFirstTime = FALSE;
    TimeCounter.LOADTIME(DATAWORK,TIME);
    return DATAWORK;
}