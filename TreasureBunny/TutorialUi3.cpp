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
            //���̃`���[�g���A���֐i�߂�
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

    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY+FontCorrectionY, "������x������Ƃ���܂ŏ��ԃu���b�N��", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "������x������Ƃ���܂ŏ��ԃu���b�N��", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY+FontBetweenCorrectionY, "�߂Â���X�ł��݌��ɓ|���������낤", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + +FontBetweenCorrectionY, "�߂Â���X�ł��݌��ɓ|���������낤", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "�c�� %d / %d", step, PullStep);
    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "�c�� %d / %d", step, PullStep);


}