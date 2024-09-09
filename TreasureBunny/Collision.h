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

};

