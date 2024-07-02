#include"DxLib.h"
#include"TutorialUi2.h"
#include"TutorialUi3.h"


TutorialUi2::TutorialUi2() :BaseTutorialUi()
{

}
TutorialUi2::~TutorialUi2()
{

}
BaseTutorialUi* TutorialUi2::Update(const int nowStep)
{
    if (nowStep == PullStep)
    {
        if (nextTutorialCount >= CountLimit)
        {
            nextTutorialCount = 0;
            //次のチュートリアルへ進める
            return new TutorialUi3;
        }
        else
        {
            nextTutorialCount++;
        }
    }
    step = nowStep;
    return this;
}
void TutorialUi2::Draw(const int fontHandle, const int sheetImgHandle)
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
    DrawExtendGraph(SheetX, SheetY, SheetWidth, SheetHeight, sheetImgHandle, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY, "階段をAでジャンプして上についたら", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "階段をAでジャンプして上についたら", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY+ FontBetweenCorrectionY, "緑ブロックに近づいてXでつかみ", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY+ FontBetweenCorrectionY, "緑ブロックに近づいてXでつかみ", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY+ FontBetweenCorrectionY * 2, "後ろに左スティックを倒し引っ張ろう", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY * 2, "後ろに左スティックを倒し引っ張ろう", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "残り %d / %d", step, PullStep);
    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "残り %d / %d", step, PullStep);

}