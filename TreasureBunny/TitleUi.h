#pragma once

/// <summary>
/// タイトルのステージセレクト前のUIクラス
/// </summary>
class TitleUi
{
public:
	TitleUi();
	~TitleUi();
	/// <summary>
	/// スタートなどの文字描画
	/// </summary>
	/// <param name="titleSelect"></param>
	/// <param name="SelectFontHandle"></param>
	/// <param name="NSelectFontHandle"></param>
	void DrawTitleFont(int titleSelect, int selectFontHandle, int nSelectFontHandle, int boardImg);
	void ResultMessage();
	void Draw(int titleSelect, int selectFontHandle, int nSelectFontHandle, int boardImg);
private:
	static constexpr int SelectTransparency = 255;
	static constexpr int NoSelectTransparency = 100;
	static constexpr int ColorValue = 255;
	static constexpr double MagnificationRate = 4.5;//拡大率
	static constexpr int PositionX = 200;
	static constexpr int BaseY = 550;
	static constexpr int BaseFontY = BaseY-35;
	static constexpr int CorrectionY = 170;
	static constexpr int FontBetweenCorrectionY = CorrectionY+15;
	static constexpr int Scale = 2;
	static constexpr double Angle = 0.0;
	static constexpr int StartFontBaseX = PositionX-115;
	static constexpr int TutorialFontBaseX = PositionX-135;
	static constexpr int EndFontBaseX = PositionX-145;
	static constexpr int EndCorrection = -30;
	static constexpr int TitleX= 300;
	static constexpr int TitleY = 0;
	static constexpr int TitleWidth = TitleX + 600;
	static constexpr int TitleHeight = TitleY+400;
	static constexpr int FontCorrectionX = 4;
	static constexpr int FontCorrectionY = 3;

	int titlepos;
	int  titlerogopos;
	int titleLogoImg;

};