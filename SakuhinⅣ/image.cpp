#define _CRT_SECURE_NO_WARNINGS

#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "image.h"
#include "textevent.h"

#include<stdio.h>

#define ERR -1

MAPCHIP mapChip;

IMAGE ImageTitleBk;
IMAGE ImageTitleRogo;
IMAGE ImageEndBk;
IMAGE ImageEndComp;
IMAGE ImageEndFail;
IMAGE ImageRule;
IMAGE ImageMenu;
IMAGE ButtonPlay;
IMAGE ButtonEnd;
IMAGE ButtonRule;
IMAGE ButtonTitleNow;
IMAGE ButtonMenuNow;
IMAGE ButtonMenuSave;
IMAGE ButtonMenuEnd;
IMAGE Clock;
IMAGE TextBox;
IMAGE PlayerNomal;
IMAGE PlayerSmile;
IMAGE PlayerFear;
IMAGE PlayerTrouble;


//MAP_CHIP mapChipRoom[8];  //���[���}�b�v�`�b�v
//MAP_CHIP mapChipPass;  //�ʘH�}�b�v�`�b�v


MAP_ROOM mapRoom[ROOM_NUM]; //�}�b�v

MAP_PASS mappass; //�ʘH
//---------------------------------------------------�摜�̓ǂݍ��݁�----------------------------------------------------------


//IMAGE�̓ǂݍ���
BOOL MY_LOAD_IMAGE(VOID)
{
	//�^�C�g���w�i�̓ǂݍ���
	ImageTitleBk.SetPath(IMAGE_TITLE_BK_PATH);
	ImageTitleBk.SetHandle(LoadGraph(ImageTitleBk.GetPath()));
	if (ImageTitleBk.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�^�C�g�����S�̓ǂݍ���
	ImageTitleRogo.SetPath(IMAGE_TITLE_ROGO_PATH);
	ImageTitleRogo.SetHandle(LoadGraph(ImageTitleRogo.GetPath()));
	if (ImageTitleBk.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���[���w�i�̓ǂݍ���
	ImageRule.SetPath(IMAGE_RULE_PATH);
	ImageRule.SetHandle(LoadGraph(ImageRule.GetPath()));
	if (ImageRule.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_RULE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���j���[�̓ǂݍ���
	ImageMenu.SetPath(IMAGE_MENU_PATH);
	ImageMenu.SetHandle(LoadGraph(ImageMenu.GetPath()));
	if (ImageMenu.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	////�G���h�w�i�̓ǂݍ���
	//ImageEndBk.SetPath(IMAGE_END_BK_PATH);
	//ImageEndBk.SetHandle(LoadGraph(ImageEndBk.GetPath()));
	//if (ImageEndBk.GetHandle() == ERR)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_END_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	////�G���h�����̓ǂݍ���
	ImageEndComp.SetPath(IMAGE_END_COMP_PATH);
	ImageEndComp.SetHandle(LoadGraph(ImageEndComp.GetPath()));
	if (ImageEndComp.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	////�G���h���s�̓ǂݍ���
	ImageEndFail.SetPath(IMAGE_END_FAIL_PATH);
	ImageEndFail.SetHandle(LoadGraph(ImageEndFail.GetPath()));
	if (ImageEndFail.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_FAIL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�v���C��ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	ButtonPlay.SetPath(IMAGE_TITLE_BUTTON_PLAY_PATH);
	ButtonPlay.SetHandle(LoadGraph(ButtonPlay.GetPath()));
	if (ButtonPlay.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_PLAY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�G���h��ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	ButtonEnd.SetPath(IMAGE_TITLE_BUTTON_END_PATH);
	ButtonEnd.SetHandle(LoadGraph(ButtonEnd.GetPath()));
	if (ButtonEnd.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���[����ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	ButtonRule.SetPath(IMAGE_TITLE_BUTTON_RULE_PATH);
	ButtonRule.SetHandle(LoadGraph(ButtonRule.GetPath()));
	if (ButtonRule.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_RULE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�^�C�g����ʃ{�^���I���摜�̓ǂݍ���
	ButtonTitleNow.SetPath(IMAGE_TITLE_BUTTON_NOW_PATH);
	ButtonTitleNow.SetHandle(LoadGraph(ButtonTitleNow.GetPath()));
	if (ButtonTitleNow.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_NOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���j���[�{�^���I���摜�̓ǂݍ���
	ButtonMenuNow.SetPath(IMAGE_MENU_BUTTON_NOW_PATH);
	ButtonMenuNow.SetHandle(LoadGraph(ButtonMenuNow.GetPath()));
	if (ButtonMenuNow.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_NOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���j���[(�Z�[�u�{�^��)�̓ǂݍ���
	ButtonMenuSave.SetPath(IMAGE_MENU_BUTTON_SAVE_PATH);
	ButtonMenuSave.SetHandle(LoadGraph(ButtonMenuSave.GetPath()));
	if (ButtonMenuSave.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_SAVE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//���j���[(�I���{�^��)�̓ǂݍ���
	ButtonMenuEnd.SetPath(IMAGE_MENU_BUTTON_END_PATH);
	ButtonMenuEnd.SetHandle(LoadGraph(ButtonMenuEnd.GetPath()));
	if (ButtonMenuEnd.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���v�̓ǂݍ���
	Clock.SetPath(IMAGE_CLOCK_PATH);
	Clock.SetHandle(LoadGraph(Clock.GetPath()));
	if (Clock.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_CLOCK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�e�L�X�g�̓ǂݍ���
	TextBox.SetPath(IMAGE_TEXTBOX_PATH);
	TextBox.SetHandle(LoadGraph(TextBox.GetPath()));
	if (TextBox.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TEXTBOX_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�^��̓ǂݍ���
	PlayerNomal.SetPath(IMAGE_PLAYER_NOMAL_PATH);
	PlayerNomal.SetHandle(LoadGraph(PlayerNomal.GetPath()));
	if (PlayerNomal.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_NOMAL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�Ί�̓ǂݍ���
	PlayerSmile.SetPath(IMAGE_PLAYER_SMILE_PATH);
	PlayerSmile.SetHandle(LoadGraph(PlayerSmile.GetPath()));
	if (PlayerSmile.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_SMILE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�����̓ǂݍ���
	PlayerFear.SetPath(IMAGE_PLAYER_FEAR_PATH);
	PlayerFear.SetHandle(LoadGraph(PlayerFear.GetPath()));
	if (PlayerFear.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_FEAR_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�^��̓ǂݍ���
	PlayerTrouble.SetPath(IMAGE_PLAYER_TROUBLE_PATH);
	PlayerTrouble.SetHandle(LoadGraph(PlayerNomal.GetPath()));
	if (PlayerTrouble.GetHandle() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_TROUBLE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�v���C���[�̓ǂݍ���
	int charaChip = LoadDivGraph(
		IMAGE_PLAYER_PATH,
		PLAYER_DIV_NUM, PLAYER_DIV_YOKO, PLAYER_DIV_TATE,
		PLAYER_WIDTH, PLAYER_HEIGHT,
		player.handle);
	for (int i = 0; i < PLAYER_DIV_NUM; i++)
	{
		if (player.handle[i] == ERR)
		{
			MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
	}

	//�G�̓ǂݍ���
	int enemyChip = LoadDivGraph(
		IMAGE_ENEMY_PATH,
		ENEMY_DIV_NUM, ENEMY_DIV_YOKO, ENEMY_DIV_TATE,
		ENEMY_WIDTH, ENEMY_HEIGHT,
		enemy.handle);
	for (int i = 0; i < ENEMY_DIV_NUM; i++)
	{
		if (enemy.handle[i] == ERR)
		{
			MessageBox(GetMainWindowHandle(), IMAGE_ENEMY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
	}

	//if (charaChip == ERR) {
	//	MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	//�}�b�v�`�b�v�̓ǂݍ���

	if (MY_LOAD_MAPCHIP() == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}



	//csv�̓ǂݍ���

	//-----------------------------�X�e�[�W�P----------------------------------------------
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_FLOOR, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_WALL, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//����
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_ACCES, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_BLOOD, &mapRoom[0], LAYER_MAP_MIDDLE) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//�d�ˌ�
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SBLOOD, &mapRoom[0], LAYER_MAP_TOP) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�����蔻��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_RECT, &mapRoom[0], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_SG, &mapRoom[0], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//�M�~�b�N
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_GIMMICK, &mapRoom[0], LAYER_MAP_GIMMICK) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	mapRoom[0].gimmick = GIMMICK_BUTTON;

	//-----------------------------�X�e�[�W2----------------------------------------------
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_FLOOR, &mapRoom[1], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_WALL, &mapRoom[1], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//����
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_ACCES, &mapRoom[1], LAYER_MAP_MIDDLE) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_BLOOD, &mapRoom[1], LAYER_MAP_TOP) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//�d�ˌ�
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SBLOOD, &mapRoom[1], LAYER_MAP_TOP) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�����蔻��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_RECT, &mapRoom[1], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SG, &mapRoom[1], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	mapRoom[1].gimmick = GIMMICK_MAZE;


	//-----------------------------�X�e�[�W3----------------------------------------------
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE3_FLOOR, &mapRoom[2], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE3_WALL, &mapRoom[2], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE3_BLOOD, &mapRoom[2], LAYER_MAP_TOP) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�����蔻��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE3_RECT, &mapRoom[2], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE3_SG, &mapRoom[2], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}

	//�M�~�b�N
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE3_GIMMICK, &mapRoom[3], LAYER_MAP_GIMMICK) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	mapRoom[2].gimmick = GIMMICK_MOVE;

	//-----------------------------�X�e�[�W4----------------------------------------------
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE4_FLOOR, &mapRoom[3], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE4_WALL, &mapRoom[3], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}

	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE4_ACCES, &mapRoom[3], LAYER_MAP_TOP) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}

	////�����蔻��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE4_RECT, &mapRoom[3], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE4_SG, &mapRoom[3], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}

	//�M�~�b�N
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE4_GIMMICK, &mapRoom[3], LAYER_MAP_GIMMICK) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	mapRoom[3].gimmick = GIMMICK_MINE;

	//-----------------------------�X�e�[�W5----------------------------------------------
//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_FLOOR, &mapRoom[4], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_WALL, &mapRoom[4], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//����
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_ACCES, &mapRoom[4], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_BLOOD, &mapRoom[4], LAYER_MAP_MIDDLE) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//�d�ˌ�
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_SBLOOD, &mapRoom[4], LAYER_MAP_TOP) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�����蔻��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_RECT, &mapRoom[4], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_SG, &mapRoom[4], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//�M�~�b�N
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE5_GIMMICK, &mapRoom[4], LAYER_MAP_GIMMICK) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	mapRoom[4].gimmick = GIMMICK_WARP;

	//-----------------------------�X�e�[�W6----------------------------------------------
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE6_FLOOR, &mapRoom[5], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE6_WALL, &mapRoom[5], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}

	////�����蔻��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE6_RECT, &mapRoom[5], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE6_SG, &mapRoom[5], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	mapRoom[5].gimmick = GIMMICK_MAZE;


	//-----------------------------�X�e�[�W7----------------------------------------------
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE7_FLOOR, &mapRoom[6], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE7_WALL, &mapRoom[6], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//����
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE7_ACCES, &mapRoom[6], LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�����蔻��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE7_RECT, &mapRoom[6], LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE7_SG, &mapRoom[6], LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//�M�~�b�N
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE7_GIMMICK, &mapRoom[6], LAYER_MAP_GIMMICK) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	mapRoom[6].gimmick = GIMMICK_PAZZLE;


	//-----------------------------�ʘH----------------------------------------------
	//��
	if (MY_LOAD_CSV_PASS(GAME_CSV_PATH_STAGEPASS_FLOOR, &mappass, LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	//��
	if (MY_LOAD_CSV_PASS(GAME_CSV_PATH_STAGEPASS_WALL, &mappass, LAYER_MAP_UNDER) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�����蔻��
	if (MY_LOAD_CSV_PASS(GAME_CSV_PATH_STAGEPASS_RECT, &mappass, LAYER_MAP_RECT) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}
	////�X�^�[�g�S�[��
	if (MY_LOAD_CSV_PASS(GAME_CSV_PATH_STAGEPASS_SG, &mappass, LAYER_MAP_SG) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}


	return TRUE;
}


//csv�̓ǂݍ���
BOOL MY_LOAD_CSV(VOID)
{
	//�}�b�v�`�b�v��ǂݍ���
	if (MY_LOAD_MAPCHIP() == FALSE) { return -1; }

	return TRUE;
}

BOOL MY_LOAD_MAPCHIP()
{
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,
		mapChip.handle);

	if (mapRes == -1)
	{
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);
	//mapChip.width = MAP
	return TRUE;
}

/// <summary>
/// �}�b�v�̓ǂݍ���
/// </summary>
/// <param name="room">�K�w�̍\���̂̃|�C���^</param>
/// <param name="path">�}�b�v�̃p�X</param>
/// <returns></returns>
BOOL MY_LOAD_CSV_MAP(const char* path,MAP_ROOM* room,int Layer)
{
	FILE* fp;

	errno_t error;
	int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
	int LoopCnt = 0;        //���[�v�J�E���^

	//csv�t�@�C�����J��
	error = fopen_s(&fp, path, "r");
	if (error != 0)
	{
		MessageBox(GetMainWindowHandle(), path, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	else
	{
		result = 0;
		LoopCnt = 0;

		while (result != EOF)    //End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
		{
			GAME_MAP_KIND mapData;
			GAME_MAP_KIND indata;
			
			if (Layer == LAYER_MAP_UNDER || Layer == LAYER_MAP_MIDDLE || Layer == LAYER_MAP_TOP)
			{
				mapData = room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer];

				//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
				result = fscanf(fp, "%d,", &indata);

				if (result != EOF )
				{
					room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer] = indata;

					room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].width = mapChip.width;
					room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].height = mapChip.height;

					room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x = LoopCnt % MAP_WIDTH_MAX * mapChip.width;
					room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y = LoopCnt / MAP_WIDTH_MAX * mapChip.height;

					if (room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer] == -1)
					{
						room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer] = mapData;
					}
				}
			}
			
			//�M�~�b�N
			else if (Layer == LAYER_MAP_GIMMICK)
			{
				result = fscanf(fp, "%d,", &mapData);
				if (result != EOF)
					GIMMICK_OBJ_SET(LoopCnt % MAP_WIDTH_MAX, LoopCnt / MAP_WIDTH_MAX, mapData);

			}
			//�X�^�[�g�S�[��
			else if (Layer == LAYER_MAP_SG)
			{
				result = fscanf(fp, "%d,", &mapData);
				if (result != EOF)
				{
					//�X�^�[�g���W
					if (mapData == START)
					{
						room->StartPt = { LoopCnt % MAP_WIDTH_MAX,LoopCnt / MAP_WIDTH_MAX };
					}
					//�S�[�����W
					if (mapData == GOAL)
					{
						room->GoalPt = { LoopCnt % MAP_WIDTH_MAX,LoopCnt / MAP_WIDTH_MAX };
					}
				}

			}
			//�����蔻��
			else if (Layer == LAYER_MAP_RECT)
			{
				result = fscanf(fp, "%d,", &mapData);
				if (result != EOF)
				{
					mapColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].top = room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y ;
					mapColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].right= room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x + mapChip.width;
					mapColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].bottom = room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y + mapChip.height;
					mapColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].left = room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x;
					//�����蔻��Z
					if (mapData == COLL_EXISTS)
					{
						room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].IsCollisionNo = FALSE; //�Z�͓����蔻�肪�Ȃ�����FALSE
					}
					//�����蔻��~
					if (mapData == COLL_NOEXSITS)
					{
						room->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].IsCollisionNo = TRUE; //�~�͓����蔻�肪���邩��TRUE
					}
				}

			}
			LoopCnt++;
		}

		fclose(fp);
	}

	return TRUE;
}

/// <summary>
/// �ʘH�̓ǂݍ���
/// </summary>
/// <param name="room">�K�w�̍\���̂̃|�C���^</param>
/// <param name="path">�}�b�v�̃p�X</param>
/// <returns></returns>
BOOL MY_LOAD_CSV_PASS(const char* path, MAP_PASS* pass, int Layer)
{
	FILE* fp;

	errno_t error;
	int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
	int LoopCnt = 0;        //���[�v�J�E���^

	//csv�t�@�C�����J��
	error = fopen_s(&fp, path, "r");
	if (error != 0)
	{
		MessageBox(GetMainWindowHandle(), path, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	else
	{
		result = 0;
		LoopCnt = 0;

		while (result != EOF)    //End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
		{
			GAME_MAP_KIND mapData;
			GAME_MAP_KIND indata;

			if (Layer == LAYER_MAP_UNDER || Layer == LAYER_MAP_MIDDLE || Layer == LAYER_MAP_TOP)
			{
				mapData = pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer];

				//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
				result = fscanf(fp, "%d,", &indata);

				if (result != EOF)
				{
					pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer] = indata;

					pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].width = mapChip.width;
					pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].height = mapChip.height;

					pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x = LoopCnt % MAP_WIDTH_MAX * mapChip.width;
					pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y = LoopCnt / MAP_WIDTH_MAX * mapChip.height;

					if (pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer] == -1)
					{
						pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind[Layer] = mapData;
					}
				}
			}

			//�M�~�b�N
			else if (Layer == LAYER_MAP_GIMMICK)
			{
				result = fscanf(fp, "%d,", &mapData);
				if (result != EOF)
				{
					GIMMICK_OBJ_SET(LoopCnt % MAP_WIDTH_MAX, LoopCnt / MAP_WIDTH_MAX, mapData);
				}
			}
			//�X�^�[�g�S�[��
			else if (Layer == LAYER_MAP_SG)
			{
				result = fscanf(fp, "%d,", &mapData);
				if (result != EOF)
				{
					//�X�^�[�g���W
					if (mapData == START)
					{
						pass->StartPt = { LoopCnt % MAP_WIDTH_MAX,LoopCnt / MAP_WIDTH_MAX };
					}
					//�S�[�����W
					if (mapData == GOAL)
					{
						pass->GoalPt = { LoopCnt % MAP_WIDTH_MAX,LoopCnt / MAP_WIDTH_MAX };
					}
				}
			}
			//�����蔻��
			else if (Layer == LAYER_MAP_RECT)
			{
				result = fscanf(fp, "%d,", &mapData);
				if (result != EOF)
				{

					mapPassColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].top = pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y;
					mapPassColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].right = pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x + mapChip.width;
					mapPassColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].bottom = pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y + mapChip.height;
					mapPassColl[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].left = pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x;

					if (mapData == COLL_EXISTS)
					{
						pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].IsCollisionNo = FALSE; //�Z�͓����蔻�肪�Ȃ�����FALSE
					}
					//�S�[�����W
					if (mapData == COLL_NOEXSITS)
					{
						pass->map[LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].IsCollisionNo = TRUE; //�~�͓����蔻�肪���邩��TRUE
					}
				}
			}
			LoopCnt++;
		}

		fclose(fp);
	}

	return TRUE;
}

//---------------------------------------------------�摜�`�恫----------------------------------------------------------
//�X�^�[�g��ʂ̕`�揈��
VOID START_DRAW(VOID)
{
	DrawGraph(0, 0, ImageTitleBk.GetHandle(), TRUE);
	DrawGraph(IMAGE_TITLE_ROGO_WIDTH_POSITION, IMAGE_TITLE_ROGO_HEIGHT_POSITION, ImageTitleRogo.GetHandle(), TRUE);
	DrawGraph(IMAGE_TITLE_BUTTON_PLAY_WIDTH, IMAGE_TITLE_BUTTON_PLAY_HEIGHT, ButtonPlay.GetHandle(), TRUE);
	DrawGraph(IMAGE_TITLE_BUTTON_RULE_TITLE_WIDTH, IMAGE_TITLE_BUTTON_RULE_TITLE_HEIGHT, ButtonRule.GetHandle(), TRUE);
	DrawGraph(IMAGE_TITLE_BUTTON_END_WIDTH, IMAGE_TITLE_BUTTON_END_HEIGHT, ButtonEnd.GetHandle(), TRUE);
	//�X�^�[�g�{�^���Əd�Ȃ����Ƃ�
	if (TITLE_SELECT_NO == TITLE_START)
	{
		DrawGraph(IMAGE_TITLE_BUTTON_NOW_PLAY_WIDTH, IMAGE_TITLE_BUTTON_NOW_PLAY_HEIGHT, ButtonTitleNow.GetHandle(), TRUE);
	}
	//���[���{�^���Əd�Ȃ����Ƃ�
	if (TITLE_SELECT_NO == TITLE_RULE)
	{
		DrawGraph(IMAGE_TITLE_BUTTON_NOW_RULE_WIDTH, IMAGE_TITLE_BUTTON_NOW_RULE_HEIGHT, ButtonTitleNow.GetHandle(), TRUE);
	}
	//�G���h�{�^���Əd�Ȃ����Ƃ�
	if (TITLE_SELECT_NO == TITLE_QUIT)
	{
		DrawGraph(IMAGE_TITLE_BUTTON_NOW_END_WIDTH, IMAGE_TITLE_BUTTON_NOW_END_HEIGHT, ButtonTitleNow.GetHandle(), TRUE);
	}

	return;
}

//���[����ʂ̕`�揈��
VOID RULE_DRAW(VOID)
{
	DrawGraph(0, 0, ImageRule.GetHandle(), TRUE);

	return;
}

//����̕`�揈��
VOID MOVIE_DRAW(VOID)
{
	PlayMovie(GAME_MOVIE_PATH, 1, DX_MOVIEPLAYTYPE_NORMAL);
	GameScene = GAME_SCENE_PLAY;
	return;
}

//�v���C��ʂ̕`�揈��
VOID PLAY_DRAW(VOID)
{

	if (player.InRoom)
	{
		//�}�b�v�̕`��
		for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
		{
			for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
			{
				if (mapRoom[player.nowRoom].map[tate][yoko].kind[LAYER_MAP_UNDER] != -1)
				{
					//���̃��C���[
					DrawGraph
					(
						mapRoom[player.nowRoom].map[tate][yoko].x - (player.CenterX - (GAME_WIDTH / 2)),
						mapRoom[player.nowRoom].map[tate][yoko].y - (player.CenterY - (GAME_HEIGHT / 2)),
						mapChip.handle[mapRoom[player.nowRoom].map[tate][yoko].kind[LAYER_MAP_UNDER]],
						TRUE
					);
				}
				if (mapRoom[player.nowRoom].map[tate][yoko].kind[LAYER_MAP_MIDDLE] != -1)
				{
					//���̃��C���[
					DrawGraph
					(
						mapRoom[player.nowRoom].map[tate][yoko].x - (player.CenterX - (GAME_WIDTH / 2)),
						mapRoom[player.nowRoom].map[tate][yoko].y - (player.CenterY - (GAME_HEIGHT / 2)),
						mapChip.handle[mapRoom[player.nowRoom].map[tate][yoko].kind[LAYER_MAP_MIDDLE]],
						TRUE
					);
				}

				if (mapRoom[player.nowRoom].map[tate][yoko].kind[LAYER_MAP_TOP] != -1)
				{
					//�d�ˌ��̃��C���[
					DrawGraph
					(
						mapRoom[player.nowRoom].map[tate][yoko].x - (player.CenterX - (GAME_WIDTH / 2)),
						mapRoom[player.nowRoom].map[tate][yoko].y - (player.CenterY - (GAME_HEIGHT / 2)),
						mapChip.handle[mapRoom[player.nowRoom].map[tate][yoko].kind[LAYER_MAP_TOP]],
						TRUE
					);
				}

				GIMMICK_DRAW();
			}
		}
	}
	else if (player.InPass)
	{
		//�}�b�v�̕`��
		for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
		{
			for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
			{
				if (mappass.map[tate][yoko].kind[LAYER_MAP_UNDER] != -1)
				{
					//���̃��C���[
					DrawGraph
					(
						mappass.map[tate][yoko].x - (player.CenterX - (GAME_WIDTH / 2)),
						mappass.map[tate][yoko].y - (player.CenterY - (GAME_HEIGHT / 2)),
						mapChip.handle[mappass.map[tate][yoko].kind[LAYER_MAP_UNDER]],
						TRUE
					);
				}
				if (mappass.map[tate][yoko].kind[LAYER_MAP_MIDDLE] != -1)
				{
					//���̃��C���[
					DrawGraph
					(
						mappass.map[tate][yoko].x - (player.CenterX - (GAME_WIDTH / 2)),
						mappass.map[tate][yoko].y - (player.CenterY - (GAME_HEIGHT / 2)),
						mapChip.handle[mappass.map[tate][yoko].kind[LAYER_MAP_MIDDLE]],
						TRUE
					);
				}

				if (mappass.map[tate][yoko].kind[LAYER_MAP_TOP] != -1)
				{
					//�d�ˌ��̃��C���[
					DrawGraph
					(
						mappass.map[tate][yoko].x - (player.CenterX - (GAME_WIDTH / 2)),
						mappass.map[tate][yoko].y - (player.CenterY - (GAME_HEIGHT / 2)),
						mapChip.handle[mappass.map[tate][yoko].kind[LAYER_MAP_TOP]],
						TRUE
					);
				}

			}
		}
	}

	//�v���C���[�\��
	DrawGraph
	(
		(GAME_WIDTH / 2) - mapChip.width / 2,
		(GAME_HEIGHT / 2) - mapChip.height /2 - mapChip.height / 3,
		player.handle[player.kind1],
		TRUE
	);


	SetFontSize(50);
	if (GAME_TIME_LIMIT - TimeCounter.NOW() >= 0)
	{
		DrawFormatString(CLOCK_TIME_WIDTH_PATH, CLOCK_TIME_HEIGHT_PATH, GetColor(255, 255, 255), "%d", GAME_TIME_LIMIT - TimeCounter.NOW());
	}
	else if (GAME_TIME_LIMIT - TimeCounter.NOW() < 0 && player.InRoom)
	{
		//�G�\��
		DrawGraph
		(
			enemy.image.x - (player.image.x - (GAME_WIDTH / 2)),
			enemy.image.y - (ENEMY_HEIGHT - mapChip.height) - (player.image.y - (GAME_HEIGHT / 2)),
			enemy.handle[enemy.kind1],
			TRUE
		);
		
		int workX = (TimeCounter.NOW() - GAME_TIME_LIMIT) * ((WINDOW_WIDTH / 2) / GAME_TIME_LIMIT);
		int workY = (TimeCounter.NOW() - GAME_TIME_LIMIT) * ((WINDOW_HEIGHT / 2) / GAME_TIME_LIMIT);

			//�Èł̕\����
			DrawBox(0, 0, WINDOW_WIDTH, workY, GetColor(0, 0, 0), TRUE);
			//�Èł̕\����
			DrawBox(0, WINDOW_HEIGHT - workY, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), TRUE);
			//�Èł̕\����
			DrawBox(0, 0, workX, WINDOW_HEIGHT, GetColor(0, 0, 0), TRUE);
			//�Èł̕\���E
			DrawBox(WINDOW_WIDTH - workX, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), TRUE);

		DrawFormatString(CLOCK_TIME_WIDTH_PATH, CLOCK_TIME_HEIGHT_PATH, GetColor(255, 0, 0), "%d", GAME_TIME_LIMIT - TimeCounter.NOW());
	}

	DrawGraph(IMAGE_CLOCK_WIDTH_PATH, IMAGE_CLOCK_HEIGHT_PATH, Clock.GetHandle(), TRUE);

	if (IsDrawText == TRUE)
	{
		DRAW_TEXT();
	}


	return;
}

//���j���[��ʂ̕`�揈��
VOID MENU_DRAW(VOID)
{		
	DrawGraph(IMAGE_MENU_WIDTH, IMAGE_MENU_HEIGHT, ImageMenu.GetHandle(), TRUE);
	if (player.InPass)
	{
		DrawGraph(IMAGE_MENU_BUTTON_SAVE_WIDTH, IMAGE_MENU_BUTTON_SAVE_HEIGHT, ButtonMenuSave.GetHandle(), TRUE);
	}
	DrawGraph(IMAGE_MENU_BUTTON_END_WIDTH, IMAGE_MENU_BUTTON_END_HEIGHT, ButtonMenuEnd.GetHandle(), TRUE);
	//�{�^�����G���h�{�^���ɏd�Ȃ��Ă�
	if (SELECT == MENU_TITLE)
	{
		DrawGraph(IMAGE_MENU_BUTTON_SELECT_TITLE_WIDTH, IMAGE_MENU_BUTTON_SELECT_TITLE_HEIGHT, ButtonMenuNow.GetHandle(), TRUE);
	}
	//�{�^�����Z�[�u�{�^���ɏd�Ȃ��Ă�
	if (SELECT == MENU_SAVE)
	{
		DrawGraph(IMAGE_MENU_BUTTON_SELECT_SAVE_WIDTH, IMAGE_MENU_BUTTON_SELECT_SAVE_HEIGHT, ButtonMenuNow.GetHandle(), TRUE);
	}
}

//�G���h��ʂ̕`�揈��
VOID END_DRAW(VOID)
{
	//DrawGraph(0, 0, ImageEndBk.GetHandle(), TRUE); //�G���h�w�i

	switch (GameEndkind)
	{
	case GAME_END_COMP: //�������
		PlayMovie(GAME_MOVIE_END_PATH, 1, DX_MOVIEPLAYTYPE_NORMAL);
		DrawGraph(0, 0, ImageEndComp.GetHandle(), TRUE);
		break;

	case GAME_END_FAIL: //���s���
		DrawGraph(0, 0, ImageEndFail.GetHandle(), TRUE);
		break;

	default:
		break;
	}

	return;
}



//----------------------------------------------------�摜�̍폜��-----------------------------------------------------------

//�摜�̍폜
VOID MY_DELETE_IMAGE(VOID)
{
	ImageTitleBk.DeleteHandle();
	ImageTitleRogo.DeleteHandle();
	ImageEndBk.DeleteHandle();
	ImageEndComp.DeleteHandle();
	ImageEndFail.DeleteHandle();
	ImageRule.DeleteHandle();
	ImageMenu.DeleteHandle();
	ButtonPlay.DeleteHandle();
	ButtonEnd.DeleteHandle();
	ButtonRule.DeleteHandle();
	ButtonMenuNow.DeleteHandle();
	ButtonMenuSave.DeleteHandle();
	ButtonMenuEnd.DeleteHandle();
	Clock.DeleteHandle();
	TextBox.DeleteHandle();
	PlayerNomal.DeleteHandle();
	PlayerSmile.DeleteHandle();
	PlayerFear.DeleteHandle();
	PlayerTrouble.DeleteHandle();
}

