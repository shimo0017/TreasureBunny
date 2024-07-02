#pragma once

class Map;
class TitleUi;
class UiBook;
class ResetGauge;
class StageSelectUi;
class CountDownUi;
class PauseSelectUi;
class PressUi;
class MethodOperation;
class TutorialManagerUi;
class StageClearUi;

class UiManager
{
public:
	UiManager();
	~UiManager();
	void Initialize();
	bool Update(const Map&map, const bool isFadeOut, bool isClear);
	void TitleDraw(int nowMapNumber, int titleSelect, bool stageSelectMode);
	void GameDraw(int resetCount, bool endCountDownFlag, int nowTime, bool isGrasp,int blockNumber,bool isEndCountDown, int mapNumber, const bool isHitGool);
	void PauseDraw(bool isTitle);
	void GameClearDraw(int nowMapNumber,bool isFade);
	bool GetIsClearCount();
private:
	static constexpr LPCSTR FontName = /*"851�}�J�|�b�v"*/"RocknRoll One";
	static constexpr int SheetX = 760;
	static constexpr int SheetY = 80;
	static constexpr int SheetWidth = SheetX+130;
	static constexpr int SheetHeight = SheetY + 80;
	static constexpr int CorrectionX = 20;
	static constexpr int HandX = 510;
	static constexpr int HandY = 530;
	static constexpr int HandWidth = HandX + 50;
	static constexpr int HandHeight = HandY + 50;
	static constexpr int TutorialNumber = 0;
	static constexpr int MaxMap = 5;//�X�e�[�W��

	TitleUi* titleUi;
	UiBook* uiBook;
	ResetGauge* resetGauge;
	StageSelectUi* stageSelectUi;
	CountDownUi* countDownUi;
	PauseSelectUi* pauseSelectUi;
	PressUi* pressUi;
	MethodOperation* methodOperationUi;
	TutorialManagerUi* tutorialManagerUi;
	StageClearUi* stageClearUi;
	static bool isFirstConstructor;
	static int selectFontHandle;//�t�H���g��
	static int nSelectFontHandle;//�t�H���g��
	static int explanaFont;//�t�H���g��
	static int TutorialFontHandle;//�`���[�g���A���t�H���g
	static int countDownFont;
	static int boardImg;
	static int handImg;
	static int sheetImg;
	static int clearImgHandle;
	static int bookHandle;//�{�̉摜
	static int gaugeImg;
	static int stageImg[MaxMap];//�X�e�[�W�̉摜
	static int accessoryImg;//�����摜

};