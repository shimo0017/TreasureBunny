#pragma once
/// <summary>
/// フェードエフェクトクラス
/// </summary>
class Fade
{
public:
	Fade();
	~Fade();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(bool isOut);
	/// <summary>
	/// フェードイン・フェードアウト
	/// </summary>
	bool FadeInOut(bool isOut);
	void Draw(const int blackColor);
private:
	static constexpr int BoxX = 0;//ボックスの左
	static constexpr int BoxY = 0;//ボックスの上
	static constexpr int BoxWidth = 1280;//ボックスの右
	static constexpr int BoxHeight = 1024;//ボックスの下
	static constexpr int FadeSpeed = 3;
	static constexpr int MinTransparency = 0;
	static constexpr int MaxTransparency = 255;
	int transparency;//透明度
};