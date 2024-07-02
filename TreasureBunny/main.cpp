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
	ChangeWindowMode(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);	//����ʉ�

	//���s0.1�`1300�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1300.0f);
	//�t�H���g�ǂݍ���
	//LPCSTR font_path = "Font/851MkPOP_101.ttf";//�t�H���g�p�X
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
	//GameStatus gameStatus =GameStatus::Title;
	//TitleAndEnd* titleEnd = new TitleAndEnd();
	//UiManager* uiManager = new UiManager();
	//EffectManager* effectManager = new EffectManager();
	//Player* player = new Player();
	//Camera* camera = new Camera();
	//Map* map = new Map();
	//Collision* collision=new Collision();
	//Pause* pause = new Pause();
	//SoundManager* soundManager = new SoundManager();
	//CountDown* countDown = new CountDown();
	Fps* fps = new Fps();
	//bool isFadeOut = false;						//�Â����邩
	//bool isHitGool = false;						//�S�[���ɓ���������
	
	////������
	//player->LoadModel();
	//player->Initialize();
	//titleEnd->Initialize();

	//----------------//
	//���C�����[�v
	//----------------//
	while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{

		//FPS
		fps->Update();
		sceneManager->Update();
		sceneManager->Draw();
		////�Q�[���I��
		//if (gameStatus == GameStatus::End)
		//{
		//	break;
		//}

		////�^�C�g��
		//if (gameStatus == GameStatus::Title)
		//{
		//	titleEnd->titleset(*map, *camera, *player, *collision, gameStatus, *uiManager, *effectManager,*soundManager, isFadeOut,isHitGool);

		//	if (gameStatus == GameStatus::Game)
		//	{
		//		player->Initialize();
		//		map->SetMap();
		//		camera->UpDate(*player);
		//		countDown->SetTime();
		//		uiManager->Initialize();
		//		isHitGool = false;
		//	}
		//}
		////�Q�[���N���A
		//if (gameStatus == GameStatus::Gameclear)
		//{
		//	titleEnd->GameClearSet(*map, *camera, *player, *collision, gameStatus, *uiManager, *effectManager, *soundManager, isFadeOut);
		//	if (gameStatus == GameStatus::Title)
		//	{
		//		player->Initialize();
		//		map->Initialize();
		//		camera->Initialize();
		//		camera->UpDate(*player);
		//	}
		//}
		////�|�[�Y
		//if (gameStatus == GameStatus::Pause)
		//{
		//	pause->PauseSet(*map, *camera, *player, *collision, gameStatus, *uiManager, *effectManager, *soundManager, isFadeOut);
		//	if (gameStatus == GameStatus::Title)
		//	{
		//		player->Initialize();
		//		map->Initialize();
		//		camera->Initialize();
		//		camera->UpDate(*player);
		//	}
		//}
		////�Q�[��
		//if (gameStatus == GameStatus::Game)
		//{
		//	bool isFade = effectManager->FadeInOut(isFadeOut);
		//	soundManager->SoundPlay(SoundKinds::Game, SoundMethod::Loop);
		//	if (isFade)
		//	{
		//		if (uiManager->GetIsClearCount())
		//		{
		//			gameStatus = GameStatus::Gameclear;
		//			soundManager->SoundStop(SoundKinds::Game);
		//		}
		//		countDown->FirstCountDown();
		//		if (countDown->GetFlag()&&isHitGool==false)
		//		{
		//			if (camera->GetModePlayer() == true)
		//			{
		//				player->UpDate(*map, *collision,*soundManager, isHitGool);
		//			}
		//			camera->UpDate(*player);
		//			map->UpDate();
		//			if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_8)
		//			{
		//				gameStatus = GameStatus::Pause;
		//			}
		//		}
		//		uiManager->Update(*map,isHitGool);//�A�b�v�f�[�g
		//		effectManager->UpDate(isHitGool);
		//	}
		//	map->DrawMap(player->GetPosition());
		//	player->Draw();
		//	uiManager->GameDraw(map->GetResetCount(), countDown->GetFlag(), countDown->GetNowTime(),player->GetGrasp(),collision->HitHand(*player,*map),countDown->NoMoveCount(player->GetIsMove()),map->GetMapNumber(),isHitGool);
		//	effectManager->Draw(isHitGool);
		//}
		// 
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