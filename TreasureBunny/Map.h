#pragma once

#include<vector>

class Block;
class Map
{
public:
	Map();
	~Map();
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();
	/// <summary>
	/// �X�V�i�N�[���^�C���j
	/// </summary>
	void UpDate();
	/// <summary>
	/// block�`��
	/// </summary>
	/// <param name="playerPos"></param>
	void DrawMap(VECTOR playerPos);
	void DrawSky();
	/// <summary>
	/// �X�e�[�W���n�߂��Ƃ��Ƀu���b�N���Z�b�g����
	/// </summary>
	void SetMap();
	/// <summary>
	/// �}�b�v�ԍ����Z�b�g
	/// </summary>
	void SetMapNumber(int number);
	/// <summary>
	/// �u���b�N�𓮂���
	/// </summary>
	/// <param name="moveVector"></param>
	bool BlockMove(VECTOR moveVector,int hitNumber, int& moveDirection,int graspDirection);
	/// <summary>
	/// �w�肵���ꏊ�̎�ޔԍ��擾
	/// </summary>
	/// <param name="i"></param>
	/// <param name="j"></param>
	/// <returns></returns>
	int GetCell(int i, int j) const { return cell[mapNumber][i][j]; }

	/// <summary>
	/// ���}�b�v�ڂ��擾
	/// </summary>
	/// <returns></returns>
	int GetMapNumber() const { return mapNumber; }
	/// <summary>
	/// �u���b�N�̃��f���ԍ��擾
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	int GetBlockModel(int i)const;
	/// <summary>
	/// �S���̃u���b�N���擾
	/// </summary>
	/// <returns></returns>
	int GetBlockNuber()const { return blockNumber; }
	/// <summary>
	/// �S���̒n�ʐ��擾
	/// </summary>
	/// <returns></returns>
	int GetSoilNumber()const { return soilNumber; }
	/// <summary>
	/// �n�ʂ̍����擾
	/// </summary>
	/// <returns></returns>
	float GetSoilPositionY()const { return InitializePositionY; }
	/// <summary>
	/// ���Z�b�g�J�E���g�擾
	/// </summary>
	/// <returns></returns>
	int GetResetCount()const { return resetCount; }
	/// <summary>
	/// �u���b�N�̎�ގ擾
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	int GetBlockKinds(int i)const;
	/// <summary>
	/// �S�[�����ǂ������擾
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	bool GetIsGool(int i)const;
	/// <summary>
	/// �u���b�N�̈����o���Ă���i�K�擾
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	int GetBlockStep(int i)const;
	/// <summary>
	/// �������擾
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	bool GetIsTransparent(int i)const;
private:
	static constexpr int	BlockKinds = 4;//�u���b�N�̎�ސ�
	static constexpr int	AccessoriesKinds = 1;//�����̎��
	static constexpr int	MapX = 8;//block�S�̂�X��
	static constexpr int	MapY = 8;//block�S�̂�Y��
	static constexpr int	SoilX = 10;//�n�ʑS�̂�X��
	static constexpr int	SoilY = 6;//�n�ʑS�̂�Y��
	static constexpr float	CorrectionX = 4.0f;//�u���b�N�E�n�ʂ̔z�u�Ԋu
	static constexpr float	CorrectionY = 3.9f;//�u���b�N�̔z�u�Ԋu
	static constexpr float	CorrectionZ = 4.0f;//�u���b�N�̔z�u�Ԋu
	static constexpr float	InitializePositionY = 0.0f;//�n�ʂ�z�u���鍂��
	static constexpr float	InitializePositionZ = 15.0f;//�u���b�N�z�u���鉜�s
	static constexpr int	NoBaseBlock = 3;//��������u���b�N�����Ԃ��炩
	static constexpr int	SearchBlockX = 1;//�u���b�N�z���X�̏ꍇ1�����炵�ĒT��
	static constexpr int	SearchBlockY = 1;//�u���b�N�z���X�̏ꍇ8�����炵�ĒT��
	static constexpr int	PullPushBlockCoolDown = 60;	//�u���b�N����i�K������������ƃN�[���_�E��
	static constexpr int	BaseParentNumber = -1;//��Ԏ�O�̃u���b�N��\��
	static constexpr int	FirstStepNumber = 0;//��Ԏ�O�̃u���b�N�𐶐�����Ƃ��̒i�K
	static constexpr int	ResetTiming = 150;//���B�ナ�Z�b�g����
	static constexpr int	MaxMap = 5;//�ő�}�b�v��
	static constexpr float	StopTransparent = 15.1f;//����ȏ�̎�����
	static constexpr float	CenterXY = 0.5f;//���S
	static constexpr float	CoinImgSize = 1.0f;//���{
	static constexpr float	CoinImgAngle = 0.0f;//�p�x
	static constexpr float	CoinCorrectionY = 2.0f;//�R�C�����f�����炵��
	static constexpr float	CoinImgCorrectionZ = -2.5f;//�R�C���摜���炵��

	/// <summary>
	/// �u���b�N��T��
	/// </summary>
	/// <param name="count"></param>
	/// <param name="number"></param>
	/// <param name="numberpoint"></param>
	void SearchBlock(int &count,int number[],int numberPoint,int kinds,bool isPlus,bool isX,int startPoint, VECTOR pos);
	/// <summary>
	/// �N�[���_�E���X�V
	/// </summary>
	void EndCoolDown();
	/// <summary>
	/// ���̃u���b�N�̓�������
	/// </summary>
	void SetTransparent();
	/// <summary>
	/// �u���b�N����ԍŏ��̏�Ԃ�
	/// </summary>
	void ResetBlock();
	/// <summary>
	/// �}�b�v���[�h
	/// </summary>
	void LoadMap(const char* fileName);
	//static Block block[MapX*MapY*3+SoilX*SoilY];
	static std::vector<Block> block;
	static COLOR_F	colorBlock[3];//�u���b�N�̑O�ʂ̐F�@0�F�ԁ@1�F�΁@2�F��
	static int cell[MaxMap][MapY][MapX];	//�u���b�N�z�u�z��
	static int soilCell[SoilY][SoilX];	//�n�ʔz�u�z��
	static int baseModel[BlockKinds + AccessoriesKinds];	//���ɂ��郂�f��
	static int SkyModel;			//�X�J�C�h�[�����f��
	static int coinModel;			//�R�C�����f��
	static int coinImg;			//�R�C���C���[�W
	static bool isFirstConstructor;

	int mapNumber;			//���}�b�v�ڂ�
	int blockNumber;		//�u���b�N�̐�
	int soilNumber;			//�n�ʂ̐�
	bool isCoolDown;		//�N�[���_�E������
	int resetCount;			//���Z�b�g�J�E���g
	int coolDown;

};
