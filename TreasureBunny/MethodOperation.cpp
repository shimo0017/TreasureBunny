#include"DxLib.h"
#include"MethodOperation.h"

MethodOperation::MethodOperation()
{

}
MethodOperation::~MethodOperation()
{

}
void MethodOperation::Draw(int fontHandle, int sheetImg)
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
    DrawExtendGraph(SheetX, SheetY, SheetWidth, SheetHeight, sheetImg, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY, "X�F����", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "X�F����", GetColor(255, 255, 255), fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY, "A�F�W�����v", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY, "A�F�W�����v", GetColor(255, 255, 255), fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 2, "R�F�u���b�N���Z�b�g", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY * 2, "R�F�u���b�N���Z�b�g", GetColor(255, 255, 255), fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 3, "B�F���_�؂�ւ�", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY * 3, "B�F���_�؂�ւ�", GetColor(255, 255, 255), fontHandle);

}