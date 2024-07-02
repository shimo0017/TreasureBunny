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
            //���̃`���[�g���A���֐i�߂�
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

    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY, "�K�i��A�ŃW�����v���ď�ɂ�����", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "�K�i��A�ŃW�����v���ď�ɂ�����", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY+ FontBetweenCorrectionY, "�΃u���b�N�ɋ߂Â���X�ł���", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY+ FontBetweenCorrectionY, "�΃u���b�N�ɋ߂Â���X�ł���", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY+ FontBetweenCorrectionY * 2, "���ɍ��X�e�B�b�N��|���������낤", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY * 2, "���ɍ��X�e�B�b�N��|���������낤", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "�c�� %d / %d", step, PullStep);
    DrawFormatStringToHandle(FontBaseX + NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "�c�� %d / %d", step, PullStep);

}