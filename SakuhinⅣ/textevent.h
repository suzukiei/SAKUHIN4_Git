#pragma once

#define TEXT_POSITION_X 380 //テキストポジションXの値
#define TEXT_POSITION_Y 300 //テキストポジションYの値

extern int textNumber;

enum text {
    TEXT_OP,
    TEXT_OP_1,//まだまだ追加予定
    TEXT_END
};

VOID TEXTEVENT(VOID);

