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
            //���̃`���[�g���A���֐i�߂�
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

    DrawStringFToHandle(FontBaseX+ FontCorrectionX, FontBaseY+ FontCorrectionY, "�����ɂ���ԐF�̃u���b�N�ɋ߂Â���X��", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX , FontBaseY, "�����ɂ���ԐF�̃u���b�N�ɋ߂Â���X��", whiteColor, fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY+ FontCorrectionY + FontBetweenCorrectionY , "���݌��ɍ��X�e�B�b�N��|���������낤", blackColor, fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY , "���݌��ɍ��X�e�B�b�N��|���������낤", whiteColor, fontHandle);


    DrawFormatStringToHandle(FontBaseX+ NumberCorrectionX+ FontCorrectionX , FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, blackColor, fontHandle, "�c�� %d / %d", step, PullStep);
    DrawFormatStringToHandle(FontBaseX+ NumberCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 4, whiteColor, fontHandle, "�c�� %d / %d", step, PullStep);


}