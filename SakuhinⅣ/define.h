#pragma once

#include"enum.h"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 560
#define GAME_WIDTH 960
#define GAME_HEIGHT 560
#define GAME_COLOR 32

#define GAME_WINDOW_BAR 0

//GAME_NAME
#define GAME_WINDOW_NAME "暗闇の眼"

//FPS
#define GAME_FPS	60

#define KEY_BUTTON_CODE 129

//PATH
#define PATH_MAX	255
#define NAME_MAX	255

//FONT
#define FONT_PATH_MAX			255
//#define FONT_PATH			TEXT(".ttf")
//#define FONT_NAME			TEXT("font名前")
#define FONT_INSTALL_ERR_TITLE	TEXT("フォントインストールエラー")
#define FONT_CREATE_ERR_TITLE	TEXT("フォント作成エラー")

//画像読み込みエラー
#define IMAGE_LOAD_ERR_TITLE TEXT("画像読み込みエラー")

//画像パス
#define IMAGE_TITLE_BK_PATH				TEXT(".\\IMAGE\\title_back.png")
#define IMAGE_TITLE_ROGO_PATH				TEXT(".\\IMAGE\\Titlelogo.png")

//logo場所指定
#define IMAGE_TITLE_ROGO_WIDTH_POSITION		270
#define IMAGE_TITLE_ROGO_HEIGHT_POSITION	220

#define IMAGE_TITLE_BUTTON_PLAY_PATH		TEXT(".\\IMAGE\\button_play.png")
#define IMAGE_TITLE_BUTTON_PLAY_WIDTH		100		//プレイ画面ボタン
#define IMAGE_TITLE_BUTTON_PLAY_HEIGHT		400 

//ルールに飛ぶボタン画像
#define IMAGE_TITLE_BUTTON_RULE_PATH			TEXT(".\\IMAGE\\button_rule.png")
#define IMAGE_TITLE_BUTTON_RULE_TITLE_WIDTH		370		 //ルール画面ボタン
#define IMAGE_TITLE_BUTTON_RULE_TITLE_HEIGHT	400 

//終了するためのボタン画像
#define IMAGE_TITLE_BUTTON_END_PATH			TEXT(".\\IMAGE\\button_end.png")
#define IMAGE_TITLE_BUTTON_END_WIDTH		640		 //終了画面ボタン
#define IMAGE_TITLE_BUTTON_END_HEIGHT		400 

// 選択中のボタンに画像をのっける
#define IMAGE_TITLE_BUTTON_NOW_PATH			TEXT(".\\IMAGE\\button_now.png")
//playボタン位置
#define IMAGE_TITLE_BUTTON_NOW_PLAY_WIDTH	100
#define IMAGE_TITLE_BUTTON_NOW_PLAY_HEIGHT	400
//luleボタン位置
#define IMAGE_TITLE_BUTTON_NOW_RULE_WIDTH	370
#define IMAGE_TITLE_BUTTON_NOW_RULE_HEIGHT	400
//endボタン位置
#define IMAGE_TITLE_BUTTON_NOW_END_WIDTH	640
#define IMAGE_TITLE_BUTTON_NOW_END_HEIGHT	400

#define IMAGE_TITLE_BUTTON_NOW_SPAN		30

//ルール画像
#define IMAGE_RULE_PATH	TEXT(".\\IMAGE\\rule.png")

//成功	
#define IMAGE_END_COMP_PATH	TEXT(".\\IMAGE\\COMP_kari.png")
#define IMAGE_END_COMP_CNT	1
#define IMAGE_END_COMP_CNT_MAX	30

//失敗	
#define IMAGE_END_FAIL_PATH	TEXT(".\\IMAGE\\GameOver1.png")
#define IMAGE_END_FAIL_CNT	1
#define IMAGE_END_FAIL_CNT_MAX	30

//背景	
//#define IMAGE_END_BACK_PATH	TEXT(".\\IMAGE\\.png")
//#define IMAGE_END_BACK_CNT	1
//#define IMAGE_END_BACK_CNT_MAX	30

//#define IMAGE_BACK_PATH_END	TEXT(".\\IMAGE\\.png")

//セーブボタン
#define IMAGE_MENU_BUTTON_SAVE_PATH			TEXT(".\\IMAGE\\button1.png")
#define IMAGE_MENU_BUTTON_SAVE_HEIGHT		300
#define IMAGE_MENU_BUTTON_SAVE_WIDTH		400

//ゲーム終了ボタン
#define IMAGE_MENU_BUTTON_END_PATH		TEXT(".\\IMAGE\\button2.png")
#define IMAGE_MENU_BUTTON_END_HEIGHT	120
#define IMAGE_MENU_BUTTON_END_WIDTH		400

//メニュー画面背景
#define IMAGE_MENU_PATH				TEXT(".\\IMAGE\\menu.png")
#define IMAGE_MENU_HEIGHT				25
#define IMAGE_MENU_WIDTH				260

#define IMAGE_MENU_BUTTON_NOW_PATH				TEXT(".\\IMAGE\\button_now2.png")
#define IMAGE_MENU_BUTTON_SELECT_TITLE_WIDTH	400 //タイトル選択時の位置
#define IMAGE_MENU_BUTTON_SELECT_TITLE_HEIGHT	120 //タイトル選択時の位置

//上のbutton_now2を使ってください
#define IMAGE_MENU_BUTTON_SELECT_SAVE_WIDTH		400 //セーブ選択時の位置
#define IMAGE_MENU_BUTTON_SELECT_SAVE_HEIGHT	300 //セーブ選択時の位置

//時計画像パス
#define IMAGE_CLOCK_PATH				TEXT(".\\IMAGE\\clock.png")
#define IMAGE_CLOCK_WIDTH_PATH			750
#define IMAGE_CLOCK_HEIGHT_PATH		0

//制限時間場所
#define CLOCK_TIME_WIDTH_PATH		810
#define CLOCK_TIME_HEIGHT_PATH		7

//TextBoxパス
#define IMAGE_TEXTBOX_PATH				TEXT(".\\IMAGE\\TextBox.png")
#define IMAGE_TEXTBOX_WIDTH_PATH		0
#define IMAGE_TEXTBOX_HEIGHT_PATH		430

//TEXT位置
#define TEXT_POSITION_X 150 //テキストポジションXの値
#define TEXT_POSITION_Y 500 //テキストポジションYの値
#define NAME_POSITION_X 150 //テキストボックス内の名前の位置X
#define NAME_POSITION_Y 450 //テキストボックス内の名前の位置Y 

//playerキャラチップ
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\chara.png")

//player真顔
#define IMAGE_PLAYER_NOMAL_PATH			TEXT(".\\IMAGE\\playerface_nomal.png")
#define IMAGE_PLAYER_NOMAL_WIDTH_PATH		15
#define IMAGE_PLAYER_NOMAL_HEIGHT_PATH		440

//player笑顔
#define IMAGE_PLAYER_SMILE_PATH			TEXT(".\\IMAGE\\playerface_smile.png")
#define IMAGE_PLAYER_SMILE_WIDTH_PATH		15
#define IMAGE_PLAYER_SMILE_HEIGHT_PATH		440

//player恐怖
#define IMAGE_PLAYER_FEAR_PATH			TEXT(".\\IMAGE\\playerface_fear.png")
#define IMAGE_PLAYER_FEAR_WIDTH_PATH		15
#define IMAGE_PLAYER_FEAR_HEIGHT_PATH		440

//player困り顔
#define IMAGE_PLAYER_TROUBLE_PATH			TEXT(".\\IMAGE\\playerface_trouble.png")
#define IMAGE_PLAYER_TROUBLE_WIDTH_PATH		15
#define IMAGE_PLAYER_TROUBLE_HEIGHT_PATH	440

//player立ち絵画像
#define IMAGE_PLAYER_ORIGINAL_PATH			TEXT(".\\IMAGE\\player_original.png");
//#define IMAGE_PLAYER_ORIGINAL_WIDTH
//#define IMAGE_PLAYER_ORIGINAL_HEIGHT

//enemy
#define IMAGE_ENEMY_PATH		TEXT(".\\IMAGE\\enemy.png")

//音楽
#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")

//TITLE_BGM
#define MUSIC_BGM_PATH_TITLE		TEXT(".\\BGM.\\BGM候補\\DBGM01.wav")
//PLEY_BGM
#define MUSIC_BGM_PATH			TEXT(".\\BGM.\\BGM候補\\06.wav")
//COMP_BGM
//#define MUSIC_BGM_COMP_PATH		TEXT(".\\BGM\\BGM_COMP.mp3")
//END_BGM
#define MUSIC_BGM_FAIL_PATH		TEXT(".\\BGM\\軋み.mp3")
//SE_BGM
#define MUSIC_BGM_SE_PATH			TEXT(".\\BGM\\SE.mp3")

#define MUSIC_BGM_SE_OPEN_PATH			TEXT(".\\BGM\\OPEN_SE.mp3")

#define MUSIC_BGM_SE_MENU_PATH			TEXT(".\\BGM\\MENU_SE.mp3")

//MAP
#define GAME_MAP_TATE_MAX
#define GAME_MAP_YOKO_MAX
#define GAME_MAP_KIND_MAX
#define GAME_MAP_KAISO_MAX

//制限時間
#define GAME_TIME_LIMIT	120

#define MAP_WIDTH_MAX		29
#define MAP_HEIGHT_MAX	30
#define MAP_DIV_WIDTH		32
#define MAP_DIV_HEIGHT	32
#define MAP_DIV_TATE		64
#define MAP_DIV_YOKO		64

//MAPTHIP分割する(4096)
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO

#define START_ERR_TITLE	TEXT("スタート位置エラー")
#define START_ERR_CAPTION	TEXT("スタート位置が決まっていません")

#define GOAL_ERR_TITLE	TEXT("ゴール位置エラー")
#define GOAL_ERR_CAPTION	TEXT("ゴール位置が決まっていません")

#define MOUSE_R_CLICK_TITLE	TEXT("ゲーム中断")
#define MOUSE_R_CLICK_CAPTION	TEXT("ゲームを中断し、タイトル画面に戻りますか？")

//何故拉致られたのかの動画
#define MOVIE_START_PATH		TEXT(".\\MOVIE\\序章.mp4")
//クリア後ムービー
#define MOVIE_END_PATH		TEXT(".\\MOVIE\\最後.mp4")

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
