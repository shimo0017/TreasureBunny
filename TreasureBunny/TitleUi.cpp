#include"DxLib.h"
#include"TitleUi.h"

TitleUi::TitleUi()
{
	titleLogoImg = LoadGraph("Img/titleLogo.png");

}
TitleUi::~TitleUi()
{

}
void TitleUi::Draw(int titleSelect,int selectFontHandle,int nSelectFontHandle,int boardImg)
{
	//�^�C�g��
	DrawExtendGraph(TitleX, TitleY, TitleWidth, TitleHeight, titleLogoImg, TRUE);
	//�����E�{�[�h�\��
	DrawTitleFont(titleSelect, selectFontHandle, nSelectFontHandle, boardImg);
}
void TitleUi::DrawTitleFont(int titleSelect, int selectFontHandle, int nSelectFontHandle, int boardImg)
{
	static int WhiteColor = GetColor(ColorValue, ColorValue, ColorValue);
	static int BlackColor= GetColor(0, 0, 0);
	int startTransparency= NoSelectTransparency;
	int tutorialTransparency= NoSelectTransparency;
	int endTransparency= NoSelectTransparency;
	if (titleSelect == 0)
	{
		startTransparency = SelectTransparency;
	}
	else if (titleSelect == 1)
	{
		tutorialTransparency = SelectTransparency;
	}
	else if (titleSelect == 2)
	{
		endTransparency = SelectTransparency;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, startTransparency);
	DrawRotaGraph(PositionX, BaseY, MagnificationRate, Angle, boardImg, TRUE, FALSE);
	DrawStringFToHandle(StartFontBaseX + FontCorrectionX, BaseFontY+ FontCorrectionY, "�X�^�[�g", BlackColor, selectFontHandle);
	DrawStringFToHandle(StartFontBaseX, BaseFontY, "�X�^�[�g", WhiteColor, selectFontHandle);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, tutorialTransparency);
	DrawRotaGraph(PositionX, BaseY+ CorrectionY, MagnificationRate, Angle, boardImg, TRUE, FALSE);
	DrawStringFToHandle(TutorialFontBaseX + FontCorrectionX, BaseFontY + FontCorrectionY + FontBetweenCorrectionY, "�`���[�g���A��", BlackColor, nSelectFontHandle);
	DrawStringFToHandle(TutorialFontBaseX, BaseFontY+ FontBetweenCorrectionY, "�`���[�g���A��", WhiteColor, nSelectFontHandle);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, endTransparency);
	DrawRotaGraph(PositionX, BaseY + CorrectionY* Scale, MagnificationRate, Angle, boardImg, TRUE, FALSE);
	DrawStringFToHandle(EndFontBaseX + FontCorrectionX, BaseFontY + FontCorrectionY + FontBetweenCorrectionY *2+ EndCorrection, "�Q�[���I��", BlackColor, selectFontHandle);
	DrawStringFToHandle(EndFontBaseX, BaseFontY + FontBetweenCorrectionY *2+ EndCorrection, "�Q�[���I��", WhiteColor, selectFontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
void TitleUi::ResultMessage()
{
	//DrawStringFToHandle(40, 900, "Enter�������ƃ^�C�g���֖߂�܂�", GetColor(255, 255, 255), NSelectFontHandle);
	//FontMolse();
}
