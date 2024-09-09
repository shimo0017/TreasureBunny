#pragma once
class Block
{
public:
	Block(int model, VECTOR pos,int kindsNumber, COLOR_F color,int parentnumber,int startstepNumber, bool gool);
	~Block();
	void Draw();
	void UpDate();
	/// <summary>
	/// ��Ԏ�O�̃u���b�N�𓮂���
	/// </summary>
	/// <param name="moveVector"></param>
	/// <param name="isCoolDown"></param>
	/// <param name="StartPosition"></param>
	/// <param name="moveDirection"></param>
	/// <returns></returns>
	bool SetMoveCloser(VECTOR moveVector,bool& isCoolDown, float StartPosition,int &moveDirection);
	/// <summary>
	/// ���̃u���b�N�����O�̃u���b�N�ɒǏ]������
	/// </summary>
	/// <param name="CloserPosition"></param>
	void SetMoveFarther(VECTOR closerPosition,float correctionZ);
	/// <summary>
	/// �u���b�N�̓�������
	/// </summary>
	/// <param name="Transparent"></param>
	void SetTransparent(bool Transparent);
	/// <summary>
	/// �u���b�N�̐F�ʈȊO�̓�������
	/// </summary>
	void SetMeshTransparent();
	/// <summary>
	/// �u���b�N���ŏ��̏�Ԃɖ߂�
	/// </summary>
	void ResetBlock();
	int GetModel() { return model; }
	int GetKinds() { return kinds; }
	bool GetGool() { return isGool;}
	int GetStep() { return step; }
	/// <summary>
	/// ���̃u���b�N�̏ꍇ��Ԏ�O�̔ԍ�������Ă��肻����擾
	/// </summary>
	/// <returns></returns>
	int GetParentNumber() { return parentNumber; }
	bool GetIsTransparent() { return isTransparent; }
	VECTOR GetPosition() { return position; }
	VECTOR GetCreatePosition() { return createPosition; }
private:
	static constexpr float	CorrectionZ = 4.0f;//�u���b�N�̔z�u�Ԋu
	static constexpr int MaxStep = 3;
	static constexpr int MinStep = 0;
	static constexpr int	BaseParentNumber = -1;//��Ԏ�O�̃u���b�N��\��
	static constexpr int	DownStepNoBaseParent = -1;//�쐬����O�̃u���b�N�ł͂Ȃ��Ƃ��X�e�b�v�������l
	static constexpr float	setOpacity = 1.0f;//�����x0
	static constexpr float	SetCleanness = 0.0f;//�����x100
	static constexpr int MeshNumber=4;
	int model;//�u���b�N�̃��f��
	VECTOR position;//�ʒu
	VECTOR createPosition;//������ʒu
	int kinds;//���
	bool isGool;//�S�[�����ǂ���
	int step;//�u���b�N�̌��݈����o����Ă���i�K�i�ő�3)
	int nextStep;//���̒i�K
	bool completeStep;//�u���b�N�����S�Ɉړ���������
	int	parentNumber;//���̃u���b�N�̈�Ԏ�O�̃u���b�N�̔ԍ�(-1����Ԏ�O)
	int startStep;//���ꂽ���̒i�K
	bool isTransparent;//�������ǂ���
	MV1_REF_POLYGONLIST polygonList;
};
