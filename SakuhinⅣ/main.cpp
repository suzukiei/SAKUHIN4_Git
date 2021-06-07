#include "DxLib.h"
#include "BGM.h"
#include "class.h"
#include "define.h"
#include "enum.h"
#include "flag.h"
#include "GameProcHeader.h"
#include "image.h"
#include "menu.h"
#include "movement.h"
#include "textevent.h"
#include "title.h"
#include "variable.h"

//�Q�[���{��
VOID GameMain(VOID);
//��ʑJ��
VOID GameSceneMove(VOID);
//�e���
VOID MY_START(VOID);
VOID MY_RULE(VOID);
VOID MY_PLAY(VOID);
VOID MY_END(VOID);

int GameScene = GAME_SCENE_START; //�Q�[���V�[��

int GameEndkind;  //�G���h���

CHARA player;   //�v���C���[
CHARA enemy;   //�G�l�~�[

MAP_CHIP mapChipRoom[8];  //���[���}�b�v�`�b�v
MAP_CHIP mapChipPass;  //�ʘH�}�b�v�`�b�v

MAP_ROOM mapRoom[8]; //�}�b�v

MAP_PASS mappass;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//--------------------------------�����ݒ�ݒ�---------------------------------
	ChangeWindowMode(TRUE);	
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_COLOR);
	SetWindowStyleMode(GAME_WINDOW_BAR);
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));

	//SetWindowIconID(IDI_ICON1);

	if (DxLib_Init() == -1) { return(-1); }
	if (MY_LOAD_IMAGE() == -1) { return(-1); }
	if (MY_LOAD_MUSIC() == -1) { return(-1); }

	SetMouseDispFlag(FALSE);

	SetDrawScreen(DX_SCREEN_BACK);


	//--------------------------------�Q�[�����[�v---------------------------------
	while (GameLoop)
	{
		if (ProcessMessage() != 0) { break; }

		if (ClearDrawScreen() != 0) { break; }

		MY_ALL_KEYDOWN_UPDATE();

		//MY_MOUSE_UPDATE();

		MY_FPS_UPDATE();

		GameMain();

		ScreenFlip();

		MY_FPS_WAIT();
	}
	ScreenFlip();

	//--------------------------------�I������---------------------------------


	MY_DELETE_IMAGE();
	MY_DELETE_MUSIC();

	DxLib_End();

	return 0;
}

void GameMain(void)
{
	GameSceneMove();
	return;
}

void GameSceneMove(void)
{
	switch (GameScene)
	{
	case GAME_SCENE_START:
		MY_START();
		break;
	case GAME_SCENE_PLAY:
		MY_PLAY();
		break;
	case GAME_SCENE_END:
		MY_END();
		break;
	case GAME_SCENE_RULE:
		MY_RULE();
		break;
	}

	return;
}

VOID MY_START(VOID)
{
	START_PROC();
	START_DRAW();
	return;
}

VOID MY_RULE(VOID)
{
	RULE_PROC();
	RULE_DRAW();
	return;
}

VOID MY_PLAY(VOID)
{
	PLAY_PROC();
	PLAY_DRAW();
	return;
}

VOID MY_END(VOID)
{
	END_PROC();
	END_DRAW();
	return;
}
