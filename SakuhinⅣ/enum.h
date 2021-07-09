#pragma once

//ゲームシーン
enum GAME_SCENE 
{
	GAME_SCENE_START,
	GAME_SCENE_PLAY,
	GAME_SCENE_END,
	GAME_SCENE_RULE
};

//ゲームエンド画面
enum GAME_END 
{
	GAME_END_COMP,
	GAME_END_FAIL
};

//メニュー選択
enum MENU_SELECT
{
	MENU_TITLE,//タイトルボタン選択時
	MENU_SAVE //セーブボタン選択時
};



//マップチップ
enum GAME_MAP_KIND
{
	//------------------------------床--------------------------------------
	MAP_FLOOR1 = 0,
	MAP_FLOOR2 = 2,
	//------------------------------壁--------------------------------------
	MAP_WALL_GRAY = 1344,
	MAP_WALL_BLACK = 1408,
	MAP_WALL_UP = 2240,
	MAP_WALL_MIDDLE = 2304,
	MAP_WALL_DOWN = 2368,
	MAP_BOOKSHELF1_UP = 1089,
	MAP_BOOKSHELF2_UP = 1090,
	MAP_BOOKSHELF3_UP = 1091,
	MAP_BOOKSHELF1_DOWN = 1153,
	MAP_BOOKSHELF2_DOWN = 1154,
	MAP_BOOKSHELF3_DOWN = 1155,
	//------------------------------小物--------------------------------------
	MAP_CHEST1 = 960,
	MAP_CHEST2 = 961,
	MAP_CHEST3= 962,
	MAP_BOOK1 = 1410,
	MAP_BOOK2 = 1411,
	MAP_BOOK3 = 1472,
	MAP_BOOK4 = 1473,
	MAP_BOOK5 = 1474,
	MAP_BOOK6 = 1536,
	MAP_CD = 1603,
	MAP_CLOSET1_UP = 704,
	MAP_CLOSET2_UP = 705,
	MAP_CLOSET3_UP = 706,
	MAP_CLOSET1_DOWN = 768,
	MAP_CLOSET2_DOWN = 769,
	MAP_CLOSET3_DOWN = 770,
	//ギミックの動かすやつ
	MAP_CARDBOARD = 1158,
	//ギミックのボタン
	MAP_DOLL = 3328,
	//ギミックの地雷
	MAP_MINE = 2738,
	//------------------------------血--------------------------------------
	//ギミック移動　前
	MAP_BLOOD_ARROW_FORNT = 299,
	//ギミック移動　左
	MAP_BLOOD_ARROW_LEFT = 297,
	//ギミック移動　右
	MAP_BLOOD_ARROW_RIGHT = 296,
	//ギミック移動　後ろ
	MAP_BLOOD_ARROW_BACK = 298,
	MAP_BLOOD_FOOTPOINT_FORNT1 = 234,
	MAP_BLOOD_FOOTPOINT_FORNT2 = 235,
	MAP_BLOOD_FOOTPOINT_LEFT1 = 236,
	MAP_BLOOD_FOOTPOINT_LEFT2 = 237,
	MAP_BLOOD_FOOTPOINT_RIGHT1 = 238,
	MAP_BLOOD_FOOTPOINT_RIGHT2 = 239,
	MAP_BLOOD_FOOTPOINT_BOTTOM1 = 300,
	MAP_BLOOD_FOOTPOINT_BOTTOM2 = 301,
	MAP_BLOOD_ROME1 = 2352,
	MAP_BLOOD_ROME2 = 2353,
	MAP_BLOOD_ROME3 = 2354,
	MAP_BLOOD_ROME4 = 2355,
	MAP_BLOOD_ROME5 = 2356,
	MAP_BLOOD_ROME6 = 2357,
	MAP_BLOOD_ROME7 = 2358,
	MAP_BLOOD_ROME8 = 2359,
	MAP_BLOOD_ROME9 = 2416,
	MAP_BLOOD_ROME10 = 2417,
	MAP_BLOOD_ROME11 = 2418,
	MAP_BLOOD_ROME12 = 2419,
	MAP_BLOOD_ALPHA_A = 426,
	MAP_BLOOD_ALPHA_B = 427,
	MAP_BLOOD_ALPHA_C = 428,
	MAP_BLOOD_ALPHA_D = 429,
	MAP_BLOOD_ALPHA_E = 430,
	MAP_BLOOD_ALPHA_F = 431,
	MAP_BLOOD_ALPHA_G = 488,
	MAP_BLOOD_ALPHA_H = 489,
	MAP_BLOOD_ALPHA_I = 490,
	MAP_BLOOD_ALPHA_J = 491,
	MAP_BLOOD_ALPHA_K = 492,
	MAP_BLOOD_ALPHA_L = 493,
	MAP_BLOOD_ALPHA_M = 494,  
	MAP_BLOOD_ALPHA_N = 495,
	MAP_BLOOD_ALPHA_O = 552,
	MAP_BLOOD_ALPHA_P = 553,
	MAP_BLOOD_ALPHA_Q = 554,
	MAP_BLOOD_ALPHA_R = 555,
	MAP_BLOOD_ALPHA_S = 556,
	MAP_BLOOD_ALPHA_T = 557,
	MAP_BLOOD_ALPHA_U = 558,
	MAP_BLOOD_ALPHA_V = 559,
	MAP_BLOOD_ALPHA_W = 616,
	MAP_BLOOD_ALPHA_X = 617,
	MAP_BLOOD_ALPHA_Y = 618,
	MAP_BLOOD_ALPHA_Z = 619,
	MAP_BLOOD_CIRCLE = 2089,
	MAP_BLOOD_CROSS = 2092,
	MAP_BLOOD_eye_UP = 1651,
	MAP_BLOOD_eye_RIGHT = 1588,
	MAP_BLOOD_eye_LEFT = 1587,
	MAP_BLOOD_eye_BOTTOM = 1589,
	MAP_BLOOD_MAGICCIRCLE = 691,
	MAP_BLOOD_MAGICCIRCLE1 = 880,
	MAP_BLOOD_MAGICCIRCLE2 = 881,
	MAP_BLOOD_MAGICCIRCLE3 = 882,
	MAP_BLOOD_MAGICCIRCLE4 = 944,
	MAP_BLOOD_MAGICCIRCLE5 = 945,
	MAP_BLOOD_MAGICCIRCLE6 = 946,
	MAP_BLOOD_MAGICCIRCLE7 = 1008,
	MAP_BLOOD_MAGICCIRCLE8 = 1009,
	MAP_BLOOD_MAGICCIRCLE9 = 1010,
	MAP_BLOOD_LAKE1 = 743,
	MAP_BLOOD_LAKE2 = 744,
	MAP_BLOOD_LAKE3 = 745,
	MAP_BLOOD_LAKE4 = 746,
	MAP_BLOOD_LAKE5 = 747,
	MAP_BLOOD_LAKE6 = 808,
	MAP_BLOOD_LAKE7 = 809,
	MAP_BLOOD_LAKE8 = 810,
	MAP_BLOOD_LAKE9 = 811,
	MAP_BLOOD_LAKE10 = 812,
	MAP_BLOOD_LAKE11 = 872,
	MAP_BLOOD_LAKE12 = 873,
	MAP_BLOOD_LAKE13 = 874,
	MAP_BLOOD_LAKE14 = 875,
	MAP_BLOOD_LAKE15 = 876,
	MAP_BLOOD_LAKE16 = 936,
	MAP_BLOOD_LAKE17 = 937,
	MAP_BLOOD_LAKE18 = 938,
	MAP_BLOOD_LAKE19 = 939,
	MAP_BLOOD_LAKE20 = 940,
	MAP_BLOOD_LAKE21 = 1000,
	MAP_BLOOD_LAKE22 = 1001,
	MAP_BLOOD_LAKE23 = 1002,
	MAP_BLOOD_LAKE24 = 1003,
	MAP_BLOOD_LAKE25 = 1004,




	//------------------------------重ね血--------------------------------------

};

//enum GAME_MOVE_CARDBOARD
//{
//	MAP_CARDBOARD = 1158
//};

//enum GAME_BUTTON_DOLL
//{
//	MAP_DOLL = 3328
//};

enum GAME_MAP_WARP
{
	WARP_1 = 361,
	WARP_2 = 362,
	WARP_3 = 363,
	WARP_4 = 364,
	WARP_5 = 365,
	WARP_6 = 366,
	WARP_7 = 367,
	WARP_8 = 424,
	WARP_9 = 425,
	WARP_A = 426,
	WARP_B = 427,
	WARP_C = 428,
	WARP_D = 429,
	WARP_E = 430
};

enum GAME_MAP_COLLISION
{
	COLL_EXISTS = 39,
	COLL_NOEXSITS = 103
};

enum GAME_SG
{
	START = 556,
	GOAL = 488
};

//ギミック
enum GAME_GIMMICK_KIND
{
	GIMMICK_BUTTON,//ボタン
	GIMMICK_WARP,//ワープ
	GIMMICK_MINE,//地雷
	GIMMICK_PAZLE,//モノを動かす
	GIMMICK_MAZE,//迷路
	GIMMICK_MOVE//強制移動
};

enum GAME_LAYER_KIND
{
	LAYER_MAP_TOP,//一番上のレイヤー
	LAYER_MAP_MIDDLE,//真ん中のレイヤー
	LAYER_MAP_UNDER,//一番下のレイヤー
	LAYER_MAP_DRAWKIND,//描画するレイヤー数

	LAYER_MAP_GIMMICK,//ギミックのレイヤー
	LAYER_MAP_RECT,//当たり判定のレイヤー
	LAYER_MAP_SG//スタートゴールのレイヤー
};