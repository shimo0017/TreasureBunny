#pragma once

	//サウンドの種類
	enum class SoundKinds
	{
		Title,
		Game,
		Clear,
		Select,
		PushSelect,
		Grasp,
		Jamp,
	};
	//サウンドの再生方法
	enum class SoundMethod
	{
		Loop,
		BackGround,
		Normal
	};

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	/// <summary>
	/// 選択したサウンドを流す
	/// </summary>
	/// <param name="playbackNumber"></param>
	/// <param name="playbackMethod"></param>
	void SoundPlay(SoundKinds playbackNumber, SoundMethod playbackMethod);
	void SoundStop(SoundKinds playbackNumber);
private:
	static constexpr int MaxKinds = 7;
	void LoadSound(const char* fileName);

	static int SoundHandle[MaxKinds];
	static bool isFirstConstructor;
};