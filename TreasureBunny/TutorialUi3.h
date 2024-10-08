#pragma once
#include"BaseTutorialUi.h"


class TutorialUi3 :public BaseTutorialUi
{
public:
    TutorialUi3();
    ~TutorialUi3();
    BaseTutorialUi* Update(const int step);
    void Draw(const int fontHandle, const int sheetImgHandle);
    int GetSearchBlockNumber()const { return SearchBlockNumber; }
private:
    static constexpr int PullStep = 1;//引き出させる回数
    static constexpr int SearchBlockNumber = 60;

};