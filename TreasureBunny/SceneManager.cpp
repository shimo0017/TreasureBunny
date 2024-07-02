#include"DxLib.h"
#include"SceneManager.h"
#include"CommonData.h"
#include"BaseScene.h"
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"
#include"PauseScene.h"
SceneManager::SceneManager():
    nowScene(new TitleScene()),
    keepScene(nullptr),
    nowStatus(GameStatus::Title),
    nextStatus(GameStatus::Title)
{
    //処理なし
}
SceneManager::~SceneManager()
{
    delete nowScene;
}
bool SceneManager::ChangeScene()
{
    bool isEndStatus = false;
    if (nowStatus != nextStatus)
    {
        //一時的に移す
        if (nowStatus != GameStatus::Pause)
        {
            delete keepScene; 
            keepScene = nowScene;
        }
        //ポーズからゲームに戻る時のみKeepSceneから持ってくるようにする
        switch (nextStatus)
        {
        case GameStatus::Title:
            //前回のデータを破棄
            delete keepScene;
            keepScene = nullptr;
            nowScene=new TitleScene();
            break;
        case GameStatus::Game:

            if (nowStatus == GameStatus::Pause)
            {
                delete nowScene;
                nowScene = keepScene;
                keepScene = nullptr;
            }
            else
            {
                nowScene = new GameScene(keepScene->GetPlayerDate(), keepScene->GetMapDate());
            }
            break;
        case GameStatus::End:
            //メインでループを抜けさせる
            isEndStatus = true;
            break;
        case GameStatus::Gameclear:
            nowScene = new ResultScene(keepScene->GetPlayerDate(), keepScene->GetMapDate());
            break;
        case GameStatus::Pause:
            nowScene = new PauseScene(keepScene->GetPlayerDate(), keepScene->GetMapDate());
            break;
        default:
            break;
        }
        nowStatus = nextStatus;
    }
    return isEndStatus;
}
void SceneManager::Update()
{
    nowScene->Update(nextStatus);
}
void SceneManager::Draw()const
{
    nowScene->Draw();
}
