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

};

