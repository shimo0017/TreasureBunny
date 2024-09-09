#include"DxLib.h"
#include"PauseSelectUi.h"

PauseSelectUi::PauseSelectUi()
{

}
PauseSelectUi::~PauseSelectUi()
{

}
void PauseSelectUi::Draw(bool isTitle, int selectFontHandle, int nSelectFontHandle, int boardImg)
{
	static int WhiteColor = GetColor(ColorValue, ColorValue, ColorValue);
	static int BlackColor = GetColor(0, 0, 0);
	int titleTransparency = NoSelectTransparency;
	int continueTransparency = NoSelectTransparency;
	if (isTitle)
	{
		titleTransparency = SelectTransparency;
	}
	else
	{
		continueTransparency = SelectTransparency;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, titleTransparency);
	DrawRotaGraph(BaseX, PositionY, MagnificationRate, Angle, boardImg, TRUE, FALSE);
	DrawStringFToHandle(FontBaseX + FontCorrectionShadowX, FontBaseY+ FontCorrectionShadowY, "タイトル", BlackColor, selectFontHandle);
	DrawStringFToHandle(FontBaseX, FontBaseY, "タイトル", WhiteColor, selectFontHandle);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, continueTransparency);
	DrawRotaGraph(BaseX+ CorrectionX, PositionY, MagnificationRate, Angle, boardImg, TRUE, FALSE);
	DrawStringFToHandle(FontBaseX + CorrectionX+ FontCorrectionX +FontCorrectionShadowX, FontBaseY+ FontCorrectionShadowY, "続ける", BlackColor, selectFontHandle);
	DrawStringFToHandle(FontBaseX + CorrectionX+ FontCorrectionX, FontBaseY, "続ける", WhiteColor, selectFontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
