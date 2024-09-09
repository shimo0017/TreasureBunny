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
	ChangeWindowMode(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面化

	//奥行0.1～1300までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1300.0f);
	//フォント読み込み
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
	Fps* fps = new Fps();

	//----------------//
	//メインループ
	//----------------//
	while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{

		//FPS
		fps->Update();
		sceneManager->Update();
		sceneManager->Draw();
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