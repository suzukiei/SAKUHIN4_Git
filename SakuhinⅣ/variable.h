#include "DxLib.h"
#include "BGM.h"
#include "class.h"
#include "define.h"
#include "enum.h"
#include "flag.h"
#include "menu.h"
#include "movement.h"
#include "textevent.h"
#include "title.h"

int GameScene; //ゲームシーン

int GameEndkind;  //エンド画面

CHARA player;   //プレイヤー
CHARA enemy;   //エネミー

MAP_CHIP mapChipRoom[8];  //ルームマップチップ
MAP_CHIP mapChipPass;  //通路マップチップ

MAP_ROOM mapRoom[8]; //マップ

MAP_PASS mappass;