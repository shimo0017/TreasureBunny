#include"DxLib.h"
#include"CommonData.h"
#include"BaseScene.h"
#include"SceneManager.h"
#include"Fps.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}
	SetMainWindowText("TreasureBunny");
	// 画面モードのセット
	SetGraphMode(1280, 1024, 32);
	ChangeWindowMode(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面化

	//奥行0.1～1300までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1300.0f);
	//フォント読み込み
	//LPCSTR font_path = "Font/851MkPOP_101.ttf";//フォントパス
	LPCSTR font_path = "Font/RocknRollOne-Regular.ttf";//フォントパス

	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0)
	{
	}
	else
	{
		// フォント読込エラー処理
		printfDx("フォントを読み込み失敗");
	}
	//生成
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
	//bool isFadeOut = false;						//暗くするか
	//bool isHitGool = false;						//ゴールに当たったか
	
	////初期化
	//player->LoadModel();
	//player->Initialize();
	//titleEnd->Initialize();

	//----------------//
	//メインループ
	//----------------//
	while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{

		//FPS
		fps->Update();
		sceneManager->Update();
		sceneManager->Draw();
		////ゲーム終了
		//if (gameStatus == GameStatus::End)
		//{
		//	break;
		//}

		////タイトル
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
		////ゲームクリア
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
		////ポーズ
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
		////ゲーム
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
		//		uiManager->Update(*map,isHitGool);//アップデート
		//		effectManager->UpDate(isHitGool);
		//	}
		//	map->DrawMap(player->GetPosition());
		//	player->Draw();
		//	uiManager->GameDraw(map->GetResetCount(), countDown->GetFlag(), countDown->GetNowTime(),player->GetGrasp(),collision->HitHand(*player,*map),countDown->NoMoveCount(player->GetIsMove()),map->GetMapNumber(),isHitGool);
		//	effectManager->Draw(isHitGool);
		//}
		// 
		//// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		////終了処理
		//シーンがエンドになっている時抜ける
		if (sceneManager->ChangeScene()==true||CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		//待機
		fps->Wait();

	}
	RemoveFontResourceEx(font_path, FR_PRIVATE, NULL);

	// ＤＸライブラリの後始末
	DxLib_End();
	// ソフトの終了
	return 0;

}