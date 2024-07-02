#pragma once

class Player;
class CountDown
{
public:
	CountDown();
	~CountDown();

	void Initialize();
	void SetTime();
	void FirstCountDown();
	bool GetFlag() { return endFlag; }
	bool NoMoveCount(bool isMove);
	int GetNowTime() { return nowTime; }
private:
	static constexpr int ResetNowTime = 4;
	static constexpr int MaxFirst = 4000;
	static constexpr int TimeSeconds = 1000;
	static constexpr int CorrectionTime = 800;
	static constexpr int ResetMoveCount = 200;
	static constexpr int CountNumber = 1;
	static constexpr int LimitCount = 0;
	bool endFlag;//�ŏ��̎��ԃJ�E���g���I�����Ă��邩
	int timeRecord;//�^�C�g���I���Ŏ��Ԃ�����
	int nowTime;
	int notMoveCount;
	bool isMoveMode;
};
