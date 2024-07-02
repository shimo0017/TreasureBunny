#include<math.h>
#include"DxLib.h"
#include"Camera.h"
#include"Player.h"

Camera::Camera()
	:position(VGet(10.0f, 8.0f, -20.0f))
	,target(VGet(10.0f, 9.0f, 0.0f))
	, modePlayer(true)
	, hitShift(false)
	, sumCorrectionY(0.0f)
{
	//èàóùÇ»Çµ
}
Camera::~Camera()
{
	//èàóùÇ»Çµ
}
void Camera::Initialize()
{
	modePlayer = true;
	sumCorrectionY = 0.0f;
	hitShift = true;
}
void Camera::UpDate(const Player&player)
{
	SelectMode();

	Move();
	CorrectionPosition(player.GetPosition());
	CorrectionTarget(player.GetPosition());

	SetCameraPositionAndTarget_UpVecY(position,target);
}
void Camera::TitleUpdate(const Player& player)
{
	Move();
	CorrectionPosition(player.GetPosition());
	CorrectionTarget(player.GetPosition());

	SetCameraPositionAndTarget_UpVecY(position, target);

}
void Camera::CorrectionPosition(const VECTOR player)
{
	VECTOR pos = VGet(0.0f, 0.0f, DistancePlayer);
	if (modePlayer == false)
	{
		float plusZ;
		if (player.z < 0.0f)
		{
			plusZ = player.z - StartZ- DistancePlayer*2;
		}
		else
		{
			plusZ = player.z + StartZ;
		}
		pos = VAdd(pos, VGet(player.x+ StartX, player.y+ StartY+sumCorrectionY, plusZ));
	}
	else
	{
		pos = VAdd(pos, VGet(0.0f, TargetHeightPlayer, 0.0f));
	}
	position=VSub(player, pos);
	if (player.z < 0.0f&& modePlayer == false)
	{
		position.z *= -1;
	}
}
void Camera::CorrectionTarget(const VECTOR player)
{
	VECTOR pos;

	if (modePlayer == false)
	{
		float plusZ= player.z;
		if (player.z < 0.0f)
		{
			plusZ *= -1;
		}
		pos = VAdd(position, VGet(0.0f, 0.0f, plusZ));
	}
	else
	{
		pos = player;
	}
	target = pos;
}
void Camera::SelectMode()
{
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_2)
	{

		if (hitShift == false)
		{
			if (modePlayer == true)
			{
				modePlayer = false;
			}
			else
			{
				modePlayer = true;
				sumCorrectionY = 0.0f;
			}
		}
		hitShift = true;

	}
	else
	{
		hitShift = false;
	}
}
void Camera::Move()
{
	if (modePlayer==false)
	{
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP && sumCorrectionY >= -30.0f)
		{
			sumCorrectionY -= MoveY;
		}
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN && sumCorrectionY <= 0.0f)
		{
			sumCorrectionY += MoveY;
		}
	}
}
