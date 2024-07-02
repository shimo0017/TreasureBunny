#pragma once
#include"BaseScene.h"

class Player;
class Map;

class ResultScene :public BaseScene
{
public:
	ResultScene(Player* playerDate, Map* mapDate);
	~ResultScene();
	void Update(GameStatus& nextStatus);
	void Draw();
private:
	bool HitKeyReturn();
	bool isPreparationTitleTransition;//�^�C�g���֍s���������ł��Ă��邩
	bool isDisplayClearLogo;
};