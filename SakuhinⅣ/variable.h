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

extern int GameScene; //�Q�[���V�[��

extern int GameEndkind;  //�G���h���

extern CHARA player;   //�v���C���[
extern CHARA enemy;   //�G�l�~�[

//����Ȃ�����
//extern MAP_CHIP mapChipRoom[8];  //���[���}�b�v�`�b�v
//extern MAP_CHIP mapChipPass;  //�ʘH�}�b�v�`�b�v

extern MAP_ROOM mapRoom[3][8]; //�}�b�v

extern MAP_PASS mappass;

extern MAPCHIP mapChip;