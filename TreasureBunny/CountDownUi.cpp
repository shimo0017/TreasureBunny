#include"DxLib.h"
#include"CountDownUi.h"

CountDownUi::CountDownUi()
{

}
CountDownUi::~CountDownUi()
{

}
void CountDownUi::Draw(int nowTime,int fontHandle)
{
	int whiteColor = GetColor(255, 255, 255);
	int blackColor = GetColor(0, 0, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
	DrawBox(BoxX, BoxY, BoxWidth, BoxWidth, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Transparency);

	if (nowTime > 1)
	{
		DrawFormatStringToHandle(NumberX + CorrectionX, NumberY+ CorrectionY, blackColor, fontHandle, "%d", nowTime - 1);
		DrawFormatStringToHandle(NumberX, NumberY, whiteColor, fontHandle, "%d", nowTime - 1);
	}
	else
	{
		DrawStringToHandle(PositionX + CorrectionX, PositionY+ CorrectionY, "スタート！", blackColor, fontHandle);
		DrawStringToHandle(PositionX, PositionY, "スタート！", whiteColor, fontHandle);
	}

}