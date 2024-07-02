#pragma once

class Player;
class Camera
{
public:
    Camera();
    ~Camera();
    void Initialize();
    void UpDate(const Player &player);
    void TitleUpdate(const Player& player);
    /// <summary>
    /// カメラ自体の位置補正関数
    /// </summary>
    void CorrectionPosition(const VECTOR player);
    /// <summary>
    /// カメラの注視点補正関数
    /// </summary>
    void CorrectionTarget(const VECTOR player);
    /// <summary>
    /// モード切替
    /// </summary>
    void SelectMode();
    /// <summary>
    /// 移動
    /// </summary>
    void Move();
    bool GetModePlayer() { return modePlayer; }
private:
    static constexpr float DistancePlayer=20.0f;//プレイヤーからどれだけカメラを離すか
    static constexpr float TargetHeightPlayer=-10.0f;//プレイヤーをどれだけ上から見るか
    static constexpr float MoveY = 1.0f;//カメラの移動速度
    static constexpr float StartX = -14.0f;//
    static constexpr float StartY = -12.0f;
    static constexpr float StartZ = -6.0f;
    static constexpr float MaxMove = 30.0f;//上移動限界
    static constexpr float MinMove = 0.0f;//下移動限界
    VECTOR position;//カメラの位置
    VECTOR target;//カメラの注視点
    bool modePlayer;//プレイヤーを中心にするか
    bool hitShift;
    float sumCorrectionY;//モードを変えてからのYの合計ずらし量

};