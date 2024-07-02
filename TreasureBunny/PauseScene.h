#pragma once
#include"BaseScene.h"

class Player;
class Map;

class PauseScene :public BaseScene
{
public:
	PauseScene(Player* playerDate, Map* mapDate);
	~PauseScene();
	void Update(GameStatus& nextStatus);
	void Draw();
private:
	bool HitKeyReturn();

	bool isPreparationTitleTransition;//タイトルへ行く準備ができているか
	bool hitA;
	bool hitD;
	bool firstInput;
	bool isTitle;
};