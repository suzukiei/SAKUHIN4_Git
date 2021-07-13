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

    fp = fopen("SAVEDATA/gamedata.dat", "wb");
    if (fp == NULL) {
        return;
    }
    fwrite(&player.nowRoom, sizeof(player.nowRoom), 1, fp); //ここでマップの番号とプレイヤーの座標を書き込む。
    fclose(fp);

    return;
}

int LOADING(VOID)
{
    fp = fopen("SAVEDATA/gamedata.dat", "rb");
    if (fp == NULL) {
        return 0;
    }
    fread(&player.nowRoom, sizeof(player.nowRoom), 1, fp);

    fclose(fp);

    return player.nowRoom;
}