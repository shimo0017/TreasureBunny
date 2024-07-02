#include"DxLib.h"
#include"UiManager.h"
#include"Map.h"
#include"TitleUi.h"
#include"UiBook.h"
#include"ResetGauge.h"
#include"StageSelectUi.h"
#include"CountDownUi.h"
#include"PauseSelectUi.h"
#include"PressUi.h"
#include"MethodOperation.h"
#include"TutorialManagerUi.h"
#include"StageClearUi.h"

bool UiManager::isFirstConstructor=false;
int UiManager::selectFontHandle=0;//フォント大
int UiManager::nSelectFontHandle=0;//フォント中
int UiManager::explanaFont=0;//フォント小
int UiManager::TutorialFontHandle=0;//チュートリアルフォント
int UiManager::countDownFont=0;
int UiManager::boardImg=0;
int UiManager::handImg = 0;
int UiManager::sheetImg = 0;
int UiManager::clearImgHandle = 0;
int UiManager::bookHandle = 0;//本の画像
int UiManager::gaugeImg = 0;
int UiManager::stageImg[] = {0};//ステージの画像
int UiManager::accessoryImg = 0;//小物画像



UiManager::UiManager() :
	titleUi(new TitleUi()),
	uiBook(new UiBook()),
	resetGauge(new ResetGauge()),
	stageSelectUi(new StageSelectUi()),
	countDownUi(new CountDownUi()),
	pauseSelectUi(new PauseSelectUi()),
	pressUi(new PressUi()),
	methodOperationUi(new MethodOperation()),
	tutorialManagerUi(new TutorialManagerUi()),
	stageClearUi(new StageClearUi())
{

	if (isFirstConstructor == false)
	{
		selectFontHandle = CreateFontToHandle(FontName, 60, 9);
		nSelectFontHandle = CreateFontToHandle(FontName, 40, 9);
		explanaFont = CreateFontToHandle(FontName, 25, 9);
		TutorialFontHandle= CreateFontToHandle(FontName, 30, 9);
		countDownFont = CreateFontToHandle(FontName, 110, 9);

		boardImg = LoadGraph("Img/Board.png");
		handImg = LoadGraph("Img/拳.png");
		sheetImg = LoadGraph("Img/Sheet.png");
		clearImgHandle = LoadGraph("Img/Complete.png");
		bookHandle = LoadGraph("Img/Book.png");
		gaugeImg = LoadGraph("Img/gauge.png");
		accessoryImg = LoadGraph("Img/Star.png");
		stageImg[0] = LoadGraph("Img/TutorialStage.png");
		stageImg[1] = LoadGraph("Img/FirstStage.png");
		stageImg[2] = LoadGraph("Img/SecondStage.png");
		stageImg[3] = LoadGraph("Img/ThirdStage.png");
		stageImg[4] = LoadGraph("Img/FourStage.png");
		isFirstConstructor = true;
	}

}
UiManager::~UiManager()
{
	delete titleUi;
	delete uiBook;
	delete resetGauge;
	delete stageSelectUi;
	delete countDownUi;
	delete pauseSelectUi;
	delete pressUi;
	delete methodOperationUi;
	delete tutorialManagerUi;
	delete stageClearUi;
}
void UiManager::Initialize()
{
	stageSelectUi->Initialize();
	stageClearUi->Initialize();
	delete tutorialManagerUi;
	tutorialManagerUi = new TutorialManagerUi();
}
void UiManager::TitleDraw(int nowMapNumber, int titleSelect, bool stageSelectMode)
{
	titleUi->Draw(titleSelect, selectFontHandle, nSelectFontHandle, boardImg);
	if (stageSelectMode)
	{
		static bool isClear = false;
		uiBook->Draw(bookHandle);
		stageSelectUi->Draw(nowMapNumber, selectFontHandle, nSelectFontHandle, clearImgHandle, stageImg, accessoryImg, isClear, false);
	}
}
bool UiManager::Update(const Map& map,const bool isHitGool,bool isClear)
{
	bool displayOut = false;
	if (isClear == false)
	{
		if (map.GetMapNumber() == TutorialNumber)
		{
			tutorialManagerUi->Update(map, isHitGool);
		}
		if (isHitGool)
		{
			stageClearUi->UpDate();
		}
	}
	else
	{
		displayOut = stageSelectUi->UpData(map.GetMapNumber(), isHitGool);
	}
	return displayOut;
}
void UiManager::GameDraw(int resetCount,bool endCountDownFlag,int nowTime,bool isGrasp, int blockNumber, bool isEndCountDown,int mapNumber, const bool isHitGool)
{
	if (isHitGool == false)
	{
		resetGauge->Draw(gaugeImg,resetCount);
		if (isGrasp)
		{
			DrawExtendGraph(HandX, HandY, HandWidth, HandHeight, handImg, TRUE);
		}
		if (blockNumber >= 0)
		{
			pressUi->Draw(nSelectFontHandle);
		}
		if (isEndCountDown == true)
		{
			methodOperationUi->Draw(nSelectFontHandle,sheetImg);
		}
		//チュートリアルの時以外は動かさない
		if (mapNumber == TutorialNumber)
		{
			tutorialManagerUi->Draw(nSelectFontHandle,sheetImg);
		}
		if (endCountDownFlag == false)
		{
			countDownUi->Draw(nowTime, countDownFont);
		}
	}
	else
	{
		stageClearUi->Draw(clearImgHandle);
	}
}
void UiManager::PauseDraw(bool isTitle)
{
	uiBook->Draw(bookHandle);
	pauseSelectUi->Draw(isTitle, selectFontHandle, nSelectFontHandle, boardImg);
}
void UiManager::GameClearDraw(int nowMapNumber,bool isFade)
{
	static bool isClear = true;

	uiBook->Draw(bookHandle);
	return stageSelectUi->Draw(nowMapNumber, selectFontHandle, nSelectFontHandle, clearImgHandle, stageImg, accessoryImg, isClear, isFade);
}
bool UiManager::GetIsClearCount()
{
	return stageClearUi->GetIsClearCount();
}