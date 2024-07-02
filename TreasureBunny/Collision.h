#pragma once

class Map;
class Player;
enum class GameStatus;

class Collision
{
public:
	Collision();
	~Collision();
	/// <summary>
	/// プレイヤーとブロックの当たり判定指示
	/// </summary>
	/// <param name="map"></param>
	/// <param name="player"></param>
	/// <param name="moveVector"></param>
	/// <returns></returns>
	VECTOR HitBlockPlayer(Map& map, Player& player, VECTOR& moveVector, bool& isHitGool);
		/// <summary>
	/// プレイヤーとブロックの当たり判定
	/// </summary>
	/// <param name="player"></param>
	/// <param name="model"></param>
	/// <param name="startPosition"></param>
	/// <param name="endPosition"></param>
	/// <param name="isGool"></param>
	void OnCollision(Player& player, int model,VECTOR& moveVector, bool isGool, bool& isFall, bool& isHitGool);
	/// <summary>
	/// 手との当たり判定
	/// </summary>
	/// <param name="player"></param>
	/// <param name="map"></param>
	int HitHand(Player& player, Map& map);
	/// <summary>
	/// 横からブロックを動かすとき奥一マスにを調べ動かす
	/// </summary>
	/// <param name="player"></param>
	/// <param name="map"></param>
	/// <param name="moveVector"></param>
	void HitDepthBlock(Player& player, Map& map, VECTOR moveVector,const int blockNumber );
private:
	static constexpr float	HitSlideLength = 0.1f;	// 一度の壁押し出し処理でスライドさせる距離
	static constexpr float  CorrectionY = 1.5f;		//当たり判定を上にずらす
	static constexpr float  CorrectionX = 0.0f;  //当たり判定を左右にずらす
	static constexpr float  CorrectionZ = 0.0f;  //当たり判定を奥、手前にずらす
	static constexpr float	CheckDepthRange = 5.8f;//つかんだ方向が左右の場合ものがあるか確認する奥行
	static constexpr float	DirectionLine = 3.0f;	//キャラクターからどれだけの距離をつかめるか
	static constexpr float	radius = 1.5f;			//半径
	static constexpr int	MaxTry = 1;				//最大ずらし回数

	//ここからyuiアレンジ
	static constexpr int MaxHitColl = 2048;	// 処理するコリジョンポリゴンの最大数
	static constexpr float	DefaultSize = 10.0f;	// 周囲のポリゴン検出に使用する球の初期サイズ
	static constexpr float	HitWidth = 3.0f;	// 当たり判定カプセルの半径
	static constexpr float	HitHeight = 4.0f;	// 当たり判定カプセルの高さ
	static constexpr int	HitTryNum = 16;		// 壁押し出し処理の最大試行回数

	VECTOR CheckHitWithFloor(Player& player, const VECTOR& checkPosition);
	VECTOR CheckHitWithWall(Player& player, const VECTOR& checkPosition);
	void AnalyzeWallAndFloor(MV1_COLL_RESULT_POLY_DIM hitDim, const VECTOR& checkPosition);

	//MV1_COLL_RESULT_POLY* wall[MaxHitColl];	// 壁ポリゴンと判断されたポリゴンの構造体のアドレスを保存しておくためのポインタ配列
	//MV1_COLL_RESULT_POLY* floor[MaxHitColl];	// 床ポリゴンと判断されたポリゴンの構造体のアドレスを保存しておくためのポインタ配列
	//int							wallNum;			// 壁ポリゴンと判断されたポリゴンの数
	//int							floorNum;			// 床ポリゴンと判断されたポリゴンの数

};

