#include"DxLib.h"
#include"TutorialUi3.h"
#include"TutorialUi4.h"

TutorialUi3::TutorialUi3() :BaseTutorialUi()
{

}
TutorialUi3::~TutorialUi3()
{

}
BaseTutorialUi* TutorialUi3::Update(const int nowStep)
{
    if (nowStep == PullStep)
    {
        if (nextTutorialCount >= CountLimit)
        {
            nextTutorialCount = 0;
            //次のチュートリアルへ進める
            return new TutorialUi4;
        }
        else
        {
            nextTutorialCount++;
        }
    }
    step = nowStep;
    return this;
}
void TutorialUi3::Draw(const int fontHandle, const int sheetImgHandle)
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
    DrawExtendGraph(SheetX, SheetY, SheetWidth, SheetHeight, sheetImgHandle, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY+FontCorrectionY, "もう一度いけるところまで上り赤ブロックに", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "もう一度いけるところまで上り赤ブロックに", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY+FontBetweenCorrectionY, "近づいてXでつかみ後ろに倒し引っ張ろう", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + +FontBetweenCorrectionY, "近づいてXでつかみ後ろに倒し引っ張ろう", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "残り %d / %d", step, PullStep);
    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "残り %d / %d", step, PullStep);


}