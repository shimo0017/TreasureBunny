#pragma once
/// <summary>
/// 本と背景薄暗くするクラス
/// </summary>
class UiBook
{
public:
	UiBook();
	~UiBook();
	void Draw(const int bookHandle);
private:
	static constexpr int BoxX = 0;//ボックスの左
	static constexpr int BoxY = 0;//ボックスの上
	static constexpr int BoxWidth = 1280;//ボックスの右
	static constexpr int BoxHeight = 1024;//ボックスの下

	static constexpr int BookX = 150;
	static constexpr int BookY = 100;
	static constexpr int BookWidth = BookX+1000;
	static constexpr int BookHeight = BookY+800;

	static constexpr int MinTransparency = 0;
	static constexpr int MaxTransparency = 100;
};