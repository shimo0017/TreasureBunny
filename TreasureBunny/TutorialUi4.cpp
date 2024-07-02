#include"DxLib.h"
#include "TutorialUi4.h"


TutorialUi4::TutorialUi4() :BaseTutorialUi()
{

}
TutorialUi4::~TutorialUi4()
{

}
BaseTutorialUi* TutorialUi4::Update(const int nowStep)
{
    if (nowStep == GoolStep)
    {
        if (nextTutorialCount >= CountLimit)
        {
            nextTutorialCount = 0;
            //この先はないので自分を送りクリア画面まで変えない
            return this;
        }
        else
        {
            nextTutorialCount++;
        }
    }
    step = nowStep;
    return this;
}
void TutorialUi4::Draw(const int fontHandle, const int sheetImgHandle)
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
    DrawExtendGraph(SheetX, SheetY, SheetWidth, SheetHeight, sheetImgHandle, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY, "お金が出現したね", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "お金が出現したね", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY, "お金のところまで行けばクリアだ", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY, "お金のところまで行けばクリアだ", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "残り %d / %d", step, GoolStep);
    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "残り %d / %d", step, GoolStep);


}