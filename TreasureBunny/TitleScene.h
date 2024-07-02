#pragma once
#include"BaseScene.h"

class Collision;

class TitleScene :public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	void Update(GameStatus &nextStatus)override;
	void Draw()override;
private:
	static constexpr int MaxSelect = 2;
	static constexpr int MinSelect = 0;
	static constexpr int MaxMapNumber = 4;
	static constexpr int MinMapNumber = 1;
	static constexpr int TutorialNumber = 0;
	bool HitKeyReturn();
	Collision* collision;

	bool upFlag;//ã‚ğ‘O‰Ÿ‚µ‚Ä‚¢‚é‚©
	bool downFlag;
	int titleSelect;
	bool isPreparationStageTransition;
	bool hitA;
	bool hitD;
	bool stageSelectMode;
	bool firstInput;


};