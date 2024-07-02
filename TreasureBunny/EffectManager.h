#pragma once

class Fade;
class Confetti;

class EffectManager
{
public:
	EffectManager();
	~EffectManager();
	void Initialize();
	void UpDate(const bool isHitGool);
	/// <summary>
	/// フェードイン・フェードアウト
	/// </summary>
	/// <param name="nextMode">true：暗く false：明るく</param>
	/// <returns>true：上限まで行った　false：上限に行っていない</returns>
	bool FadeInOut(bool nextMode);
	void CreateConfetti();
	void Draw(int isHitGool);
private:
	static constexpr bool InitFadeMode = false;
	static constexpr int MaxColorKinds = 4;
	static bool isFirstConstructor;
	static bool nowFadeMode;
	static bool isCreateConfetti;
	static int blackColor;
	static int colorPaper[MaxColorKinds];

	Fade *fade;
	Confetti* confetti;
};