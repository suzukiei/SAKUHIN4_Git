#pragma once

#define TEXT_POSITION_X 380 //テキストポジションXの値
#define TEXT_POSITION_Y 300 //テキストポジションYの値
#define TEXTCOLOR GetColor(255,255,255) //テキストの色


extern int textNumber;

enum text {
    TEXT_OP,
    TEXT_OP_1,//まだまだ追加予定
    TEXT_STAGE1_GMMICK_CLEAR,
    TEXT_END
};

VOID TEXTEVENT(VOID);

