#include"DxLib.h"
#include"PressUi.h"


PressUi::PressUi()
{
	//èàóùÇ»Çµ
}
PressUi::~PressUi()
{
	//èàóùÇ»Çµ
}
void PressUi::Draw(int fontHandle)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
	DrawBox(SeetX, SeetY, SeetWidth, SeetHeight, GetColor(0,0,0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawStringToHandle(FontX+ CorrectionX, FontY+ CorrectionY, XPrees, GetColor(0, 0, 0), fontHandle);
	DrawStringToHandle(FontX, FontY, XPrees, GetColor(255, 255, 255), fontHandle);

}