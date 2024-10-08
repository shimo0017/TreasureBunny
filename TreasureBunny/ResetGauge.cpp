#include"DxLib.h"
#include"ResetGauge.h"

ResetGauge::ResetGauge()
{
	//処理なし
}
ResetGauge::~ResetGauge()
{
	//処理なし
}
void ResetGauge::Draw(const int gaugeImg,const int resetCount)
{
	if (resetCount >= 1)
	{
		DrawBox(GaugeX, GaugeY, GaugeX + resetCount, GaugeHeight, GetColor(0, 0, ColorValue), TRUE);
		DrawExtendGraph(GaugeImgX, GaugeImgY, GaugeImgWidth, GaugeImgHeight, gaugeImg, TRUE);
	}
}