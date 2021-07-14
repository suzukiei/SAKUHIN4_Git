#pragma once

#include"enum.h"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 560
#define GAME_WIDTH 960
#define GAME_HEIGHT 560
#define GAME_COLOR 32

#define GAME_WINDOW_BAR 0

//GAME_NAME
#define GAME_WINDOW_NAME "�Èł̊�"

//FPS
#define GAME_FPS	60

#define KEY_BUTTON_CODE 129

//PATH
#define PATH_MAX	255
#define NAME_MAX	255

//FONT
#define FONT_PATH_MAX			255
//#define FONT_PATH			TEXT(".ttf")
//#define FONT_NAME			TEXT("font���O")
#define FONT_INSTALL_ERR_TITLE	TEXT("�t�H���g�C���X�g�[���G���[")
#define FONT_CREATE_ERR_TITLE	TEXT("�t�H���g�쐬�G���[")

//�摜�ǂݍ��݃G���[
#define IMAGE_LOAD_ERR_TITLE TEXT("�摜�ǂݍ��݃G���[")

//�摜�p�X
#define IMAGE_TITLE_BK_PATH				TEXT(".\\IMAGE\\title_back.png")
#define IMAGE_TITLE_ROGO_PATH				TEXT(".\\IMAGE\\Titlelogo.png")

//logo�ꏊ�w��
#define IMAGE_TITLE_ROGO_WIDTH_POSITION		270
#define IMAGE_TITLE_ROGO_HEIGHT_POSITION	220

#define IMAGE_TITLE_BUTTON_PLAY_PATH		TEXT(".\\IMAGE\\button_play.png")
#define IMAGE_TITLE_BUTTON_PLAY_WIDTH		100		//�v���C��ʃ{�^��
#define IMAGE_TITLE_BUTTON_PLAY_HEIGHT		400 

//���[���ɔ�ԃ{�^���摜
#define IMAGE_TITLE_BUTTON_RULE_PATH			TEXT(".\\IMAGE\\button_rule.png")
#define IMAGE_TITLE_BUTTON_RULE_TITLE_WIDTH		370		 //���[����ʃ{�^��
#define IMAGE_TITLE_BUTTON_RULE_TITLE_HEIGHT	400 

//�I�����邽�߂̃{�^���摜
#define IMAGE_TITLE_BUTTON_END_PATH			TEXT(".\\IMAGE\\button_end.png")
#define IMAGE_TITLE_BUTTON_END_WIDTH		640		 //�I����ʃ{�^��
#define IMAGE_TITLE_BUTTON_END_HEIGHT		400 

// �I�𒆂̃{�^���ɉ摜���̂�����
#define IMAGE_TITLE_BUTTON_NOW_PATH			TEXT(".\\IMAGE\\button_now.png")
//play�{�^���ʒu
#define IMAGE_TITLE_BUTTON_NOW_PLAY_WIDTH	100
#define IMAGE_TITLE_BUTTON_NOW_PLAY_HEIGHT	400
//lule�{�^���ʒu
#define IMAGE_TITLE_BUTTON_NOW_RULE_WIDTH	370
#define IMAGE_TITLE_BUTTON_NOW_RULE_HEIGHT	400
//end�{�^���ʒu
#define IMAGE_TITLE_BUTTON_NOW_END_WIDTH	640
#define IMAGE_TITLE_BUTTON_NOW_END_HEIGHT	400

#define IMAGE_TITLE_BUTTON_NOW_SPAN		30

//���[���摜
#define IMAGE_RULE_PATH	TEXT(".\\IMAGE\\rule.png")

//����	
#define IMAGE_END_COMP_PATH	TEXT(".\\IMAGE\\COMP_kari.png")
#define IMAGE_END_COMP_CNT	1
#define IMAGE_END_COMP_CNT_MAX	30

//���s	
#define IMAGE_END_FAIL_PATH	TEXT(".\\IMAGE\\GameOver1.png")
#define IMAGE_END_FAIL_CNT	1
#define IMAGE_END_FAIL_CNT_MAX	30

//�w�i	
//#define IMAGE_END_BACK_PATH	TEXT(".\\IMAGE\\.png")
//#define IMAGE_END_BACK_CNT	1
//#define IMAGE_END_BACK_CNT_MAX	30

//#define IMAGE_BACK_PATH_END	TEXT(".\\IMAGE\\.png")

//�Z�[�u�{�^��
#define IMAGE_MENU_BUTTON_SAVE_PATH			TEXT(".\\IMAGE\\button1.png")
#define IMAGE_MENU_BUTTON_SAVE_HEIGHT		300
#define IMAGE_MENU_BUTTON_SAVE_WIDTH		400

//�Q�[���I���{�^��
#define IMAGE_MENU_BUTTON_END_PATH		TEXT(".\\IMAGE\\button2.png")
#define IMAGE_MENU_BUTTON_END_HEIGHT	120
#define IMAGE_MENU_BUTTON_END_WIDTH		400

//���j���[��ʔw�i
#define IMAGE_MENU_PATH				TEXT(".\\IMAGE\\menu.png")
#define IMAGE_MENU_HEIGHT				25
#define IMAGE_MENU_WIDTH				260

#define IMAGE_MENU_BUTTON_NOW_PATH				TEXT(".\\IMAGE\\button_now2.png")
#define IMAGE_MENU_BUTTON_SELECT_TITLE_WIDTH	400 //�^�C�g���I�����̈ʒu
#define IMAGE_MENU_BUTTON_SELECT_TITLE_HEIGHT	120 //�^�C�g���I�����̈ʒu

//���button_now2���g���Ă�������
#define IMAGE_MENU_BUTTON_SELECT_SAVE_WIDTH		400 //�Z�[�u�I�����̈ʒu
#define IMAGE_MENU_BUTTON_SELECT_SAVE_HEIGHT	300 //�Z�[�u�I�����̈ʒu

//���v�摜�p�X
#define IMAGE_CLOCK_PATH				TEXT(".\\IMAGE\\clock.png")
#define IMAGE_CLOCK_WIDTH_PATH			750
#define IMAGE_CLOCK_HEIGHT_PATH		0

//�������ԏꏊ
#define CLOCK_TIME_WIDTH_PATH		810
#define CLOCK_TIME_HEIGHT_PATH		7

//TextBox�p�X
#define IMAGE_TEXTBOX_PATH				TEXT(".\\IMAGE\\TextBox.png")
#define IMAGE_TEXTBOX_WIDTH_PATH		0
#define IMAGE_TEXTBOX_HEIGHT_PATH		430

//TEXT�ʒu
#define TEXT_POSITION_X 150 //�e�L�X�g�|�W�V����X�̒l
#define TEXT_POSITION_Y 500 //�e�L�X�g�|�W�V����Y�̒l
#define NAME_POSITION_X 150 //�e�L�X�g�{�b�N�X���̖��O�̈ʒuX
#define NAME_POSITION_Y 450 //�e�L�X�g�{�b�N�X���̖��O�̈ʒuY 

//player�L�����`�b�v
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\chara.png")

//player�^��
#define IMAGE_PLAYER_NOMAL_PATH			TEXT(".\\IMAGE\\playerface_nomal.png")
#define IMAGE_PLAYER_NOMAL_WIDTH_PATH		15
#define IMAGE_PLAYER_NOMAL_HEIGHT_PATH		440

//player�Ί�
#define IMAGE_PLAYER_SMILE_PATH			TEXT(".\\IMAGE\\playerface_smile.png")
#define IMAGE_PLAYER_SMILE_WIDTH_PATH		15
#define IMAGE_PLAYER_SMILE_HEIGHT_PATH		440

//player���|
#define IMAGE_PLAYER_FEAR_PATH			TEXT(".\\IMAGE\\playerface_fear.png")
#define IMAGE_PLAYER_FEAR_WIDTH_PATH		15
#define IMAGE_PLAYER_FEAR_HEIGHT_PATH		440

//player�����
#define IMAGE_PLAYER_TROUBLE_PATH			TEXT(".\\IMAGE\\playerface_trouble.png")
#define IMAGE_PLAYER_TROUBLE_WIDTH_PATH		15
#define IMAGE_PLAYER_TROUBLE_HEIGHT_PATH	440

//player�����G�摜
#define IMAGE_PLAYER_ORIGINAL_PATH			TEXT(".\\IMAGE\\player_original.png");
//#define IMAGE_PLAYER_ORIGINAL_WIDTH
//#define IMAGE_PLAYER_ORIGINAL_HEIGHT

//enemy
#define IMAGE_ENEMY_PATH		TEXT(".\\IMAGE\\enemy.png")

//���y
#define MUSIC_LOAD_ERR_TITLE	TEXT("���y�ǂݍ��݃G���[")

//TITLE_BGM
#define MUSIC_BGM_PATH_TITLE		TEXT(".\\BGM.\\BGM���\\DBGM01.wav")
//PLEY_BGM
#define MUSIC_BGM_PATH			TEXT(".\\BGM.\\BGM���\\06.wav")
//COMP_BGM
//#define MUSIC_BGM_COMP_PATH		TEXT(".\\BGM\\BGM_COMP.mp3")
//END_BGM
#define MUSIC_BGM_FAIL_PATH		TEXT(".\\BGM\\�a��.mp3")
//SE_BGM
#define MUSIC_BGM_SE_PATH			TEXT(".\\BGM\\SE.mp3")

#define MUSIC_BGM_SE_OPEN_PATH			TEXT(".\\BGM\\OPEN_SE.mp3")

#define MUSIC_BGM_SE_MENU_PATH			TEXT(".\\BGM\\MENU_SE.mp3")

//MAP
#define GAME_MAP_TATE_MAX
#define GAME_MAP_YOKO_MAX
#define GAME_MAP_KIND_MAX
#define GAME_MAP_KAISO_MAX

//��������
#define GAME_TIME_LIMIT	120

#define MAP_WIDTH_MAX		29
#define MAP_HEIGHT_MAX	30
#define MAP_DIV_WIDTH		32
#define MAP_DIV_HEIGHT	32
#define MAP_DIV_TATE		64
#define MAP_DIV_YOKO		64

//MAPTHIP��������(4096)
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO

#define START_ERR_TITLE	TEXT("�X�^�[�g�ʒu�G���[")
#define START_ERR_CAPTION	TEXT("�X�^�[�g�ʒu�����܂��Ă��܂���")

#define GOAL_ERR_TITLE	TEXT("�S�[���ʒu�G���[")
#define GOAL_ERR_CAPTION	TEXT("�S�[���ʒu�����܂��Ă��܂���")

#define MOUSE_R_CLICK_TITLE	TEXT("�Q�[�����f")
#define MOUSE_R_CLICK_CAPTION	TEXT("�Q�[���𒆒f���A�^�C�g����ʂɖ߂�܂����H")

//���̝f�v��ꂽ�̂��̓���
#define MOVIE_START_PATH		TEXT(".\\MOVIE\\����.mp4")
//�N���A�ダ�[�r�[
#define MOVIE_END_PATH		TEXT(".\\MOVIE\\�Ō�.mp4")

typedef struct STRUCT_IPOINT
{
	int x = -1;
	int y = -1;
}IPOINT;

//FONT
typedef struct STRUCT_FONT
{
	char path[FONT_PATH_MAX];
	char name[FONT_PATH_MAX];
	int handle;
	int size;
	int bold;
	int type;
}FONT;

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];
	int handle[MAP_DIV_NUM];
	int kind[MAP_DIV_NUM];
	int width;
	int height;
}MAPCHIP;

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind[LAYER_MAP_DRAWKIND];
	int x;
	int y;
	int width;
	int height;

	bool IsCollisionNo;
}MAP;
