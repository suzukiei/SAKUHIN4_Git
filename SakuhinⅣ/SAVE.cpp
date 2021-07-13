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
VOID SAVING(int NOWROOM)
{

    fp = fopen(".\\SAVEDATA.\\gamedata.txt", "w");
    if (fp == NULL) {
        return;
    }

    fwrite(&NOWROOM, sizeof(NOWROOM), 1, fp); //ここでマップの番号とプレイヤーの座標を書き込む。
    fclose(fp);

    return;
}

int LOADING(VOID)
{
    fp = fopen(".\\SAVEDATA\\gamedata.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    int DATAWORK;
    
    if (fread(&DATAWORK, sizeof(DATAWORK), 1, fp) < 1) {
        return 0;
    }

    fclose(fp);

    return DATAWORK;
}