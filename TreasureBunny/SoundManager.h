#pragma once

	//�T�E���h�̎��
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
	//�T�E���h�̍Đ����@
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
	/// �I�������T�E���h�𗬂�
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