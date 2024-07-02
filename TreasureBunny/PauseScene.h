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

	bool isPreparationTitleTransition;//�^�C�g���֍s���������ł��Ă��邩
	bool hitA;
	bool hitD;
	bool firstInput;
	bool isTitle;
};