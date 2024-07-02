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
	static constexpr int MaxMap = 5;//�X�e�[�W��
	static constexpr int MaxAccessory = 2;//�ʐ^�ȊO�̉摜��
	static constexpr int CorrectionX = 50;
	static constexpr int CorrectionY = 70;
	static constexpr int StagePositionX = 240;
	static constexpr int StagePositionY = 280;
	static constexpr int StagePositionWidth = StagePositionX+300;
	static constexpr int StagePositionHeight = StagePositionY+300;

	static constexpr int NumberPositionX = 190;
	static constexpr int NumberPositionY = 120;
	static constexpr int RightNoteBaceY = 400;
	static constexpr double MagnificationRate = 1.0;//�g�嗦
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

	static constexpr LPCSTR Tutorial = "�`���[�g���A��";
	static constexpr LPCSTR FirstStage = "�X�e�[�W1";
	static constexpr LPCSTR SecondStage = "�X�e�[�W2";
	static constexpr LPCSTR ThirdStage = "�X�e�[�W3";
	static constexpr LPCSTR Fourstage = "�X�e�[�W4";

	/// <summary>
	/// �`���[�g���A���X�e�[�W��X�e�[�W1�Ȃ�
	/// </summary>
	void DrawStageNumber(int mapNumber, int fontHandle);
	static bool stageCrear[MaxMap];
	static bool isFirstConstructor;
	int transparency;

	//double angle;//�p�x
};