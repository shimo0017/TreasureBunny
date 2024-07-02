#pragma once
class PauseSelectUi
{
public:
	PauseSelectUi();
	~PauseSelectUi();
	void Draw(bool isTitle, int selectFontHandle, int nSelectFontHandle, int boardImg);
private:
	static constexpr int SelectTransparency = 255;
	static constexpr int NoSelectTransparency = 100;
	static constexpr int ColorValue = 255;
	static constexpr double MagnificationRate = 3.5;//Šg‘å—¦
	static constexpr int FontBaseX = 300;
	static constexpr int FontBaseY = 420;
	static constexpr int BaseX = FontBaseX+80;
	static constexpr int PositionY = FontBaseY+25;
	static constexpr int CorrectionX = 550;
	static constexpr int CorrectionFontX = 155;
	static constexpr int Scale = 2;
	static constexpr double Angle = 0.0;
	static constexpr int FontCorrectionX = 4;
	static constexpr int FontCorrectionY = 3;
};