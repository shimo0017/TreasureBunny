#pragma once
#include"BaseTutorialUi.h"


class TutorialUi2 :public BaseTutorialUi
{
public:
    TutorialUi2();
    ~TutorialUi2();
    BaseTutorialUi* Update(const int step);
    void Draw(const int fontHandle, const int sheetImgHandle);
    int GetSearchBlockNumber()const { return SearchBlockNumber; }
private:
    static constexpr int PullStep = 2;//�����o�������
    static constexpr int SearchBlockNumber = 61;

};