#include"DxLib.h"
#include"GameScene.h"
#include"CommonData.h"
#include"Player.h"
#include"Camera.h"
#include"Collision.h"
#include"Map.h"
#include"EffectManager.h"
#include"SoundManager.h"
#include"UiManager.h"
#include"CountDown.h"


GameScene::GameScene(Player* playerDate, Map* mapDate):
BaseScene(playerDate, mapDate),
countDown(new CountDown()),
collision(new Collision())
{
	countDown->SetTime();
}
GameScene::~GameScene()
{
	delete countDown;
	delete collision;
}
void GameScene::Update(GameStatus& nextStatus)
{
	bool isFade = effectManager->FadeInOut(isFadeOut);
	soundManager->SoundPlay(SoundKinds::Game, SoundMethod::Loop);
	if (isFade)
	{
		if (uiManager->GetIsClearCount())
		{
			nextStatus = GameStatus::Gameclear;
			soundManager->SoundStop(SoundKinds::Game);
		}
		countDown->FirstCountDown();
		if (countDown->GetFlag()&&isHitGool==false)
		{
			if (camera->GetModePlayer() == true)
			{
				player->UpDate(*map, *collision,*soundManager, isHitGool);
			}
			camera->UpDate(*player);
			map->UpDate();
			if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_8)
			{
				nextStatus = GameStatus::Pause;
			}
		}
		uiManager->Update(*map,isHitGool,false);//アップデート
		effectManager->UpDate(isHitGool);
	}

}
void GameScene::Draw()
{
	map->DrawMap(player->GetPosition());
	player->Draw();
	uiManager->GameDraw(map->GetResetCount(), countDown->GetFlag(), countDown->GetNowTime(),player->GetGrasp(),collision->HitHand(*player,*map),countDown->NoMoveCount(player->GetIsMove()),map->GetMapNumber(),isHitGool);
	effectManager->Draw(isHitGool);

}
