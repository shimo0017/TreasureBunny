#pragma once

enum class GameStatus;
class BaseScene;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	 bool ChangeScene();
	 void Update();
	 void Draw()const;
	 GameStatus GetNowStatus()const { return nowStatus; }
private:
	 BaseScene* nowScene;
	 BaseScene* keepScene;
	 GameStatus nowStatus;
	 GameStatus nextStatus;
};