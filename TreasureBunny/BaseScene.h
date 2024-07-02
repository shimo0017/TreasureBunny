#pragma once

enum class GameStatus;
class Player;
class Map;
class UiManager;
class EffectManager;
class SoundManager;
class Camera;

class BaseScene
{
public:
	BaseScene();
	BaseScene(Player* playerDate, Map* mapDate);
	virtual ~BaseScene();
	virtual void Update(GameStatus &nextStatus) = 0;
	virtual void Draw() = 0;
	Player* GetPlayerDate() { return player; }
	Map* GetMapDate() { return map; }
protected:
	Player* player;
	Map* map;
	Camera* camera;

	static UiManager* uiManager;
	static EffectManager* effectManager;
	static SoundManager* soundManager;

	static bool isFadeOut;
	static bool isHitGool;//ƒS[ƒ‹‚É“–‚½‚Á‚½‚©
};