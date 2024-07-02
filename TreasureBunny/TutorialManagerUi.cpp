#include"DxLib.h"
#include "TutorialManagerUi.h"
#include"Map.h"
#include"TutorialUi1.h"

TutorialManagerUi::TutorialManagerUi() :
    nowStepNumber(0),
    tutorial(new TutorialUi1())
{

}
TutorialManagerUi::~TutorialManagerUi()
{
    delete tutorial;
}
void TutorialManagerUi::Initialize()
{
    tutorial = new TutorialUi1();
}
void TutorialManagerUi::Update(const Map &map, const bool isHitGool)
{
    int step = map.GetBlockStep(tutorial->GetSearchBlockNumber());
    if (nowStepNumber==3)
    {
        if (isHitGool)
        {
            step = 1;
        }
        else
        {
            step = 0;
        }
    }
    //ˆê’è‚ÌðŒƒNƒŠƒAŽž‚ÉŽŸ‚ÉˆÚs‚³‚¹‚ê‚é‚æ‚¤‚É‚·‚é
    BaseTutorialUi* nextTutorial = tutorial->Update(step);
    if (nextTutorial != tutorial)
    {
        delete tutorial;
        tutorial = nextTutorial;
        nowStepNumber++;
    }
}
void TutorialManagerUi::Draw(int fontHandle,int sheetImgHandle)const
{
    tutorial->Draw(fontHandle, sheetImgHandle);
}
