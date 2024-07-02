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
    /// �J�������̂̈ʒu�␳�֐�
    /// </summary>
    void CorrectionPosition(const VECTOR player);
    /// <summary>
    /// �J�����̒����_�␳�֐�
    /// </summary>
    void CorrectionTarget(const VECTOR player);
    /// <summary>
    /// ���[�h�ؑ�
    /// </summary>
    void SelectMode();
    /// <summary>
    /// �ړ�
    /// </summary>
    void Move();
    bool GetModePlayer() { return modePlayer; }
private:
    static constexpr float DistancePlayer=20.0f;//�v���C���[����ǂꂾ���J�����𗣂���
    static constexpr float TargetHeightPlayer=-10.0f;//�v���C���[���ǂꂾ���ォ�猩�邩
    static constexpr float MoveY = 1.0f;//�J�����̈ړ����x
    static constexpr float StartX = -14.0f;//
    static constexpr float StartY = -12.0f;
    static constexpr float StartZ = -6.0f;
    static constexpr float MaxMove = 30.0f;//��ړ����E
    static constexpr float MinMove = 0.0f;//���ړ����E
    VECTOR position;//�J�����̈ʒu
    VECTOR target;//�J�����̒����_
    bool modePlayer;//�v���C���[�𒆐S�ɂ��邩
    bool hitShift;
    float sumCorrectionY;//���[�h��ς��Ă����Y�̍��v���炵��

};