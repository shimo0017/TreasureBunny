#pragma once
class PressUi
{
public:
	PressUi();
	~PressUi();
	void Draw(int fontHandle);
private:
	static constexpr LPCSTR XPrees = "'X'’Í‚Þ";
	static constexpr int Transparency = 100;//”¼“§–¾
	static constexpr int SeetX = 570;
	static constexpr int SeetY = 520;
	static constexpr int SeetWidth = SeetX+150;
	static constexpr int SeetHeight = SeetY + 60;

	static constexpr int FontX = SeetX+5;
	static constexpr int FontY = SeetY+10;
	static constexpr int CorrectionX = 4;
	static constexpr int CorrectionY = 3;
};