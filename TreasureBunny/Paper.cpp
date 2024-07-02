#include"DxLib.h"
#include "Paper.h"



Paper::Paper(VECTOR createPosition):
    kinds(KindsColor::Red)
{
    position = createPosition;
    startPosition = position;
    //’†S‚ğ‚¸‚ç‚·
    centreX = BaseCentre / (GetRand(MaxDivisionNumber) + 1);
    centreY = BaseCentre / (GetRand(MaxDivisionNumber) + 1);

    angle = 0.0;
    //ƒ‰ƒ“ƒ_ƒ€‚ÉF‚ğİ’è‚·‚é
    int kindsColor=GetRand(MaxKinds - 1);
    switch ((KindsColor)kindsColor)
    {
    case KindsColor::Red:
        kinds = KindsColor::Red;
        break;
    case KindsColor::Green:
        kinds = KindsColor::Green;
        break;
    case KindsColor::Blue:
        kinds = KindsColor::Blue;
        break;
    case KindsColor::Yellow:
        kinds = KindsColor::Yellow;
        break;
    }
    isTurnLeft = GetRand(1);
}
Paper::~Paper()
{
}
void Paper::UpDate()
{
    Move();
    ChangeDirection();
}
void Paper::Move()
{
    position.y-= FallSpeed;
    if (position.y <= -LimitY)
    {
        position.y = startPosition.y;
    }
}
void Paper::ChangeDirection()
{
    if (isTurnLeft)
    {
        angle -= TurnSpeed;

    }
    else
    {
        angle += TurnSpeed;
    }
    if (angle >= MaxAngle ||angle<=-MaxAngle)
    {
        angle = 0.0f;
    }
}

void Paper::Draw(const int colorHandle[])
{
    int color=0;
    switch (kinds)
    {
    case KindsColor::Red:
        color = colorHandle[(int)KindsColor::Red];
        break;
    case KindsColor::Green:
        color = colorHandle[(int)KindsColor::Green];
        break;
    case KindsColor::Blue:
        color = colorHandle[(int)KindsColor::Blue];
        break;
    case KindsColor::Yellow:
        color = colorHandle[(int)KindsColor::Yellow];
        break;
    }
    
    //DrawBox(position.x, position.y, position.x + correctionX, position.y + correctionY, color, TRUE);
    DrawBillboard3D(position, centreX, centreY, 0.5f, angle * DX_PI_F / 180.0f, color, TRUE);
}
