#include "DxLib.h"
#include "BGM.h"
#include "enum.h"
#include "variable.h"


MUSIC BGM_TITLE;
MUSIC BGM_PLAY;
MUSIC BGM_COMP;
MUSIC BGM_END;
MUSIC BGM_SE;

VOID TITLE_BGM(VOID)
{
	//����BGM������Ă��Ȃ��Ȃ痬��
	if (CheckSoundMem(BGM_TITLE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_TITLE.GetHandle(), DX_PLAYTYPE_LOOP);
	}

	//����BGM_PLAY������Ă�����~�߂�
	if (CheckSoundMem(BGM_PLAY.GetHandle() != 0))
	{
		StopSoundMem(BGM_PLAY.GetHandle());
	}
	//����BGM_COMP������Ă�����~�߂�
	if (CheckSoundMem(BGM_COMP.GetHandle() != 0))
	{
		StopSoundMem(BGM_COMP.GetHandle());
	}
	//����BGM_END������Ă�����~�߂�
	if (CheckSoundMem(BGM_END.GetHandle() != 0))
	{
		StopSoundMem(BGM_END.GetHandle());
	}

	return;
}

VOID PLAY_BGM(VOID)
{
	if (CheckSoundMem(BGM_PLAY.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_PLAY.GetHandle(), DX_PLAYTYPE_LOOP);
	}

	//�^�C�g��BGM������Ă�����~�߂�
	if (CheckSoundMem(BGM_TITLE.GetHandle() != 0))
	{
		StopSoundMem(BGM_TITLE.GetHandle());
	}

	return;
}

VOID END_BGM(VOID)
{
	//����BGM_PLAY������Ă�����~�߂�
	if (CheckSoundMem(BGM_PLAY.GetHandle() != 0))
	{
		StopSoundMem(BGM_PLAY.GetHandle());
	}

	switch (GameEndkind)
	{
	case GAME_END_COMP:
		if (CheckSoundMem(BGM_COMP.GetHandle()) == 0)
		{
			PlaySoundMem(BGM_COMP.GetHandle(), DX_PLAYTYPE_LOOP);
		}
		break;

	case GAME_END_FAIL:
		if (CheckSoundMem(BGM_END.GetHandle()) == 0)
		{
			PlaySoundMem(BGM_END.GetHandle(), DX_PLAYTYPE_LOOP);
		}
	}
	return;
}

VOID SE_BGM(VOID)
{
	if (CheckSoundMem(BGM_SE.GetHandle()) == 0)
	{
		PlaySoundMem(BGM_SE.GetHandle(), DX_PLAYTYPE_LOOP);
	}

	//if (CheckSoundMem(BGM_SE.GetHandle() != 0))
	//{
	//	StopSoundMem(BGM_SE.GetHandle());
	//}

	return;
}

//BGM�ǂݍ��ݏ���
BOOL MY_LOAD_MUSIC(VOID)
{
	BGM_TITLE.SetPath(MUSIC_BGM_PATH_TITLE);
	BGM_TITLE.SetHandle(LoadSoundMem(BGM_TITLE.GetPath()));
	if (BGM_TITLE.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH_TITLE, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}


	BGM_PLAY.SetPath(MUSIC_BGM_PATH);
	BGM_PLAY.SetHandle(LoadSoundMem(BGM_PLAY.GetPath()));
	if (BGM_PLAY.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_COMP.SetPath(MUSIC_BGM_COMP_PATH);
	BGM_COMP.SetHandle(LoadSoundMem(BGM_COMP.GetPath()));
	if (BGM_COMP.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_END.SetPath(MUSIC_BGM_FAIL_PATH);
	BGM_END.SetHandle(LoadSoundMem(BGM_END.GetPath()));
	if (BGM_END.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_FAIL_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	BGM_SE.SetPath(MUSIC_BGM_SE_PATH);
	BGM_SE.SetHandle(LoadSoundMem(BGM_SE.GetPath()));
	if (BGM_SE.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_SE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}

	//����I�����邽�߂�TRUE
	return TRUE;
}

//BGM�폜����
BOOL MY_DELETE_MUSIC(VOID)
{
	BGM_TITLE.DeleteHandle();
	BGM_PLAY.DeleteHandle();
	BGM_COMP.DeleteHandle();
	BGM_END.DeleteHandle();
	BGM_SE.DeleteHandle();

	//����I�����邽�߂�TRUE
	return TRUE;
}