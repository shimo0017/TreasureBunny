#include"DxLib.h"
#include"ResultScene.h"
#include"CommonData.h"
#include"Player.h"
#include"Camera.h"
#include"Collision.h"
#include"Map.h"
#include"EffectManager.h"
#include"SoundManager.h"
#include"UiManager.h"


ResultScene::ResultScene(Player* playerDate, Map* mapDate):
	BaseScene(playerDate, mapDate),
	isPreparationTitleTransition(false),
	isDisplayClearLogo(false)
{

}
ResultScene::~ResultScene()
{
	delete player;
	delete map;
	delete uiManager;
	delete effectManager;
	delete soundManager;

}
void ResultScene::Update(GameStatus& nextStatus)
{
	bool isFade = effectManager->FadeInOut(isFadeOut);

	soundManager->SoundPlay(SoundKinds::Clear, SoundMethod::Loop);
	if (isFade)
	{
		if (HitKeyReturn() && isDisplayClearLogo)
		{
			isFadeOut = true;
			isPreparationTitleTransition = true;
			soundManager->SoundPlay(SoundKinds::PushSelect, SoundMethod::BackGround);
		}
	}
	//ボタンを押して画面が暗くなったら
	if (isPreparationTitleTransition && isFade)
	{
		isFadeOut = false;
		nextStatus = GameStatus::Title;
		soundManager->SoundStop(SoundKinds::Clear);
	}

	map->DrawSky();
	camera->TitleUpdate(*player);
	isDisplayClearLogo = uiManager->Update(*map, isFade,true);

}
void ResultScene::Draw()
{
	player->Draw();
	map->DrawMap(player->GetPosition());
	uiManager->GameClearDraw(map->GetMapNumber(), isFadeOut);
	effectManager->Draw(false);//FADEだけさせたいためfalse
}

bool ResultScene::HitKeyReturn()
{
	static bool hitkey = true;
	//Bボタンを押したら
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_2)
	{

		if (hitkey == false)
		{
			hitkey = true;
			return true;
		}
		hitkey = true;
	}
	else
	{
		hitkey = false;
	}
	return false;
}
