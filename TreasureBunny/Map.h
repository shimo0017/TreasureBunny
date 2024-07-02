#pragma once

#include<vector>

class Block;
class Map
{
public:
	Map();
	~Map();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 更新（クールタイム）
	/// </summary>
	void UpDate();
	/// <summary>
	/// block描画
	/// </summary>
	/// <param name="playerPos"></param>
	void DrawMap(VECTOR playerPos);
	void DrawSky();
	/// <summary>
	/// ステージを始めたときにブロックをセットする
	/// </summary>
	void SetMap();
	/// <summary>
	/// マップ番号をセット
	/// </summary>
	void SetMapNumber(int number);
	/// <summary>
	/// ブロックを動かす
	/// </summary>
	/// <param name="moveVector"></param>
	bool BlockMove(VECTOR moveVector,int hitNumber, int& moveDirection,int graspDirection);
	/// <summary>
	/// 指定した場所の種類番号取得
	/// </summary>
	/// <param name="i"></param>
	/// <param name="j"></param>
	/// <returns></returns>
	int GetCell(int i, int j) const { return cell[mapNumber][i][j]; }

	/// <summary>
	/// 何マップ目か取得
	/// </summary>
	/// <returns></returns>
	int GetMapNumber() const { return mapNumber; }
	/// <summary>
	/// ブロックのモデル番号取得
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	int GetBlockModel(int i)const;
	/// <summary>
	/// 全部のブロック数取得
	/// </summary>
	/// <returns></returns>
	int GetBlockNuber()const { return blockNumber; }
	/// <summary>
	/// 全部の地面数取得
	/// </summary>
	/// <returns></returns>
	int GetSoilNumber()const { return soilNumber; }
	/// <summary>
	/// 地面の高さ取得
	/// </summary>
	/// <returns></returns>
	float GetSoilPositionY()const { return InitializePositionY; }
	/// <summary>
	/// リセットカウント取得
	/// </summary>
	/// <returns></returns>
	int GetResetCount()const { return resetCount; }
	/// <summary>
	/// ブロックの種類取得
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	int GetBlockKinds(int i)const;
	/// <summary>
	/// ゴールかどうかを取得
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	bool GetIsGool(int i)const;
	/// <summary>
	/// ブロックの引き出している段階取得
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	int GetBlockStep(int i)const;
	/// <summary>
	/// 透明か取得
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	bool GetIsTransparent(int i)const;
private:
	static constexpr int	BlockKinds = 4;//ブロックの種類数
	static constexpr int	AccessoriesKinds = 1;//小物の種類
	static constexpr int	MapX = 8;//block全体のX量
	static constexpr int	MapY = 8;//block全体のY量
	static constexpr int	SoilX = 10;//地面全体のX量
	static constexpr int	SoilY = 6;//地面全体のY量
	static constexpr float	CorrectionX = 4.0f;//ブロック・地面の配置間隔
	static constexpr float	CorrectionY = 3.9f;//ブロックの配置間隔
	static constexpr float	CorrectionZ = 4.0f;//ブロックの配置間隔
	static constexpr float	InitializePositionY = 0.0f;//地面を配置する高さ
	static constexpr float	InitializePositionZ = 15.0f;//ブロック配置する奥行
	static constexpr int	NoBaseBlock = 3;//動かせるブロックが何番からか
	static constexpr int	SearchBlockX = 1;//ブロック配列をXの場合1ずつずらして探す
	static constexpr int	SearchBlockY = 1;//ブロック配列をXの場合8ずつずらして探す
	static constexpr int	PullPushBlockCoolDown = 60;	//ブロックを一段階押し引きするとクールダウン
	static constexpr int	BaseParentNumber = -1;//一番手前のブロックを表す
	static constexpr int	FirstStepNumber = 0;//一番手前のブロックを生成するときの段階
	static constexpr int	ResetTiming = 150;//到達後リセットする
	static constexpr int	MaxMap = 5;//最大マップ数
	static constexpr float	StopTransparent = 15.1f;//これ以上の時透明
	static constexpr float	CenterXY = 0.5f;//中心
	static constexpr float	CoinImgSize = 1.0f;//等倍
	static constexpr float	CoinImgAngle = 0.0f;//角度
	static constexpr float	CoinCorrectionY = 2.0f;//コインモデルずらし量
	static constexpr float	CoinImgCorrectionZ = -2.5f;//コイン画像ずらし量

	/// <summary>
	/// ブロックを探す
	/// </summary>
	/// <param name="count"></param>
	/// <param name="number"></param>
	/// <param name="numberpoint"></param>
	void SearchBlock(int &count,int number[],int numberPoint,int kinds,bool isPlus,bool isX,int startPoint, VECTOR pos);
	/// <summary>
	/// クールダウン更新
	/// </summary>
	void EndCoolDown();
	/// <summary>
	/// 後ろのブロックの透明処理
	/// </summary>
	void SetTransparent();
	/// <summary>
	/// ブロックを一番最初の状態に
	/// </summary>
	void ResetBlock();
	/// <summary>
	/// マップロード
	/// </summary>
	void LoadMap(const char* fileName);
	//static Block block[MapX*MapY*3+SoilX*SoilY];
	static std::vector<Block> block;
	static COLOR_F	colorBlock[3];//ブロックの前面の色　0：赤　1：緑　2：青
	static int cell[MaxMap][MapY][MapX];	//ブロック配置配列
	static int soilCell[SoilY][SoilX];	//地面配置配列
	static int baseModel[BlockKinds + AccessoriesKinds];	//元にするモデル
	static int SkyModel;			//スカイドームモデル
	static int coinModel;			//コインモデル
	static int coinImg;			//コインイメージ
	static bool isFirstConstructor;

	int mapNumber;			//何マップ目か
	int blockNumber;		//ブロックの数
	int soilNumber;			//地面の数
	bool isCoolDown;		//クールダウン中か
	int resetCount;			//リセットカウント
	int coolDown;

};
