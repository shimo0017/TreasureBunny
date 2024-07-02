#include"DxLib.h"
#include"BaseScene.h"
#include"Player.h"
#include"Map.h"
#include"Camera.h"
#include"UiManager.h"
#include"EffectManager.h"
#include"SoundManager.h"

UiManager* BaseScene::uiManager = nullptr;
EffectManager* BaseScene::effectManager = nullptr;
SoundManager* BaseScene::soundManager = nullptr;
bool BaseScene::isFadeOut = false;
bool BaseScene::isHitGool = false;

BaseScene::BaseScene():
    player(new Player()),
    map(new Map())
{
    uiManager=new UiManager();
    effectManager=new EffectManager(); 
   soundManager=new SoundManager();
   isFadeOut = false;
   isHitGool = false;
   camera = new Camera();

}
BaseScene::BaseScene(Player* playerDate, Map* mapDate)
{
    player = playerDate;
    map = mapDate;
    camera = new Camera();
}
BaseScene::~BaseScene()
{
    delete camera;
}

