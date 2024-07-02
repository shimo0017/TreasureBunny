#include"DxLib.h"
#include "TutorialUi1.h"
#include"TutorialUi2.h"

TutorialUi1::TutorialUi1() :BaseTutorialUi()
{

}
TutorialUi1::~TutorialUi1()
{

}
BaseTutorialUi* TutorialUi1::Update(const int nowStep)
{
    if (nowStep==PullStep)
    {
        if (nextTutorialCount >= CountLimit)
        {
            nextTutorialCount=0;
            //次のチュートリアルへ進める
            return new TutorialUi2;
        }
        else
        {
            nextTutorialCount++;
        }
    }
    step = nowStep;
    return this;
}
void TutorialUi1::Draw(const int fontHandle, const int sheetImgHandle)
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
    DrawExtendGraph(SheetX, SheetY, SheetWidth, SheetHeight, sheetImgHandle, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    DrawStringFToHandle(FontBaseX+ FontCorrectionX, FontBaseY+ FontCorrectionY, "左下にある赤色のブロックに近づいてXで", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX , FontBaseY, "左下にある赤色のブロックに近づいてXで", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY+ FontCorrectionY + FontBetweenCorrectionY , "つかみ後ろに左スティックを倒し引っ張ろう", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY , "つかみ後ろに左スティックを倒し引っ張ろう", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX+ NumberCorrectionX+ FontCorrectionX , FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "残り %d / %d", step, PullStep);
    DrawFormatStringToHandle(FontBaseX+ NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "残り %d / %d", step, PullStep);


}