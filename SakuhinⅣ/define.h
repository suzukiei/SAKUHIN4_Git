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
#define IMAGE_TITLE_ROGO_PATH				TEXT(".\\IMAGE\\karilogo.png")
#define IMAGE_TITLE_BUTTON_PLAY_PATH		TEXT(".\\IMAGE\\button_play.png")
//ルールに飛ぶボタン画像
#define IMAGE_TITLE_BUTTON_RULE_PATH		TEXT(".\\IMAGE\\button_lule.png")
//終了するためのボタン画像
#define IMAGE_TITLE_BUTTON_END_PATH			TEXT(".\\IMAGE\\button_end.png")
// 選択中のボタンに画像をのっける
#define IMAGE_TITLE_BUTTON_NOW_PATH			TEXT(".\\IMAGE\\button_now.png")
#define IMAGE_TITLE_BUTTON_SPAN		30

//ルール画像
#define IMAGE_RULE_PATH	TEXT(".\\IMAGE\\lule.png")


//成功	
#define IMAGE_END_COMP_PATH	TEXT(".\\IMAGE\\COMP_kari.png")
#define IMAGE_END_COMP_CNT	1
#define IMAGE_END_COMP_CNT_MAX	30

//失敗	
#define IMAGE_END_FAIL_PATH	TEXT(".\\IMAGE\\GameOver1.\\IMAGE\\.png")
#define IMAGE_END_FAIL_CNT	1
#define IMAGE_END_FAIL_CNT_MAX	30

//背景	
//#define IMAGE_END_BACK_PATH	TEXT(".\\IMAGE\\.png")
//#define IMAGE_END_BACK_CNT	1
//#define IMAGE_END_BACK_CNT_MAX	30

//#define IMAGE_BACK_PATH_END	TEXT(".\\IMAGE\\.png")

#define MENU_WIDTH_POSITION 280 //メニュー背景
#define MENU_HEIGHT_POSITION 180 //メニュー背景
#define MENU_BUTTON_TITLE_WIDTH_POSITION 380 //タイトルへ戻るボタンの位置
#define MENU_BUTTON_TITLE_HEIGHT_POSITION 280 //タイトルへ戻るボタンの位置
#define MENU_BUTTON_SAVE_WIDTH_POSITION 380 //セーブボタンの位置
#define MENU_BUTTON_SAVE_HEIGHT_POSITION 380 //セーブボタンの位置
#define MENU_BUTTON_SELECT_TITLE_WIDTH_POSITION 370 //タイトル選択時の位置
#define MENU_BUTTON_SELECT_TITLE_HEIGHT_POSITION 270 //タイトル選択時の位置
#define MENU_BUTTON_SELECT_SAVE_WIDTH_POSITION 370 //セーブ選択時の位置
#define MENU_BUTTON_SELECT_SAVE_HEIGHT_POSITION 370 //セーブ選択時の位置

//メニュー時の画像パス
#define IMAGE_MENU_BUTTON_PATH			TEXT(".\\IMAGE\\.button1.png")
#define IMAGE_MENU_BUTTON_END_PATH		TEXT(".\\IMAGE\\.button2.png")
#define IMAGE_MENU_PATH				TEXT(".\\IMAGE\\menu.png")

//player
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\chara.png")

//enemy
#define IMAGE_ENEMY_PATH		TEXT(".\\IMAGE\\enemy.png")

//音楽
#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")

//TITLE_BGM
#define MUSIC_BGM_PATH_TITLE		TEXT(".\\BGM\\famipop3.mp3")
//PLEY_BGM
#define MUSIC_BGM_PATH			TEXT(".\\BGM\\famipop3.mp3")
//COMP_BGM
#define MUSIC_BGM_COMP_PATH		TEXT(".\\BGM\\famipop3.mp3")
//END_BGM
#define MUSIC_BGM_FAIL_PATH		TEXT(".\\BGM\\famipop3.mp3")

//MAP
#define GAME_MAP_TATE_MAX
#define GAME_MAP_YOKO_MAX
#define GAME_MAP_KIND_MAX
#define GAME_MAP_KAISO_MAX

//制限時間
#define GAME_TIME_LIMIT	60

#define MAP_WIDTH_MAX		30
#define MAP_HEIGHT_MAX	29
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
	GAME_MAP_KIND kind;
	int x;
	int y;
	int width;
	int height;

	bool IsCollisionNo;
}MAP;
