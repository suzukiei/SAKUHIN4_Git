#pragma once

#define TEXT_POSITION_X 380 //テキストポジションXの値
#define TEXT_POSITION_Y 300 //テキストポジションYの値
#define NAME_POSITION_X 380 //テキストボックス内の名前の位置X
#define NAME_POSITION_Y 280 //テキストボックス内の名前の位置Y
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
    TEXT_END //脱出できたとき
};

VOID TEXTEVENT(VOID);

