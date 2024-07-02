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


    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY, "X：つかみ", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY, "X：つかみ", GetColor(255, 255, 255), fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY, "A：ジャンプ", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY, "A：ジャンプ", GetColor(255, 255, 255), fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 2, "R：ブロックリセット", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY * 2, "R：ブロックリセット", GetColor(255, 255, 255), fontHandle);
    DrawStringFToHandle(FontBaseX + FontCorrectionX, FontBaseY + FontCorrectionY + FontBetweenCorrectionY * 3, "B：視点切り替え", GetColor(0, 0, 0), fontHandle);
    DrawStringFToHandle(FontBaseX, FontBaseY + FontBetweenCorrectionY * 3, "B：視点切り替え", GetColor(255, 255, 255), fontHandle);

}