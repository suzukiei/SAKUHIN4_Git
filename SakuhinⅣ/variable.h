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

int GameScene; //�Q�[���V�[��

int GameEndkind;  //�G���h���

CHARA player;   //�v���C���[
CHARA enemy;   //�G�l�~�[

MAP_CHIP mapChipRoom[8];  //���[���}�b�v�`�b�v
MAP_CHIP mapChipPass;  //�ʘH�}�b�v�`�b�v

MAP_ROOM mapRoom[8]; //�}�b�v

MAP_PASS mappass;