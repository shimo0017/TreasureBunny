#pragma once


class Paper
{
public:
    enum class KindsColor
    {
        Red,
        Green,
        Blue,
        Yellow,
    };

    Paper(VECTOR position);
    ~Paper();
    void UpDate();
    void Draw(const int colorHandle[]);

private:
    static constexpr int MaxKinds = 4;
    static constexpr int MinKinds = 0;
    static constexpr float LimitY = 300;
    static constexpr float FallSpeed = 0.3f;
    static constexpr float BaseCentre = 1.0f;
    static constexpr int MaxDivisionNumber = 10;
    static constexpr float TurnSpeed = 2.0;
    static constexpr float MaxAngle = 360.0f;
    void Move();
    void ChangeDirection();

    KindsColor kinds;
    VECTOR position;
    VECTOR startPosition;
    float centreX;
    float centreY;
    float angle;
    bool isTurnLeft;
};

