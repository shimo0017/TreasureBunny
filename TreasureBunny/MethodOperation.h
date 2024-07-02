#pragma once


class MethodOperation
{
public:
    MethodOperation();
    ~MethodOperation();
    void Draw(int fontHandle,int sheetImg);

private:
    static constexpr int FontBaseX = 60;
    static constexpr int FontBaseY = 100;
    static constexpr int FontCorrectionX = 4;
    static constexpr int FontCorrectionY = 3;
    static constexpr int FontBetweenCorrectionY = 50;
    static constexpr int Transparency = 200;
    static constexpr int SheetX = 10;
    static constexpr int SheetY = 70;
    static constexpr int SheetWidth = SheetX+500;
    static constexpr int SheetHeight = SheetY + 260;
};