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
    static constexpr int PullStep = 1;//ˆø‚«o‚³‚¹‚é‰ñ”
    static constexpr int SearchBlockNumber = 60;

};