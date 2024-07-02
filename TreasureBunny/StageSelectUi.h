#pragma once

class StageSelectUi
{
public:
	StageSelectUi();
	~StageSelectUi();
	void Initialize();
	bool UpData(const int nowMapNumber, bool isFade);
	void Draw(const int nowMapNumber, const int selectFontHandle, const int nSelectFontHandle, const int clearImgHandle, const int stageImg[], const int accessoryImg, bool isClear, bool isFade);
	//void Rotation();
private:
	static constexpr int MaxMap = 5;//ステージ数
	static constexpr int MaxAccessory = 2;//写真以外の画像数
	static constexpr int CorrectionX = 50;
	static constexpr int CorrectionY = 70;
	static constexpr int StagePositionX = 240;
	static constexpr int StagePositionY = 280;
	static constexpr int StagePositionWidth = StagePositionX+300;
	static constexpr int StagePositionHeight = StagePositionY+300;

	static constexpr int NumberPositionX = 190;
	static constexpr int NumberPositionY = 120;
	static constexpr int RightNoteBaceY = 400;
	static constexpr double MagnificationRate = 1.0;//拡大率
	static constexpr int Scale = 2;
	static constexpr int StartPosition = 800;
	static constexpr int StartPositionY = 700;
	static constexpr int MinTransparency = 0;
	static constexpr int MaxTransparency = 255;
	static constexpr int ClearImgX = 735;
	static constexpr int ClearImgY = 180;
	static constexpr int ClearImgWidth = ClearImgX +390;
	static constexpr int ClearImgHeight = ClearImgY+150;
	static constexpr int CorrectionShadowX = 4;
	static constexpr int CorrectionShadowY = 3;
	static constexpr int StarPosition = StartPosition-20;

	static constexpr LPCSTR Tutorial = "チュートリアル";
	static constexpr LPCSTR FirstStage = "ステージ1";
	static constexpr LPCSTR SecondStage = "ステージ2";
	static constexpr LPCSTR ThirdStage = "ステージ3";
	static constexpr LPCSTR Fourstage = "ステージ4";

	/// <summary>
	/// チュートリアルステージやステージ1など
	/// </summary>
	void DrawStageNumber(int mapNumber, int fontHandle);
	static bool stageCrear[MaxMap];
	static bool isFirstConstructor;
	int transparency;

	//double angle;//角度
};