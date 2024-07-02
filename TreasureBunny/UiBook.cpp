#include"DxLib.h"
#include"UiBook.h"


UiBook::UiBook()
{
	//処理なし
}
UiBook::~UiBook()
{
	//処理なし
}
void UiBook::Draw(const int bookHandle)
{
	//本の後ろを暗くする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, MaxTransparency);
	DrawBox(BoxX, BoxY, BoxWidth, BoxWidth, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, MinTransparency);
	//本を描画
	DrawExtendGraph(BookX, BookY, BookWidth, BookHeight, bookHandle, TRUE);

}