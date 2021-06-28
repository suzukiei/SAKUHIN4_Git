#define _CRT_SECURE_NO_WARNINGS

#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "image.h"

#include<stdio.h>

#define ERR ("")

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
IMAGE ButtonNow;
IMAGE ButtonMenu1;
IMAGE ButtonMenu2;


//MAP_CHIP mapChipRoom[8];  //���[���}�b�v�`�b�v
//MAP_CHIP mapChipPass;  //�ʘH�}�b�v�`�b�v

CHARA charaChip;

MAP_ROOM mapRoom[8]; //�}�b�v

MAP_PASS mappass;
//---------------------------------------------------�摜�̓ǂݍ��݁�----------------------------------------------------------


//IMAGE�̓ǂݍ���
BOOL MY_LOAD_IMAGE(VOID)
{
	//�^�C�g���w�i�̓ǂݍ���
	ImageTitleBk.SetPath(IMAGE_TITLE_BK_PATH);
	ImageTitleBk.SetHandle(LoadGraph(ImageTitleBk.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�^�C�g�����S�̓ǂݍ���
	ImageTitleRogo.SetPath(IMAGE_TITLE_ROGO_PATH);
	ImageTitleRogo.SetHandle(LoadGraph(ImageTitleRogo.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���[���w�i�̓ǂݍ���
	ImageRule.SetPath(IMAGE_RULE_PATH);
	ImageRule.SetHandle(LoadGraph(ImageRule.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_RULE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���j���[�̓ǂݍ���
	ImageMenu.SetPath(IMAGE_MENU_PATH);
	ImageMenu.SetHandle(LoadGraph(ImageMenu.GetPath()));
	if (ImageTitleBk.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	////�G���h�w�i�̓ǂݍ���
	//ImageEndBk.SetPath(IMAGE_END_BK_PATH);
	//ImageEndBk.SetHandle(LoadGraph(ImageEndBk.GetPath()));
	//if (ImageEndBk.GetPath() == ERR)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_END_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	////�G���h�����̓ǂݍ���
	ImageEndComp.SetPath(IMAGE_END_COMP_PATH);
	ImageEndComp.SetHandle(LoadGraph(ImageEndComp.GetPath()));
	if (ImageEndComp.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	////�G���h���s�̓ǂݍ���
	ImageEndFail.SetPath(IMAGE_END_FAIL_PATH);
	ImageEndFail.SetHandle(LoadGraph(ImageEndFail.GetPath()));
	if (ImageEndFail.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_FAIL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�v���C��ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	ButtonPlay.SetPath(IMAGE_TITLE_BUTTON_PLAY_PATH);
	ButtonPlay.SetHandle(LoadGraph(ButtonPlay.GetPath()));
	if (ButtonPlay.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_PLAY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�G���h��ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	ButtonEnd.SetPath(IMAGE_TITLE_BUTTON_END_PATH);
	ButtonEnd.SetHandle(LoadGraph(ButtonEnd.GetPath()));
	if (ButtonEnd.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���[����ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	ButtonRule.SetPath(IMAGE_TITLE_BUTTON_RULE_PATH);
	ButtonRule.SetHandle(LoadGraph(ButtonRule.GetPath()));
	if (ButtonRule.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_RULE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�{�^���I���摜�̓ǂݍ���
	ButtonNow.SetPath(IMAGE_TITLE_BUTTON_NOW_PATH);
	ButtonNow.SetHandle(LoadGraph(ButtonNow.GetPath()));
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_NOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�{�^���I���摜�̓ǂݍ���
	ButtonNow.SetPath(IMAGE_TITLE_BUTTON_NOW_PATH);
	ButtonNow.SetHandle(LoadGraph(ButtonNow.GetPath()));
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_NOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���j���[�{�^���P�̓ǂݍ���
	ButtonMenu1.SetPath(IMAGE_MENU_BUTTON_PATH);
	ButtonMenu1.SetHandle(LoadGraph(ButtonMenu1.GetPath()));
	if (ButtonMenu1.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//���j���[�{�^��2�̓ǂݍ���
	ButtonMenu2.SetPath(IMAGE_MENU_BUTTON_END_PATH);
	ButtonMenu2.SetHandle(LoadGraph(ButtonMenu1.GetPath()));
	if (ButtonMenu2.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//�v���C���[�̓ǂݍ���
	int charaChip = LoadDivGraph(
		IMAGE_PLAYER_PATH,
		PLAYER_DIV_NUM, PLAYER_DIV_YOKO, PLAYER_DIV_TATE,
		PLAYER_WIDTH, PLAYER_HEIGHT,
		player.handle);

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
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE1_GIMMICK, &mapRoom[0], GIMMICK_BUTTON) == FALSE)
	{
		MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
		return -1;
	}

	//-----------------------------�X�e�[�W2----------------------------------------------
	////��
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_FLOOR, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
	//	return -1;
	//}
	////��
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_WALL, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
	//	return -1;
	//}
	////����
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_ACCES, &mapRoom[0], LAYER_MAP_UNDER) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
	//	return -1;
	//}
	////��
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_BLOOD, &mapRoom[0], LAYER_MAP_MIDDLE) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
	//	return -1;
	//}
	////�d�ˌ�
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SBLOOD, &mapRoom[0], LAYER_MAP_TOP) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
	//	return -1;
	//}
	//////�����蔻��
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_RECT, &mapRoom[0], LAYER_MAP_RECT) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
	//	return -1;
	//}
	//////�X�^�[�g�S�[��
	//if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SG, &mapRoom[0], LAYER_MAP_SG) == FALSE)
	//{
	//	MessageBox(GetMainWindowHandle(), "����[", "����[", MB_OK);
	//	return -1;
	//}


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
			
			if (Layer == LAYER_MAP_UNDER || Layer == LAYER_MAP_MIDDLE || Layer == LAYER_MAP_TOP)
			{
				mapData = room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind;

				//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
				result = fscanf(fp, "%d,", &room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind);

				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].width = mapChip.width;
				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].height = mapChip.height;

				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].x = LoopCnt % MAP_WIDTH_MAX * mapChip.width;
				room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].y = LoopCnt / MAP_WIDTH_MAX * mapChip.height;

				if (room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind == -1)
				{
					room->map[Layer][LoopCnt / MAP_WIDTH_MAX][LoopCnt % MAP_WIDTH_MAX].kind = mapData;
				}
			}
			
			//�M�~�b�N
			else if (Layer == LAYER_MAP_GIMMICK)
			{
				result = fscanf(fp, "%d,", &mapData);
			}
			//�X�^�[�g�S�[��
			else if (Layer == LAYER_MAP_SG)
			{
				result = fscanf(fp, "%d,", &mapData);
			}
			//�����蔻��
			else if (Layer == LAYER_MAP_RECT)
			{
				result = fscanf(fp, "%d,", &mapData);
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
	DrawGraph(TITLE_BUTTON_PLAY_WIDTH_POSITION, TITLE_BUTTON_PLAY_HEIGHT_POSITION, ButtonPlay.GetHandle(), TRUE);
	DrawGraph(TITLE_BUTTON_LULE_TITLE_WIDTH_POSITION, TITLE_BUTTON_LULE_TITLE_HEIGHT_POSITION, ButtonRule.GetHandle(), TRUE);
	DrawGraph(TITLE_BUTTON_END_WIDTH_POSITION, TITLE_BUTTON_END_HEIGHT_POSITION, ButtonEnd.GetHandle(), TRUE);

	return;
}

//���[����ʂ̕`�揈��
VOID RULE_DRAW(VOID)
{
	DrawGraph(0, 0, ImageRule.GetHandle(), TRUE);

	return;
}

//�v���C��ʂ̕`�揈��
VOID PLAY_DRAW(VOID)
{
	player.nowRoom = 0;
	//�}�b�v�̕`��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			if (mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].kind != -1)
			{
				//���̃��C���[
				DrawGraph
				(
					mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].x,
					mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].y,
					mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_UNDER][tate][yoko].kind],
					TRUE
				);
			}
			if(mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].kind != -1)
			{ 
			//���̃��C���[
			DrawGraph
			(
				mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].x,
				mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].y,
				mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_MIDDLE][tate][yoko].kind],
				TRUE
			);
			}

			if (mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].kind != -1)
			{
				//�d�ˌ��̃��C���[
				DrawGraph
				(
					mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].x,
					mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].y,
					mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_TOP][tate][yoko].kind],
					TRUE
				);
			}

			if (mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].kind != -1)
			{
				//�M�~�b�N�̃��C���[�H
				DrawGraph
				(
					mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].x,
					mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].y,
					mapChip.handle[mapRoom[player.nowRoom].map[LAYER_MAP_GIMMICK][tate][yoko].kind],
					TRUE
				);
			}

		}
	}

	//�v���C���[�\��
	DrawGraph(
		player.CenterX ,
		player.CenterY ,
		player.handle[player.kind1],
		TRUE
	);

	return;
}

//�G���h��ʂ̕`�揈��
VOID END_DRAW(VOID)
{
	//DrawGraph(0, 0, ImageEndBk.GetHandle(), TRUE); //�G���h�w�i

	switch (GameEndkind)
	{
	case GAME_END_COMP: //�������
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
	ButtonNow.DeleteHandle();
	ButtonMenu1.DeleteHandle();
	ButtonMenu2.DeleteHandle();
}

