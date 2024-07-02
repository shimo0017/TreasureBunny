#include"DxLib.h"
#include"TitleScene.h"
#include"CommonData.h"
#include"Player.h"
#include"Camera.h"
#include"Collision.h"
#include"Map.h"
#include"EffectManager.h"
#include"SoundManager.h"
#include"UiManager.h"

TitleScene::TitleScene():BaseScene(),
collision(new Collision()),
upFlag(false),
downFlag(false),
titleSelect(0),
isPreparationStageTransition(false),
hitA(true),
hitD(true),
stageSelectMode(false),
firstInput(true)

{

}
TitleScene::~TitleScene()
{

}

void TitleScene::Update(GameStatus& nextStatus)
{
	int nowMapNumber = map->GetMapNumber();
	bool isFade = effectManager->FadeInOut(isFadeOut);
	soundManager->SoundPlay(SoundKinds::Title, SoundMethod::Loop);
	if (isFade)
	{
		if (stageSelectMode == true)
		{
			if (nowMapNumber == TutorialNumber)
			{
				nowMapNumber = MinMapNumber;
			}
			//左
			if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT && nowMapNumber > MinMapNumber && nowMapNumber <= MaxMapNumber)
			{
				if (!hitA)
				{
					nowMapNumber--;
					soundManager->SoundStop(SoundKinds::Select);
					soundManager->SoundPlay(SoundKinds::Select, SoundMethod::BackGround);
				}
				hitA = true;
			}
			else
			{
				hitA = false;
			}
			//右
			if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT && nowMapNumber >= MinMapNumber && nowMapNumber < MaxMapNumber)
			{
				if (!hitD)
				{
					nowMapNumber++;
					soundManager->SoundStop(SoundKinds::Select);
					soundManager->SoundPlay(SoundKinds::Select, SoundMethod::BackGround);
				}
				hitD = true;
			}
			else
			{
				hitD = false;
			}
			map->SetMapNumber(nowMapNumber);
			//Aボタンでキャンセル
			if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1)
			{
				stageSelectMode = false;
				soundManager->SoundPlay(SoundKinds::PushSelect, SoundMethod::BackGround);
			}
		}
		else
		{
			//上
			if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP && titleSelect > MinSelect && titleSelect <= MaxSelect)
			{
				if (!upFlag)
				{
					titleSelect--;
					soundManager->SoundStop(SoundKinds::Select);
					soundManager->SoundPlay(SoundKinds::Select, SoundMethod::BackGround);
				}
				upFlag = true;
			}
			else
			{
				upFlag = false;
			}
			//下
			if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN && titleSelect >= MinSelect && titleSelect < MaxSelect)
			{
				if (!downFlag)
				{
					titleSelect++;
					soundManager->SoundStop(SoundKinds::Select);
					soundManager->SoundPlay(SoundKinds::Select, SoundMethod::BackGround);
				}
				downFlag = true;
			}
			else
			{
				downFlag = false;
			}

		}
		if (HitKeyReturn())
		{
			if (stageSelectMode)
			{
				isFadeOut = true;
				isFade = false;
				isPreparationStageTransition = true;//準備を完了させる
				soundManager->SoundStop(SoundKinds::PushSelect);
				soundManager->SoundPlay(SoundKinds::PushSelect, SoundMethod::BackGround);
			}
			else if (firstInput)
			{
				if (titleSelect == 0)
				{
					stageSelectMode = true;
				}
				else if (titleSelect == 1)
				{
					map->SetMapNumber(TutorialNumber);
					isFadeOut = true;
					isFade = false;
					isPreparationStageTransition = true;//準備を完了させる
				}
				else if (titleSelect == 2)
				{
					nextStatus = GameStatus::End;
				}
				soundManager->SoundPlay(SoundKinds::PushSelect, SoundMethod::BackGround);
			}
			firstInput = true;
		}
	}


	player->TitleMove(*map, *collision, isHitGool);
	camera->TitleUpdate(*player);
	map->UpDate();
	if (isPreparationStageTransition && isFade)
	{
		isFadeOut = false;
		nextStatus = GameStatus::Game;
		soundManager->SoundStop(SoundKinds::Title);

		player->Initialize();
		map->SetMap();
		camera->UpDate(*player);
		uiManager->Initialize();
		isHitGool = false;
	}

}
void TitleScene::Draw()
{
	map->DrawSky();
	player->Draw();
	map->DrawMap(player->GetPosition());
	uiManager->TitleDraw(map->GetMapNumber(),titleSelect,stageSelectMode);
	effectManager->Draw(false);//FADEのみ表示させたいためfalse
}

bool TitleScene::HitKeyReturn()
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
