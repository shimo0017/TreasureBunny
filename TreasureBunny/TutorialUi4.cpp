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
            //���̐�͂Ȃ��̂Ŏ����𑗂�N���A��ʂ܂ŕς��Ȃ�
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

    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY, "�������o��������", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "�������o��������", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY, "�����̂Ƃ���܂ōs���΃N���A��", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY, "�����̂Ƃ���܂ōs���΃N���A��", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "�c�� %d / %d", step, GoolStep);
    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "�c�� %d / %d", step, GoolStep);


}