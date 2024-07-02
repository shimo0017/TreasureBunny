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
	//�����Ȃ�
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
	//�m�[�g�̍��ɃX�e�[�W�̉摜��
	DrawExtendGraph(StagePositionX, StagePositionY, StagePositionWidth, StagePositionHeight,stageImg[nowMapNumber],TRUE);
	//�m�[�g�̍���ɃX�e�[�W����
	DrawStageNumber(nowMapNumber, nSelectFontHandle);
	//��Փx�\��
	DrawFormatStringToHandle(StartPosition+ CorrectionShadowX, RightNoteBaceY+ CorrectionShadowY, GetColor(0,0,0), selectFontHandle, "��Փx");
	DrawFormatStringToHandle(StartPosition , RightNoteBaceY, GetColor(255, 255, 255), selectFontHandle, "��Փx");
	int mapNumber = nowMapNumber;
	if (nowMapNumber == 0)
	{
		mapNumber = 1;
	}
	for (int i = 0; i < mapNumber; i++)
	{
		//����\��
		int x = StarPosition + CorrectionX * i;
		int y = RightNoteBaceY + CorrectionY;
		DrawGraph(x,y, accessoryImg, TRUE);
	}
	//�Q�[���N���A�̎��̏���
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
		//�^�C�g���̃X�e�[�W�Z���N�g��ʂ̏���
		//�m�[�g�̉E���clear�ς݂��\��
		if (nowMapNumber>=0&&stageCrear[nowMapNumber]==true)
		{
			DrawExtendGraph(ClearImgX, ClearImgY, ClearImgWidth,ClearImgHeight, clearImgHandle, TRUE);
		}
		DrawFormatStringToHandle(StartPosition+ CorrectionShadowX, StartPositionY+ CorrectionShadowY, GetColor(0,0,0), selectFontHandle, "�X�^�[�g�I");
		DrawFormatStringToHandle(StartPosition , StartPositionY, GetColor(255, 255, 255), selectFontHandle, "�X�^�[�g�I");

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
