#include"DxLib.h"
#include"StageSelectUi.h"

bool StageSelectUi::stageCrear[] = {false};
bool StageSelectUi::isFirstConstructor=false;


StageSelectUi::StageSelectUi():
	transparency(0)
{
	if (isFirstConstructor == false)
	{
		for (int i = 0; i < MaxMap; i++)
		{
			stageCrear[i] = false;
		}
		isFirstConstructor = true;
	}
}
StageSelectUi::~StageSelectUi()
{
	//処理なし
}
void StageSelectUi::Initialize()
{
	transparency = 0;
}
bool StageSelectUi::UpData(const int nowMapNumber, bool isFade)
{
	if (transparency < MaxTransparency)
	{
		if (isFade)
		{
			transparency++;
		}
	}
	else if (nowMapNumber > 0)
	{
		stageCrear[nowMapNumber] = true;
		return true;
	}
	else
	{
		return true;
	}
	return false;
}
void StageSelectUi::Draw(const int nowMapNumber,const int selectFontHandle,const int nSelectFontHandle,const int clearImgHandle,const int stageImg[],const int accessoryImg, bool isClear, bool isFade)
{
	//ノートの左にステージの画像を
	DrawExtendGraph(StagePositionX, StagePositionY, StagePositionWidth, StagePositionHeight,stageImg[nowMapNumber],TRUE);
	//ノートの左上にステージ名を
	DrawStageNumber(nowMapNumber, nSelectFontHandle);
	//難易度表示
	DrawFormatStringToHandle(StartPosition+ CorrectionShadowX, RightNoteBaceY+ CorrectionShadowY, GetColor(0,0,0), selectFontHandle, "難易度");
	DrawFormatStringToHandle(StartPosition , RightNoteBaceY, GetColor(255, 255, 255), selectFontHandle, "難易度");
	int mapNumber = nowMapNumber;
	if (nowMapNumber == 0)
	{
		mapNumber = 1;
	}
	for (int i = 0; i < mapNumber; i++)
	{
		//星を表示
		int x = StarPosition + CorrectionX * i;
		int y = RightNoteBaceY + CorrectionY;
		DrawGraph(x,y, accessoryImg, TRUE);
	}
	//ゲームクリアの時の処理
	if (isClear)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparency);
		DrawExtendGraph(ClearImgX, ClearImgY, ClearImgWidth,ClearImgHeight, clearImgHandle,TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, MinTransparency);
		DrawFormatStringToHandle(StartPosition+ CorrectionShadowX, StartPositionY+ CorrectionShadowY, GetColor(0,0,0), selectFontHandle, "Press  B\n  Go Title");
		DrawFormatStringToHandle(StartPosition , StartPositionY, GetColor(255, 255, 255), selectFontHandle, "Press  B\n  Go Title");

	}
	else
	{
		//タイトルのステージセレクト画面の処理
		//ノートの右上にclear済みか表示
		if (nowMapNumber>=0&&stageCrear[nowMapNumber]==true)
		{
			DrawExtendGraph(ClearImgX, ClearImgY, ClearImgWidth,ClearImgHeight, clearImgHandle, TRUE);
		}
		DrawFormatStringToHandle(StartPosition+ CorrectionShadowX, StartPositionY+ CorrectionShadowY, GetColor(0,0,0), selectFontHandle, "スタート！");
		DrawFormatStringToHandle(StartPosition , StartPositionY, GetColor(255, 255, 255), selectFontHandle, "スタート！");

	}
}
void StageSelectUi::DrawStageNumber(int mapNumber,int fontHandle)
{
	LPCSTR StageName="";
	switch (mapNumber)
	{
	case 0:
		StageName = Tutorial;
		break;
	case 1:
		StageName = FirstStage;
		break;
	case 2:
		StageName = SecondStage;
		break;
	case 3:
		StageName = ThirdStage;
		break;
	case 4:
		StageName = Fourstage;
		break;
	default:
		break;
	}
	DrawStringToHandle(NumberPositionX + CorrectionShadowX, NumberPositionY + CorrectionShadowY, StageName, GetColor(0, 0, 0), fontHandle);
	DrawStringToHandle(NumberPositionX, NumberPositionY, StageName, GetColor(255, 255, 255), fontHandle);

}
