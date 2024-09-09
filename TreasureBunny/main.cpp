#include"DxLib.h"
#include"CommonData.h"
#include"BaseScene.h"
#include"SceneManager.h"
#include"Fps.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}
	SetMainWindowText("TreasureBunny");
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(1280, 1024, 32);
	ChangeWindowMode(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);	//����ʉ�

	//���s0.1�`1300�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1300.0f);
	//�t�H���g�ǂݍ���
	LPCSTR font_path = "Font/RocknRollOne-Regular.ttf";//�t�H���g�p�X

	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0)
	{
	}
	else
	{
		// �t�H���g�Ǎ��G���[����
		printfDx("�t�H���g��ǂݍ��ݎ��s");
	}
	//����
	SceneManager* sceneManager=new SceneManager();
	Fps* fps = new Fps();

	//----------------//
	//���C�����[�v
	//----------------//
	while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{

		//FPS
		fps->Update();
		sceneManager->Update();
		sceneManager->Draw();
		//// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

		////�I������
		//�V�[�����G���h�ɂȂ��Ă��鎞������
		if (sceneManager->ChangeScene()==true||CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		//�ҋ@
		fps->Wait();

	}
	RemoveFontResourceEx(font_path, FR_PRIVATE, NULL);

	// �c�w���C�u�����̌�n��
	DxLib_End();
	// �\�t�g�̏I��
	return 0;

}