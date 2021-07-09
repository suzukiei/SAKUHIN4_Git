#pragma once

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

#define ROOM_NUM 7

extern int GameScene; //ゲームシーン

extern int GameEndkind;  //エンド画面

extern CHARA player;   //プレイヤー
extern CHARA enemy;   //エネミー

//いらないかも
//extern MAP_CHIP mapChipRoom[8];  //ルームマップチップ
//extern MAP_CHIP mapChipPass;  //通路マップチップ

extern MAP_ROOM mapRoom[ROOM_NUM]; //マップ

extern MAP_PASS mappass;

extern MAPCHIP mapChip;