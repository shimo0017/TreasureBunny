#pragma once
#include"BaseTutorialUi.h"
class TutorialUi1:public BaseTutorialUi
{
public:
    TutorialUi1();
    ~TutorialUi1();
    BaseTutorialUi* Update(const int nowStep)override;
    void Draw(const int fontHandle, const int sheetImgHandle)override;
    int GetSearchBlockNumber()const { return SearchBlockNumber; };

private:
    static constexpr int PullStep = 3;//ˆø‚«o‚³‚¹‚é‰ñ”
    static constexpr int SearchBlockNumber = 77;
};

