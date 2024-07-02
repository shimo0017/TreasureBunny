#include"DxLib.h"
#include"StageClearUi.h"



StageClearUi::StageClearUi():
    DrawCount(ResetCount)
{

}
StageClearUi::~StageClearUi()
{

}
void StageClearUi::Initialize()
{
    DrawCount = ResetCount;
}
void StageClearUi::UpDate()
{
    if (DrawCount > LimitCount)
    {
        DrawCount--;
    }
}
void StageClearUi::Draw(int clearImgHandle)
{
    DrawExtendGraph(ClearImgX, ClearImgY, ClearImgWidth, ClearImgHeight, clearImgHandle, TRUE);

}
bool StageClearUi::GetIsClearCount()
{
    bool isClearCount = false;
    if (DrawCount <= LimitCount)
    {
        isClearCount = true;
    }

    return isClearCount;
}
