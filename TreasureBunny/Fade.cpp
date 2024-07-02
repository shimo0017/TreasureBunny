#include"DxLib.h"
#include"Fade.h"



Fade::Fade()
{
	transparency = 0;
}
Fade::~Fade()
{
	//処理なし
}
void Fade::Initialize(bool isOut)
{
	if (isOut)
	{
		transparency = MinTransparency;
	}
	else
	{
		transparency = MaxTransparency;
	}
}

bool Fade::FadeInOut(bool isOut)
{
	//暗く
	if (isOut)
	{
		transparency += FadeSpeed;
		if (transparency >= MaxTransparency)
		{
			transparency = MaxTransparency;
			return true;
		}
	}
	//明るく
	else
	{
		transparency -= FadeSpeed;
		if (transparency <= MinTransparency)
		{
			transparency = MinTransparency;
			return true;
		}
	}
	return false;
}
void Fade::Draw(const int blackColor)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparency);
	//黒いボックスを画面いっぱいに表示
	DrawBox(BoxX, BoxY, BoxWidth, BoxWidth, blackColor,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}