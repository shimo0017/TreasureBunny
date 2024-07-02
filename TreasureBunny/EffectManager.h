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
	/// �t�F�[�h�C���E�t�F�[�h�A�E�g
	/// </summary>
	/// <param name="nextMode">true�F�Â� false�F���邭</param>
	/// <returns>true�F����܂ōs�����@false�F����ɍs���Ă��Ȃ�</returns>
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