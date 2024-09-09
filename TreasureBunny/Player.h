#pragma once

class Map;
enum class GameStatus;
class SoundManager;
class Collision;
/// <summary>
/// �v���C���[
/// </summary>
class Player
{
public:

	/// <summary>
	/// ���
	/// </summary>
	enum class Status
	{
		STAND,//�ҋ@
		WALK,//����
		JAMP,//�W�����v
		GRASP,//��������
		FALL,//����
	};
	enum class AnimeKinds
	{
		STAND=3,//�ҋ@
		WALK=14,//����
		JAMP=7,//�W�����v
		GRASP=18,//��������
		FALL=8,//����
	};
	//enum class GraspDirection
	//{
	//	CLOSER,//��O
	//	LEFT,
	//	RIGHT,
	//	FARTHER//��
	//};
	Player();
	~Player();

	/// <summary>
	/// ���f�����[�h�֐�
	/// </summary>
	void LoadModel();
	/// <summary>
	/// ���f���ǂݍ��ݔj���֐�
	/// </summary>
	void UnLoadModel();
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();
	/// <summary>
	/// �A�b�v�f�[�g�֐�
	/// </summary>
	void UpDate(Map &map, Collision &collision, SoundManager& soundManager, bool& isHitGool);
	/// <summary>
	/// �^�C�g���p
	/// </summary>
	/// <param name="map"></param>
	/// <param name="collision"></param>
	void TitleMove(Map& map, Collision collision, bool& isHitGool);
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	/// <summary>
	///�u���b�N���ړ������Ă��邩�ƕ������Z�b�g
	/// </summary>
	/// <param name="isMove"></param>
	/// <param name="moveDirection"></param>
	void SetBlockMove(bool isMove,int moveDirection);
	/// <summary>
	/// �������߂Ȃ�������
	/// </summary>
	void SetNoHit();
	/// <summary>
	/// ���ɓ������Ă���Ƃ�
	/// </summary>
	/// <param name="verocity"></param>
	void OnHitFloor();
	/// <summary>
	/// ���Ɉ�x��������Ȃ������Ƃ�
	/// </summary>
	void NoHitFloor();
	/// <summary>
	/// �V��ɓ������Ă���Ƃ�
	/// </summary>
	void OnHitCeiling();
	/// <summary>
	/// �|�W�V�����擾
	/// </summary>
	/// <returns></returns>
	VECTOR GetPosition() const { return position; }
	/// <summary>
	/// ���݂̏�Ԏ擾
	/// </summary>
	/// <returns></returns>
	Status GetStatus() const { return status; }
	/// <summary>
	/// ���݂̃W�����v�͎擾
	/// </summary>
	/// <returns></returns>
	float GetJampPawer()const { return jampPawer; }
	/// <summary>
	/// ���ݏ�ԂɂȂ��������擾
	/// </summary>
	/// <returns></returns>
	int GetGraspDrection()const;
	/// <summary>
	/// �u���b�N���ړ������Ȃ��Ă͂����Ȃ������擾
	/// </summary>
	/// <returns></returns>
	int GetGraspMoveDirection()const { return graspMoveDirection; };
	/// <summary>
	/// ����ňړ������Ă���Ƃ�
	/// </summary>
	/// <returns></returns>
	bool GetGraspMove()const { return status==Status::GRASP&&isBlockMove; }
	/// <summary>
	/// ����ł���Ƃ�
	/// </summary>
	/// <returns></returns>
	bool GetGrasp()const { return status == Status::GRASP; }
	/// <summary>
	/// �ړ��X�s�[�h�擾
	/// </summary>
	/// <returns></returns>
	float GetMoveSpeed()const { return MoveSpeed; }
	/// <summary>
	/// ���ݓ����Ă��邩�擾
	/// </summary>
	/// <returns></returns>
	bool GetIsMove()const { return isMove; }
	/// <summary>
	/// ��̃x�N�g�����قړ�����
	/// </summary>
	/// <param name="vector1"></param>
	/// <param name="vector2"></param>
	/// <returns></returns>
	bool IsNearAngle(const VECTOR& vector1, const VECTOR& vector2);
	/// <summary>
	/// nowVector��aimVector��degreeVerocity���x�ŉ�]
	/// </summary>
	/// <param name="nowVector"></param>
	/// <param name="aimVector"></param>
	/// <param name="degreeVerocity"></param>
	/// <returns></returns>
	VECTOR RotateForAimVecYAxis(const VECTOR& nowVector, const VECTOR& aimVector, float degreeVerocity);
	/// <summary>
	/// ���v�������̎���1.0 �����v�������̎��� -1.0��Ԃ�
	/// </summary>
	/// <param name="nowVector"></param>
	/// <param name="dirVector"></param>
	/// <returns></returns>
	float CalcRotationDirectionYAxis(const VECTOR& nowVector, const VECTOR& dirVector);

	//�R���W�����p
	
	/// <summary>
	/// �n�ʂɐڒn���Ă���Ƃ�
	/// </summary>
	void OnFall();
	float GetJumpPower() { return jampPawer; }
private:
	static constexpr float MoveSpeed = 0.1f;	//�ړ����x
	static constexpr float TurnSpeed = 15.0f;	//�U��������x
	static constexpr float JampSpeed = 0.30f;	//�W�����v�̏���
	static constexpr float Gravity = -0.01f;	//�d��
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
	static constexpr float BackRightDegrees = -135.0f;			//�E����]
	static constexpr float CorrectionBackRightDegrees = -225.0f;//�E����]��angle�p�C��
	static constexpr float RightDegrees = 90.0f;				//�E����]
	static constexpr float CorrectionRightDegrees = 270.0f;		//�E��]��angle�p�C��
	static constexpr float RightFrontDegrees = -45.0f;			//�E��O��]
	static constexpr float CorrectionRightFrontDegrees = 315.0f;//�E��O��]��angle�p�C��
	static constexpr int Scale=-1;
	static constexpr float FallUpPower = 0.05f;
	static constexpr float AnimeAdvanceTime = 0.5f;//���Ԃ��ǂꂾ���i�߂邩
	

	/// <summary>
	/// �L�[���͂ɂ���Ĉړ��E��]�p�����[�^�[���Z�b�g����
	/// </summary>
	/// <returns></returns>
	Status SetMoveParameter(VECTOR& moveVector, SoundManager& soundManager);
	/// <summary>
	/// ����
	/// </summary>
	void Move(Map& map, Collision collision, VECTOR moveVector,bool& isHitGool);
	/// <summary>
	/// �����]��
	/// </summary>
	/// <param name="moveVector"></param>
	void ChangeDirection();
	/// <summary>
	/// ���ݏ��
	/// </summary>
	void ModeGrasp();
	/// <summary>
	/// �A�j���[�V�����ύX
	/// </summary>
	Status ChangeAnimation();

	VECTOR position;
	VECTOR direction;
	VECTOR nextDirection;
	float angle;//���f���̌����Ă���p�x
	float targetAngle;
	static int baseModelHandle;
	 int modelHandle;
	static bool isLoadModel;
	Status status;			//�����p���
	Status animeStatus;		//�A�j���[�V�����p�X�e�[�^�X
	Status previousAnimeStatus;//�O�̃A�j���[�V����
	float jampPawer;		//Y�������̑��x
	bool isBlockMove;		//�u���b�N���ړ�����
	int graspMoveDirection;	//�u���b�N���ړ������Ȃ��Ă͂����Ȃ�����(0�F�ړ������ĂȂ��@2�F���@3�F��O)
	bool titleMoveDirection;//�^�C�g���œ�������
	bool isMove;
	bool isRotaNow;//��]����
	float animationTime;
	float animationMaxTime;
	int animationKinds;
};