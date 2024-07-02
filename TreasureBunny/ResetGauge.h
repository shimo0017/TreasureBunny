#pragma once


class ResetGauge
{
public:
	ResetGauge();
	~ResetGauge();
	void Draw(const int gaugeImg, const int resetCount);
private:

	static constexpr int GaugeImgX = 860;
	static constexpr int GaugeImgY = 70;
	static constexpr int GaugeImgWidth = GaugeImgX+180;
	static constexpr int GaugeImgHeight = GaugeImgY+60;

	static constexpr int GaugeX = GaugeImgX+15;
	static constexpr int GaugeY = GaugeImgY+10;
	static constexpr int GaugeHeight = GaugeY+30;

	static constexpr int ColorValue = 200;
};