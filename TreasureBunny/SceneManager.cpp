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
    //�����Ȃ�
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
        //�ꎞ�I�Ɉڂ�
        if (nowStatus != GameStatus::Pause)
        {
            delete keepScene; 
            keepScene = nowScene;
        }
        //�|�[�Y����Q�[���ɖ߂鎞�̂�KeepScene���玝���Ă���悤�ɂ���
        switch (nextStatus)
        {
        case GameStatus::Title:
            //�O��̃f�[�^��j��
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
            //���C���Ń��[�v�𔲂�������
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
