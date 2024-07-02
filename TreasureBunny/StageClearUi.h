#pragma once


class StageClearUi
{
public:
    StageClearUi();
    ~StageClearUi();
    void Initialize();
    void UpDate();
    void Draw(int clearImgHandle);
    bool GetIsClearCount();

private:
    static constexpr int ResetCount = 200;
    static constexpr int LimitCount = 0;
    static constexpr int ClearImgX = 450;
    static constexpr int ClearImgY = 200;
    static constexpr int ClearImgWidth = ClearImgX + 390;
    static constexpr int ClearImgHeight = ClearImgY + 150;

    int DrawCount;
};