#pragma once


#define TEXTCOLOR GetColor(255,255,255) //テキストの色


extern int textNumber;

enum text {
    TEXT_OP,//目を覚ました瞬間
    TEXT_OP1,//続き
    TEXT_STAGE1_GMMICK_CLEAR,//段ボールの中のギミックをクリアした瞬間
    TEXT_STAGE2_START,//2ステージ目に入った瞬間
    TEXT_STAGE4_START,//4ステージ目に入った瞬間
    TEXT_STAGE5_START,//5ステージ目に入った瞬間
    TEXT_STAGE6_START,//6ステージ目に入った瞬間
    TEXT_TIMEOVER,//時間切れになった瞬間
    TEXT_END, //脱出できたとき
    TEXT_TIMESTOP,//廊下に出たとき
    TEXT_NOTIMEADD,//廊下に出たが、時間が加算されていないとき
};

VOID DRAW_TEXT(VOID);
VOID SET_TEXT_NUMBER(int);
VOID TEXT_END_KEY(VOID);
