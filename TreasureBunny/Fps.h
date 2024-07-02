#pragma once

class Fps
{
public:
	/// <summary>
	/// カウンターの初期化
	/// </summary>
	Fps();

	bool Update();

	void Draw();

	void Wait();
private:
	static constexpr int N = 60;//平均を取るサンプル数
	static constexpr int SetFps = 60;	//設定したFps

	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps

};