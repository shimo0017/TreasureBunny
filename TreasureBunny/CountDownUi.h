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
	static constexpr int BoxX = 0;//�{�b�N�X�̍�
	static constexpr int BoxY = 0;//�{�b�N�X�̏�
	static constexpr int BoxWidth = 1280;//�{�b�N�X�̉E
	static constexpr int BoxHeight = 1024;//�{�b�N�X�̉�

	static constexpr int Transparency = 100;

	static constexpr int CorrectionX = 4;
	static constexpr int CorrectionY = 3;
};