#include"DxLib.h"
#include"UiBook.h"


UiBook::UiBook()
{
	//�����Ȃ�
}
UiBook::~UiBook()
{
	//�����Ȃ�
}
void UiBook::Draw(const int bookHandle)
{
	//�{�̌����Â�����
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, MaxTransparency);
	DrawBox(BoxX, BoxY, BoxWidth, BoxWidth, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, MinTransparency);
	//�{��`��
	DrawExtendGraph(BookX, BookY, BookWidth, BookHeight, bookHandle, TRUE);

}