#include"DxLib.h"
#include"CountDown.h"
#include"Player.h"
CountDown::CountDown():
	endFlag(false),
	timeRecord(0),
	nowTime(ResetNowTime)
{
}
CountDown::~CountDown()
{

}
void CountDown::Initialize()
{
	endFlag = false;
	timeRecord = 0;
}

void CountDown::SetTime()
{
	Initialize();
	timeRecord = GetNowCount();
}
void CountDown::FirstCountDown()
{
	if (endFlag == false)
	{
		nowTime = GetNowCount();
		nowTime = (MaxFirst - (nowTime - timeRecord - CorrectionTime)) / TimeSeconds;
		if (nowTime <= 0)
		{
			endFlag = true;
			nowTime = ResetNowTime;
		}
	}
}
bool CountDown::NoMoveCount(bool isMove)
{
	bool isEndCount = false;
	if (isMoveMode != isMove)
	{
		isMoveMode = isMove;
		notMoveCount = ResetMoveCount;
	}
	if (isMoveMode == false)
	{
		notMoveCount -= CountNumber;
		if (notMoveCount <= LimitCount)
		{
			notMoveCount = LimitCount;
			isEndCount = true;
			return isEndCount;
		}
	}
	return isEndCount;
}
