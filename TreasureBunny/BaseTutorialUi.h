#pragma once

class BaseTutorialUi
{
public:
    BaseTutorialUi();
    virtual~BaseTutorialUi();
    virtual BaseTutorialUi* Update(const int step)=0;
    virtual void Draw(const int fontHandle,const int sheetImgHandle)=0;
    virtual int GetSearchBlockNumber()const =0;
protected:
    static constexpr int Transparency = 255;
    static constexpr int SheetX = 100;
    static constexpr int SheetY = 700;
    static constexpr int SheetWidth = SheetX + 1000;
    static constexpr int SheetHeight = SheetY + 300;
    static constexpr int FontBaseX = SheetX+100;
    static constexpr int FontBaseY = SheetY+40;
    static constexpr int FontCorrectionX = 4;
    static constexpr int FontCorrectionY = 3;
    static constexpr int CountLimit = 30;
    static constexpr int FontBetweenCorrectionY = 45;
    static constexpr int NumberCorrectionX = 300;
    int redColor;
    int whiteColor;
    int blackColor;
    int step;//どこまで進んでいるか
    int nextTutorialCount;//一定値を超えると次のチュートリアルへ行かせる

};

