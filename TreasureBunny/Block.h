#pragma once
class Block
{
public:
	Block(int model, VECTOR pos,int kindsNumber, COLOR_F color,int parentnumber,int startstepNumber, bool gool);
	~Block();
	void Draw();
	void UpDate();
	/// <summary>
	/// 一番手前のブロックを動かす
	/// </summary>
	/// <param name="moveVector"></param>
	/// <param name="isCoolDown"></param>
	/// <param name="StartPosition"></param>
	/// <param name="moveDirection"></param>
	/// <returns></returns>
	bool SetMoveCloser(VECTOR moveVector,bool& isCoolDown, float StartPosition,int &moveDirection);
	/// <summary>
	/// 奥のブロック二つを手前のブロックに追従させる
	/// </summary>
	/// <param name="CloserPosition"></param>
	void SetMoveFarther(VECTOR closerPosition,float correctionZ);
	/// <summary>
	/// ブロックの透明処理
	/// </summary>
	/// <param name="Transparent"></param>
	void SetTransparent(bool Transparent);
	/// <summary>
	/// ブロックの色面以外の透明処理
	/// </summary>
	void SetMeshTransparent();
	/// <summary>
	/// ブロックを最初の状態に戻す
	/// </summary>
	void ResetBlock();
	int GetModel() { return model; }
	int GetKinds() { return kinds; }
	bool GetGool() { return isGool;}
	int GetStep() { return step; }
	/// <summary>
	/// 奥のブロックの場合一番手前の番号をいれておりそれを取得
	/// </summary>
	/// <returns></returns>
	int GetParentNumber() { return parentNumber; }
	bool GetIsTransparent() { return isTransparent; }
	VECTOR GetPosition() { return position; }
	VECTOR GetCreatePosition() { return createPosition; }
private:
	static constexpr float	CorrectionZ = 4.0f;//ブロックの配置間隔
	static constexpr int MaxStep = 3;
	static constexpr int MinStep = 0;
	static constexpr int	BaseParentNumber = -1;//一番手前のブロックを表す
	static constexpr int	DownStepNoBaseParent = -1;//作成時手前のブロックではないときステップを引く値
	static constexpr float	setOpacity = 1.0f;//透明度0
	static constexpr float	SetCleanness = 0.0f;//透明度100
	static constexpr int MeshNumber=4;
	int model;//ブロックのモデル
	VECTOR position;//位置
	VECTOR createPosition;//作った位置
	int kinds;//種類
	bool isGool;//ゴールかどうか
	int step;//ブロックの現在引き出されている段階（最大3)
	int nextStep;//次の段階
	bool completeStep;//ブロックを完全に移動させたか
	int	parentNumber;//後ろのブロックの一番手前のブロックの番号(-1が一番手前)
	int startStep;//作られた時の段階
	bool isTransparent;//透明かどうか
	MV1_REF_POLYGONLIST polygonList;
};
