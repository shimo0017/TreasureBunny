#pragma once
#include"BaseScene.h"

class CountDown;
class Collision;


class GameScene :public BaseScene
{
public:
	GameScene(Player* playerDate, Map* mapDate);
	~GameScene();
	void Update(GameStatus& nextStatus);
	void Draw();
private:
	CountDown* countDown;
	Collision* collision;
};