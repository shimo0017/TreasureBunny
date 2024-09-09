#include"DxLib.h"
#include"PauseScene.h"
#include"CommonData.h"
#include"Player.h"
#include"Camera.h"
#include"Collision.h"
#include"Map.h"
#include"EffectManager.h"
#include"SoundManager.h"
#include"UiManager.h"


PauseScene::PauseScene(Player* playerDate, Map* mapDate) :
BaseScene(playerDate, mapDate),
isPreparationTitleTransition(false),
hitA(true),
hitD(true),
firstInput(false),
isTitle(false)
{

}
PauseScene::~PauseScene()
{

}
void PauseScene::Update(GameStatus& nextStatus)
{
	bool isFade = effectManager->FadeInOut(isFadeOut);
	if (isFade)
	{
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT && isTitle == false)
		{
			if (!hitA)
			{
				isTitle = true;
				soundManager->SoundStop(SoundKinds::Select);
				soundManager->SoundPlay(SoundKinds::Select, SoundMethod::BackGround);
			}
			hitA = true;
		}
		else
		{
			hitA = false;
		}
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT && isTitle)
		{
			if (!hitD)
			{
				isTitle = false;
				soundManager->SoundStop(SoundKinds::Select);
				soundManager->SoundPlay(SoundKinds::Select, SoundMethod::BackGround);
			}
			hitD = true;
		}
		else
		{
			hitD = false;
		}
	}
	if (HitKeyReturn())
	{
		if (firstInput)
		{
			if (isTitle)
			{
				isFadeOut = true;
				isPreparationTitleTransition = true;
				isFade = false;
			}
			else if (isTitle == false)
			{
				nextStatus = GameStatus::Game;//ゲームに戻す
				firstInput = false;
			}
			soundManager->SoundPlay(SoundKinds::PushSelect, SoundMethod::BackGround);
		}
		firstInput = true;
	}

	if (isPreparationTitleTransition && isFade)
	{
		isFadeOut = false;
		nextStatus = GameStatus::Title;//タイトルに
		soundManager->SoundStop(SoundKinds::Game);
		delete map;
	}

}
void PauseScene::Draw()
{
	map->DrawSky();
	player->Draw();
	map->DrawMap(player->GetPosition());
	uiManager->PauseDraw(isTitle);

	effectManager->Draw(false);//FADEだけさせたいためfalse

}
bool PauseScene::HitKeyReturn()
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
