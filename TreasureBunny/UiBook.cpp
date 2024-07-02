#include"DxLib.h"
#include"UiBook.h"


UiBook::UiBook()
{
	//ˆ—‚È‚µ
}
UiBook::~UiBook()
{
	//ˆ—‚È‚µ
}
void UiBook::Draw(const int bookHandle)
{
	//–{‚ÌŒã‚ë‚ğˆÃ‚­‚·‚é
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, MaxTransparency);
	DrawBox(BoxX, BoxY, BoxWidth, BoxWidth, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, MinTransparency);
	//–{‚ğ•`‰æ
	DrawExtendGraph(BookX, BookY, BookWidth, BookHeight, bookHandle, TRUE);

}