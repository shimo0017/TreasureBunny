#pragma once
/// <summary>
/// �{�Ɣw�i���Â�����N���X
/// </summary>
class UiBook
{
public:
	UiBook();
	~UiBook();
	void Draw(const int bookHandle);
private:
	static constexpr int BoxX = 0;//�{�b�N�X�̍�
	static constexpr int BoxY = 0;//�{�b�N�X�̏�
	static constexpr int BoxWidth = 1280;//�{�b�N�X�̉E
	static constexpr int BoxHeight = 1024;//�{�b�N�X�̉�

	static constexpr int BookX = 150;
	static constexpr int BookY = 100;
	static constexpr int BookWidth = BookX+1000;
	static constexpr int BookHeight = BookY+800;

	static constexpr int MinTransparency = 0;
	static constexpr int MaxTransparency = 100;
};