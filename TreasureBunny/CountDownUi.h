#pragma once

class CountDownUi
{
public:
	CountDownUi();
	~CountDownUi();
	void Draw(int nowTime, int fontHandle);
private:
	static constexpr int NumberX = 600;
	static constexpr int NumberY = 400;
	static constexpr int PositionX = 400;
	static constexpr int PositionY = 400;
	static constexpr int BoxX = 0;//ボックスの左
	static constexpr int BoxY = 0;//ボックスの上
	static constexpr int BoxWidth = 1280;//ボックスの右
	static constexpr int BoxHeight = 1024;//ボックスの下

	static constexpr int Transparency = 100;

	static constexpr int CorrectionX = 4;
	static constexpr int CorrectionY = 3;
};