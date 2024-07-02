#include"DxLib.h"
#include"EffectManager.h"
#include"Fade.h"
#include"Confetti.h"

bool EffectManager::isFirstConstructor=false;
bool EffectManager::nowFadeMode= InitFadeMode;
bool EffectManager::isCreateConfetti=false;
int EffectManager::blackColor=0;
int EffectManager::colorPaper[MaxColorKinds] = {0};


EffectManager::EffectManager():
fade(new Fade()),
confetti(new Confetti())
{
	if (isFirstConstructor == false)
	{
		blackColor = GetColor(0, 0, 0);
		colorPaper[0] = LoadGraph("Img/RedPaper.png");
		colorPaper[1] = LoadGraph("Img/GreenPaper.png");
		colorPaper[2] = LoadGraph("Img/BluePaper.png");
		colorPaper[3] = LoadGraph("Img/YellowPaper.png");

		nowFadeMode=InitFadeMode;
		isFirstConstructor = true;
	}
	isCreateConfetti = false;

}
EffectManager::~EffectManager()
{
	delete fade;
	delete confetti;
}
void EffectManager::Initialize()
{
	isCreateConfetti = false;
}
void EffectManager::UpDate(const bool isHitGool)
{
	if (isHitGool==true&&isCreateConfetti == true)
	{
		confetti->UpDate();
	}
}
bool EffectManager::FadeInOut(bool nextMode)
{
	//次のモードと現在のモードが違うとき初期化
	if (nowFadeMode != nextMode)
	{
		nowFadeMode = nextMode;
		fade->Initialize(nowFadeMode);
	}
	return fade->FadeInOut(nowFadeMode);
}
void EffectManager::CreateConfetti()
{
	delete confetti;
	confetti = new Confetti();
}

void EffectManager::Draw(int isHitGool)
{
	fade->Draw(blackColor);
	if (isHitGool)
	{
		if (isCreateConfetti == false)
		{
			CreateConfetti();
			isCreateConfetti = true;
		}
		confetti->Draw(colorPaper);
	}
}
