#pragma once

class Map;
class BaseTutorialUi;
class TutorialManagerUi
{
public:
    TutorialManagerUi();
    ~TutorialManagerUi();
    void Initialize();
    void Update(const Map& map, const bool isHitGool);
    void Draw(int fontHandle, int sheetImgHandle)const;
private:

    int nowStepNumber;//現在のチュートリアル
    BaseTutorialUi* tutorial;
};

