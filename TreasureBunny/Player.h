#pragma once

class Map;
enum class GameStatus;
class SoundManager;
class Collision;
/// <summary>
/// プレイヤー
/// </summary>
class Player
{
public:

	/// <summary>
	/// 状態
	/// </summary>
	enum class Status
	{
		STAND,//待機
		WALK,//歩き
		JAMP,//ジャンプ
		GRASP,//物をつかむ
		FALL,//落下
	};
	enum class AnimeKinds
	{
		STAND=3,//待機
		WALK=14,//歩き
		JAMP=7,//ジャンプ
		GRASP=18,//物をつかむ
		FALL=8,//落下
	};
	//enum class GraspDirection
	//{
	//	CLOSER,//手前
	//	LEFT,
	//	RIGHT,
	//	FARTHER//奥
	//};
	Player();
	~Player();

	/// <summary>
	/// モデルロード関数
	/// </summary>
	void LoadModel();
	/// <summary>
	/// モデル読み込み破棄関数
	/// </summary>
	void UnLoadModel();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// アップデート関数
	/// </summary>
	void UpDate(Map &map, Collision &collision, SoundManager& soundManager, bool& isHitGool);
	/// <summary>
	/// タイトル用
	/// </summary>
	/// <param name="map"></param>
	/// <param name="collision"></param>
	void TitleMove(Map& map, Collision collision, bool& isHitGool);
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	///ブロックを移動させているかと方向をセット
	/// </summary>
	/// <param name="isMove"></param>
	/// <param name="moveDirection"></param>
	void SetBlockMove(bool isMove,int moveDirection);
	/// <summary>
	/// 何もつかめなかった時
	/// </summary>
	void SetNoHit();
	/// <summary>
	/// 床に当たっているとき
	/// </summary>
	/// <param name="verocity"></param>
	void OnHitFloor();
	/// <summary>
	/// 床に一度も当たらなかったとき
	/// </summary>
	void NoHitFloor();
	/// <summary>
	/// 天井に当たっているとき
	/// </summary>
	void OnHitCeiling();
	/// <summary>
	/// ポジション取得
	/// </summary>
	/// <returns></returns>
	VECTOR GetPosition() const { return position; }
	/// <summary>
	/// 現在の状態取得
	/// </summary>
	/// <returns></returns>
	Status GetStatus() const { return status; }
	/// <summary>
	/// 現在のジャンプ力取得
	/// </summary>
	/// <returns></returns>
	float GetJampPawer()const { return jampPawer; }
	/// <summary>
	/// つかみ状態になれる向きを取得
	/// </summary>
	/// <returns></returns>
	int GetGraspDrection()const;
	/// <summary>
	/// ブロックを移動させなくてはいけない方向取得
	/// </summary>
	/// <returns></returns>
	int GetGraspMoveDirection()const { return graspMoveDirection; };
	/// <summary>
	/// つかんで移動させているとき
	/// </summary>
	/// <returns></returns>
	bool GetGraspMove()const { return status==Status::GRASP&&isBlockMove; }
	/// <summary>
	/// つかんでいるとき
	/// </summary>
	/// <returns></returns>
	bool GetGrasp()const { return status == Status::GRASP; }
	/// <summary>
	/// 移動スピード取得
	/// </summary>
	/// <returns></returns>
	float GetMoveSpeed()const { return MoveSpeed; }
	/// <summary>
	/// 現在動いているか取得
	/// </summary>
	/// <returns></returns>
	bool GetIsMove()const { return isMove; }
	/// <summary>
	/// 二つのベクトルがほぼ同じか
	/// </summary>
	/// <param name="vector1"></param>
	/// <param name="vector2"></param>
	/// <returns></returns>
	bool IsNearAngle(const VECTOR& vector1, const VECTOR& vector2);
	/// <summary>
	/// nowVectorをaimVectorにdegreeVerocity速度で回転
	/// </summary>
	/// <param name="nowVector"></param>
	/// <param name="aimVector"></param>
	/// <param name="degreeVerocity"></param>
	/// <returns></returns>
	VECTOR RotateForAimVecYAxis(const VECTOR& nowVector, const VECTOR& aimVector, float degreeVerocity);
	/// <summary>
	/// 時計回り方向の時は1.0 反時計回り方向の時は -1.0を返す
	/// </summary>
	/// <param name="nowVector"></param>
	/// <param name="dirVector"></param>
	/// <returns></returns>
	float CalcRotationDirectionYAxis(const VECTOR& nowVector, const VECTOR& dirVector);

	//コリジョン用
	
	/// <summary>
	/// 地面に接地しているとき
	/// </summary>
	void OnFall();
	float GetJumpPower() { return jampPawer; }
private:
	static constexpr float MoveSpeed = 0.1f;	//移動速度
	static constexpr float TurnSpeed = 15.0f;	//振り向き速度
	static constexpr float JampSpeed = 0.30f;	//ジャンプの初速
	static constexpr float Gravity = -0.01f;	//重力
	static constexpr float StartPosX = 15.0f;
	static constexpr float StartPosY = 2.0f;
	static constexpr float StartPosZ = 2.0f;
	static constexpr float LimitRight = 33.0f;
	static constexpr float LimitLeft = -5.0f;
	static constexpr float LimitFarther = 12.7f;
	static constexpr float LimitCloser = -10.0f;
	static constexpr float HalfDegrees = 180.0f;
	static constexpr float MinDegrees = 0.0f;
	static constexpr float MaxDegrees = 360.0f;
	static constexpr float BackRightDegrees = -135.0f;			//右奥回転
	static constexpr float CorrectionBackRightDegrees = -225.0f;//右奥回転のangle用修正
	static constexpr float RightDegrees = 90.0f;				//右奥回転
	static constexpr float CorrectionRightDegrees = 270.0f;		//右回転のangle用修正
	static constexpr float RightFrontDegrees = -45.0f;			//右手前回転
	static constexpr float CorrectionRightFrontDegrees = 315.0f;//右手前回転のangle用修正
	static constexpr int Scale=-1;
	static constexpr float FallUpPower = 0.05f;
	static constexpr float AnimeAdvanceTime = 0.5f;//時間をどれだけ進めるか
	

	/// <summary>
	/// キー入力によって移動・回転パラメーターをセットする
	/// </summary>
	/// <returns></returns>
	Status SetMoveParameter(VECTOR& moveVector, SoundManager& soundManager);
	/// <summary>
	/// 動き
	/// </summary>
	void Move(Map& map, Collision collision, VECTOR moveVector,bool& isHitGool);
	/// <summary>
	/// 方向転換
	/// </summary>
	/// <param name="moveVector"></param>
	void ChangeDirection();
	/// <summary>
	/// つかみ状態
	/// </summary>
	void ModeGrasp();
	/// <summary>
	/// アニメーション変更
	/// </summary>
	Status ChangeAnimation();

	VECTOR position;
	VECTOR direction;
	VECTOR nextDirection;
	float angle;//モデルの向いている角度
	float targetAngle;
	static int baseModelHandle;
	 int modelHandle;
	static bool isLoadModel;
	Status status;			//処理用状態
	Status animeStatus;		//アニメーション用ステータス
	Status previousAnimeStatus;//前のアニメーション
	float jampPawer;		//Y軸方向の速度
	bool isBlockMove;		//ブロックを移動中か
	int graspMoveDirection;	//ブロックを移動させなくてはいけない方向(0：移動させてない　2：奥　3：手前)
	bool titleMoveDirection;//タイトルで動く方向
	bool isMove;
	bool isRotaNow;//回転中か
	float animationTime;
	float animationMaxTime;
	int animationKinds;
};