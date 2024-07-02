#pragma once

class Map;
class Player;
enum class GameStatus;

class Collision
{
public:
	Collision();
	~Collision();
	/// <summary>
	/// �v���C���[�ƃu���b�N�̓����蔻��w��
	/// </summary>
	/// <param name="map"></param>
	/// <param name="player"></param>
	/// <param name="moveVector"></param>
	/// <returns></returns>
	VECTOR HitBlockPlayer(Map& map, Player& player, VECTOR& moveVector, bool& isHitGool);
		/// <summary>
	/// �v���C���[�ƃu���b�N�̓����蔻��
	/// </summary>
	/// <param name="player"></param>
	/// <param name="model"></param>
	/// <param name="startPosition"></param>
	/// <param name="endPosition"></param>
	/// <param name="isGool"></param>
	void OnCollision(Player& player, int model,VECTOR& moveVector, bool isGool, bool& isFall, bool& isHitGool);
	/// <summary>
	/// ��Ƃ̓����蔻��
	/// </summary>
	/// <param name="player"></param>
	/// <param name="map"></param>
	int HitHand(Player& player, Map& map);
	/// <summary>
	/// ������u���b�N�𓮂����Ƃ�����}�X�ɂ𒲂ד�����
	/// </summary>
	/// <param name="player"></param>
	/// <param name="map"></param>
	/// <param name="moveVector"></param>
	void HitDepthBlock(Player& player, Map& map, VECTOR moveVector,const int blockNumber );
private:
	static constexpr float	HitSlideLength = 0.1f;	// ��x�̕ǉ����o�������ŃX���C�h�����鋗��
	static constexpr float  CorrectionY = 1.5f;		//�����蔻�����ɂ��炷
	static constexpr float  CorrectionX = 0.0f;  //�����蔻������E�ɂ��炷
	static constexpr float  CorrectionZ = 0.0f;  //�����蔻������A��O�ɂ��炷
	static constexpr float	CheckDepthRange = 5.8f;//���񂾕��������E�̏ꍇ���̂����邩�m�F���鉜�s
	static constexpr float	DirectionLine = 3.0f;	//�L�����N�^�[����ǂꂾ���̋��������߂邩
	static constexpr float	radius = 1.5f;			//���a
	static constexpr int	MaxTry = 1;				//�ő傸�炵��

	//��������yui�A�����W
	static constexpr int MaxHitColl = 2048;	// ��������R���W�����|���S���̍ő吔
	static constexpr float	DefaultSize = 10.0f;	// ���͂̃|���S�����o�Ɏg�p���鋅�̏����T�C�Y
	static constexpr float	HitWidth = 3.0f;	// �����蔻��J�v�Z���̔��a
	static constexpr float	HitHeight = 4.0f;	// �����蔻��J�v�Z���̍���
	static constexpr int	HitTryNum = 16;		// �ǉ����o�������̍ő厎�s��

	VECTOR CheckHitWithFloor(Player& player, const VECTOR& checkPosition);
	VECTOR CheckHitWithWall(Player& player, const VECTOR& checkPosition);
	void AnalyzeWallAndFloor(MV1_COLL_RESULT_POLY_DIM hitDim, const VECTOR& checkPosition);

	//MV1_COLL_RESULT_POLY* wall[MaxHitColl];	// �ǃ|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��
	//MV1_COLL_RESULT_POLY* floor[MaxHitColl];	// ���|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��
	//int							wallNum;			// �ǃ|���S���Ɣ��f���ꂽ�|���S���̐�
	//int							floorNum;			// ���|���S���Ɣ��f���ꂽ�|���S���̐�

};

