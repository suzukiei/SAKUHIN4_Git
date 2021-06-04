#include "DxLib.h"
#include "define.h"
#include "enum.h"
#include "class.h"
#include "variable.h"
#include "GameProcHeader.h"
#include "image.h"

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

//---------------------------------------------------�摜�̓ǂݍ��݁�----------------------------------------------------------


//IMAGE�̓ǂݍ���
BOOL MY_LOAD_IMAGE(VOID)
{
	//�^�C�g���w�i�̓ǂݍ���
	ImageTitleBk.SetPath(IMAGE_TITLE_BK_PATH);
	ImageTitleBk.SetHandle(LoadGraph(ImageTitleBk.GetPath()) );
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

	////�G���h��ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	//ButtonEnd.SetPath(IMAGE_TITLE_BUTTON_END_PATH);
	//ButtonEnd.SetHandle(LoadGraph(ButtonEnd.GetPath()));
	//if (ButtonEnd.GetPath() == ERR)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	////���[����ʂ֑J�ڂ��邽�߂̃{�^���̓ǂݍ���
	//ButtonRule.SetPath(IMAGE_TITLE_BUTTON_RULE_PATH);
	//ButtonRule.SetHandle(LoadGraph(ButtonRule.GetPath()));
	//if (ButtonRule.GetPath() == ERR)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_RULE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	////�{�^���I���摜�̓ǂݍ���
	//ButtonNow.SetPath(IMAGE_TITLE_BUTTON_NOW_PATH);
	//ButtonNow.SetHandle(LoadGraph(ButtonNow.GetPath()));
	//if (ButtonNow.GetPath() == ERR)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BUTTON_NOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

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
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���j���[�{�^��2�̓ǂݍ���
	ButtonMenu2.SetPath(IMAGE_MENU_BUTTON_END_PATH);
	ButtonMenu2.SetHandle(LoadGraph(ButtonMenu1.GetPath()));
	if (ButtonNow.GetPath() == ERR)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BUTTON_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

}


//csv�̓ǂݍ���
BOOL MY_LOAD_CSV_MAP(VOID)
{
	//�}�b�v�`�b�v��ǂݍ���
	if (MY_LOAD_MAPCHIP() == FALSE) { return -1; }

	//csv��ǂݍ���
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_FLOOR)) { return -1; }	  //�X�e�[�W�P��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_WALL)) { return -1; }    //�X�e�[�W�P��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_BLOOD)) { return -1; }   //�X�e�[�W�P��
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_SBLOOD)) { return -1; }  //�X�e�[�W�P�d�ˌ�
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_ACCES)) { return -1; }   //�X�e�[�W�P����
	if (MY_LOAD_CSV_MAP(GAME_CSV_PATH_STAGE2_RECT)) { return -1; }    //�X�e�[�W�P�����蔻��

	return TRUE;
}

//---------------------------------------------------�摜�`�恫----------------------------------------------------------

//�X�^�[�g��ʂ̕`�揈��
VOID MY_START_DRAW(VOID)
{
	DrawGraph(0, 0, ImageTitleBk.GetHandle(), TRUE);

	return;
}

//���[����ʂ̕`�揈��
VOID MY_RULE_DRAW(VOID)
{
	//DrawGraph(0, 0, , TRUE);

	return;
}

//�v���C��ʂ̕`�揈��
VOID MY_PLAY_DRAW(VOID)
{
	//�}�b�v�̕`��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			DrawGraph(mapRoom[player.nowRoom].map[tate][yoko].x - player.CenterX,
				mapRoom[player.nowRoom].map[tate][yoko].y - player.CenterY,
				mapChipRoom[player.nowRoom].mapchip[tate][yoko].handle[mapRoom[player.nowRoom].map[tate][yoko].kind],
				TRUE
			);
		}
	}

	//�v���C���[�\��
	DrawGraph(
		player.CenterX,
		player.CenterY,
		player.handle[player.kind1],
		TRUE
	);

	return;
}

//�G���h��ʂ̕`�揈��
VOID MY_END_DRAW(VOID)
{
	DrawGraph(0, 0, ImageEndBk.GetHandle(), TRUE);

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




////�}�b�v�̖�����ݒ�
//for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++) {
//	for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++) {
//		MAP* p = m + tate * GAME_MAP_YOKO_MAX + yoko;
//		MAP* pInit = mInit + tate * GAME_MAP_YOKO_MAX + yoko;
//
//		p->kind = MAP_KIND_TURO;
//
//		for (int cnt = 0; cnt < MAP_JIMEN_KIND; cnt++) {
//			if (p->value == MapJimenID[cnt]) {
//				p->kind = MAP_KIND_KABE;
//				break;
//			}
//		}
//
//		for (int cnt = 0; cnt < MAP_GUILD_KIND; cnt++) {
//			if (p->value == MapGuildID[cnt]) {
//				p->kind = MAP_KIND_GUILD;
//				break;
//			}
//		}
//
//		if (p->value == MapKanbanID)
//		{
//			p->kind = MAP_KIND_KANBAN;
//		}
//
//		//�}�b�v�ʒu����
//		p->x = yoko * MAP_DIV_WIDTH;
//		p->y = tate * MAP_DIV_HEIGHT;
//		p->width = MAP_DIV_WIDTH;
//		p->height = MAP_DIV_HEIGHT;
//		pInit = p;
//	}
//}