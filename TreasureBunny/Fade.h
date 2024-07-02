#pragma once
/// <summary>
/// �t�F�[�h�G�t�F�N�g�N���X
/// </summary>
class Fade
{
public:
	Fade();
	~Fade();
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(bool isOut);
	/// <summary>
	/// �t�F�[�h�C���E�t�F�[�h�A�E�g
	/// </summary>
	bool FadeInOut(bool isOut);
	void Draw(const int blackColor);
private:
	static constexpr int BoxX = 0;//�{�b�N�X�̍�
	static constexpr int BoxY = 0;//�{�b�N�X�̏�
	static constexpr int BoxWidth = 1280;//�{�b�N�X�̉E
	static constexpr int BoxHeight = 1024;//�{�b�N�X�̉�
	static constexpr int FadeSpeed = 3;
	static constexpr int MinTransparency = 0;
	static constexpr int MaxTransparency = 255;
	int transparency;//�����x
};