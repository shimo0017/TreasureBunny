#include"DxLib.h"
#include "BaseTutorialUi.h"


BaseTutorialUi::BaseTutorialUi():
    redColor(GetColor(255, 0, 0)),
    whiteColor(GetColor(255, 255, 255)),
    blackColor(GetColor(0, 0, 0)),
    step(0),
    nextTutorialCount(0)
{
}
BaseTutorialUi::~BaseTutorialUi()
{

}
