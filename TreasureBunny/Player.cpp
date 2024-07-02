#include<math.h>
#include"DxLib.h"
#include"Player.h"
#include"Map.h"
#include"Collision.h"
#include"SoundManager.h"

int Player::baseModelHandle =0;
bool Player::isLoadModel=false;


Player::Player()
	:position(VGet(0.0f,0.0f,0.0f))
	,direction(VGet(0.0f,0.0f, -1.0f))
	,nextDirection(direction)
	,angle(0.0f)
	, targetAngle(0.0f)
	,status(Status::STAND)
	,jampPawer(0.0f)
	,isBlockMove(false)
	, graspMoveDirection(0)
	, titleMoveDirection(false)
	, isMove(false)
	, isRotaNow(false)
{
	if (isLoadModel == false)
	{
		LoadModel();
		isLoadModel = true;
	}
	modelHandle = MV1DuplicateModel(baseModelHandle);
	MV1SetScale(modelHandle, VGet(0.01f, 0.01f, 0.01f));
	Initialize();
}

Player::~Player()
{
	UnLoadModel();
}

void Player::LoadModel()
{
	baseModelHandle =MV1LoadModel("Model/Character.mv1");
	status = Status::STAND;
}
void Player::UnLoadModel()
{
	if (modelHandle >= 0)
	{
		MV1DeleteModel(modelHandle);
	}
}
void Player::Initialize()
{
	position = VGet(StartPosX, StartPosY, StartPosZ);
	direction = VGet(0, 0, -1.0f);
	nextDirection = direction;///
	MV1SetPosition(modelHandle, position);
	angle = 0.0f;
	targetAngle = 0.0f;
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle * DX_PI_F / HalfDegrees, 0.0f));
	isBlockMove = false;
	graspMoveDirection = 0;
	isRotaNow = false;
}
void Player::UpDate(Map &map,Collision &collision, SoundManager& soundManager, bool& isHitGool)
{
	VECTOR moveVector = VGet(0.0f, 0.0f, 0.0f);			//このフレーム移動量
	//つかみモード切り替え
	ModeGrasp();
	//ブロックが目の前にあるかチェックしてなかった場合つかみモードじゃなくする
	if (status == Status::GRASP)
	{
		int blockNumber=collision.HitHand(*this, map);
		if (blockNumber == -1)
		{
			SetNoHit();
		}
		else
		{
			soundManager.SoundPlay(SoundKinds::Grasp, SoundMethod::BackGround);
		}
	}
	status=SetMoveParameter(moveVector, soundManager);
	ChangeDirection();
	Move(map,collision,moveVector, isHitGool);

}
Player::Status Player::SetMoveParameter(VECTOR & moveVector, SoundManager& soundManager )
{
	static VECTOR moveXVector = VGet(MoveSpeed, 0.0f, 0.0f);	//1フレームのX移動量
	static VECTOR moveZVector = VGet(0.0f, 0.0f, MoveSpeed);	//1フレームのZ移動量
	bool xLimit = false;
	bool zLimit = false;
	Status nextStatus = status;
	isMove = false;
	//入力処理
	if (status != Status::GRASP)
	{
		//左
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT)
		{
			moveVector = VAdd(moveVector, VScale(moveXVector, -1.0f));

			if (position.x <= LimitLeft)
			{
				xLimit = true;
			}
			isMove = true;
		}
		//右
		else if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT)
		{
			moveVector = VAdd(moveVector, moveXVector);

			if (position.x >= LimitRight)
			{
				xLimit = true;
			}
			isMove = true;
		}
	}
	//手前
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN && (graspMoveDirection == 0 || graspMoveDirection == 2))
	{
		moveVector = VAdd(moveVector, VScale(moveZVector, -1.0f));

		if (position.z <= LimitCloser)
		{
			zLimit = true;
		}
		isMove = true;
	}
	//奥
	else if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP && (graspMoveDirection == 0 || graspMoveDirection == 3))
	{
		moveVector = VAdd(moveVector, moveZVector);

		if (position.z >= LimitFarther)
		{
			zLimit = true;
		}
		isMove = true;
	}
	//ジャンプ
	//つかみモードの時はジャンプさせない
	//Aボタンでジャンプ
	if (status != Status::JAMP && status != Status::GRASP&& GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1)
	{
		jampPawer = JampSpeed;
		nextStatus = Status::JAMP;
		soundManager.SoundPlay(SoundKinds::Jamp, SoundMethod::BackGround);
	}
	//現在フレームでジャンプ状態なら重力をかける
	if (status == Status::JAMP||status==Status::FALL)
	{
		if (jampPawer<=1.0f)
		{
			jampPawer += Gravity;
		}
	}

	// 移動キーを押している時は歩き状態にさせる
	if (isMove)
	{
		if (status == Status::STAND&&status!=Status::JAMP)
		{
			nextStatus = Status::WALK;
		}
		//つかんでいるときは方向転換させない
		if (status != Status::GRASP)
		{
			VECTOR norm = VNorm(moveVector);
			if (IsNearAngle(norm, direction)==true)
			{
				direction = norm;
			}
			else
			{
				nextDirection = norm;
				isRotaNow = true;
			}
		}
		// プレイヤーが向くべき方向ベクトルをプレイヤーのスピード倍したものを移動ベクトルとする
		moveVector = VScale(VNorm(moveVector), MoveSpeed);
		if (xLimit==true)
		{
			moveVector.x = 0.0f;
		}
		if (zLimit == true)
		{
			moveVector.z = 0.0f;
		}
	}
	//移動キーを押していなければ立ち止まらせる
	else
	{
		if (status == Status::WALK)
		{
			nextStatus = Status::STAND;
		}
	}
	//// 移動ベクトルのＹ成分をＹ軸方向の速度にする
	moveVector.y = jampPawer;

	return nextStatus;
}
void Player::TitleMove(Map &map,Collision collision, bool& isHitGool)
{
	VECTOR moveVector=VGet(0.0f,0.0f,0.0f);
	if (titleMoveDirection)
	{
		moveVector = VGet(MoveSpeed, 0.0f, 0.0f);
		VECTOR norm = VNorm(moveVector);
		if (IsNearAngle(norm, direction) == true)
		{
			direction = norm;
		}
		else
		{
			nextDirection = norm;
			isRotaNow = true;
		}
		if (position.x > LimitRight)
		{
			titleMoveDirection = false;
		}
	}
	else
	{
		moveVector = VGet(-MoveSpeed, 0.0f, 0.0f);
		VECTOR norm = VNorm(moveVector);
		if (IsNearAngle(norm, direction) == true)
		{
			direction = norm;
		}
		else
		{
			nextDirection = norm;
			isRotaNow = true;
		}
		if (position.x < LimitLeft)
		{
			titleMoveDirection = true;
		}
	}
	ChangeDirection();
	Move(map,collision,moveVector, isHitGool);

}
void Player::Move(Map& map,Collision collision,VECTOR moveVector,bool &isHitGool)
{
	position = collision.HitBlockPlayer(map,*this,moveVector, isHitGool);
	if (status == Status::GRASP)
	{
		bool moveMode = true;
		int blockNumber=collision.HitHand(*this,map);
		//目の前にブロックがある時に移動させる。
		//また、プレイヤーが左右を向いてる時の処理
		if (blockNumber >= 0)
		{
			collision.HitDepthBlock(*this, map, moveVector, blockNumber);
		}
	}
	//printfDx("%f\n", position.y);
	//if (position.y <= 2.0f)
	//{
	//	position.y = 2.0f;
	//	status = Status::STAND;
	//}

	MV1SetPosition(modelHandle, position);
}
void Player::ChangeDirection()
{
	// 回転が目標角度に十分近ければ回転モード終了
	if (isRotaNow)
	{
		if (IsNearAngle(nextDirection, direction))
		{
			direction = nextDirection;
			isRotaNow = false;
		}
		else
		{
			// 回転させる
			VECTOR interPolateDir;
			interPolateDir = RotateForAimVecYAxis(direction, nextDirection, TurnSpeed);

			// 回転が目標角度を超えていないか
			VECTOR cross1, cross2;
			cross1 = VCross(direction, nextDirection);
			cross2 = VCross(interPolateDir, nextDirection);

			//目標角度を超えたら終了
			if (cross1.y * cross2.y < 0.0f)
			{
				interPolateDir = nextDirection;
				isRotaNow = false;
			}
			// 目標ベクトルに15度だけ近づけた角度
			direction = interPolateDir;
		}

	}
	// 向きに合わせてモデルを回転.(mixamoのモデルはX軸反対向きに出るのでまずベクトルを180度回転させる
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	VECTOR negativeVec = VTransform(direction, rotYMat);

	// モデルに回転をセットする
	float tan=(float)atan2(negativeVec.x, negativeVec.z);
	//float tan2=(float)atan(direction.z / direction.x);
	/*tan = DX_PI * tan / 180.0f;*/
	MV1SetRotationXYZ(modelHandle, VGet(0.0f,tan,0.0f));//XYZでも行けるようにする
}
void Player::ModeGrasp()
{
	static int directionMin = 1;
	static int directionMax = 3;
	int direction = GetGraspDrection();
	//現在カメラから見て完全に左、奥、右のどれかを向いているとき
	if (direction>=directionMin&&direction<=directionMax)
	{
		//Xボタンを押されているとき
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_3)
		{
			if (status != Status::JAMP && status != Status::FALL)
			{
				status = Status::GRASP;
			}
		}
		//ブロックを動かしていなくてつかみモードならスタンド状態にする
		else if(!isBlockMove&&status == Status::GRASP)
		{
			status = Status::STAND;
		}
	}
}
void Player::Draw()
{
	MV1DrawModel(modelHandle);
}
void Player::SetBlockMove(bool isMove,int moveDirection)
{
	isBlockMove = isMove;
	graspMoveDirection = moveDirection;
}
void Player::OnHitCeiling()
{
	jampPawer = -jampPawer;
}
void Player::OnHitFloor()
{
	jampPawer = 0.0f;
	if (status == Status::JAMP||status==Status::FALL)
	{
		status = Status::STAND;
	}
}
void Player::NoHitFloor()
{
	if (status != Status::JAMP&&status!=Status::GRASP)
	{
		status = Status::FALL;
	}
}
int Player::GetGraspDrection()const
{
	float yRotation = MV1GetRotationXYZ(modelHandle).y* HalfDegrees / DX_PI_F;
	int direction = 0;
	//左
	if (yRotation > RightDegrees - 1 && yRotation < RightDegrees + 1)
	{
		direction = 1;
	}
	//右
	else if (yRotation > -RightDegrees - 1 && yRotation < -RightDegrees + 1)
	{
		direction = 2;
	}
	//奥
	else if (yRotation > -HalfDegrees - 1 && yRotation < -HalfDegrees + 1)
	{
		direction = 3;
	}
	return direction;
}
void Player::SetNoHit()
{
	if (status == Status::GRASP)
	{
		status=Status::STAND;
	}
}
void Player::OnFall()
{
	if (status != Status::JAMP)
	{
		status = Status::JAMP;
		// ちょっとだけジャンプする
		jampPawer = FallUpPower;

	}
}
bool Player::IsNearAngle(const VECTOR& vector1, const VECTOR& vector2)
{
	float dot = VDot(vector1, vector2);
	if (dot > 0.99f)
	{
		return true;
	}
	return false;
}
VECTOR Player::RotateForAimVecYAxis(const VECTOR& nowVector, const VECTOR& aimVector, float degreeVerocity)
{
	// 角速度（度数）をラジアン角に変換、右回りか左回りかを調べる
	float rotRadian = (DX_PI_F * degreeVerocity / 180.0f);
	rotRadian *= CalcRotationDirectionYAxis(nowVector, aimVector);

	// Y軸回転行列を作成する
	MATRIX yrotMat = MGetRotY(rotRadian);
	//MATRIX yrotMat = MGetRotAxis(VGet(0.0f, 1.0f, 0.0f), rotRadian);

	// Y軸回転する
	VECTOR rotVec;
	rotVec = VTransform(nowVector, yrotMat);

	return rotVec;
}
float Player::CalcRotationDirectionYAxis(const VECTOR& nowVector, const VECTOR& dirVector)
{
	VECTOR axis;
	axis = VCross(nowVector, dirVector);
	if (axis.y < 0.0f)
	{
		return -1.0f;
	}
	return 1.0f;
}
