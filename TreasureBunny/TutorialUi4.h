#pragma once
#include"BaseTutorialUi.h"

class TutorialUi4 :public BaseTutorialUi
{
public:
    TutorialUi4();
    ~TutorialUi4();
    BaseTutorialUi* Update(const int step);
    void Draw(const int fontHandle, const int sheetImgHandle);
    int GetSearchBlockNumber()const { return SearchBlockNumber; }
private:
    static constexpr int GoolStep = 1;//ゴールしたとき
    static constexpr int SearchBlockNumber = 60;//ここだけは今回なんでもいい

};