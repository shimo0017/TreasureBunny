#pragma once

class Fps
{
public:
	/// <summary>
	/// �J�E���^�[�̏�����
	/// </summary>
	Fps();

	bool Update();

	void Draw();

	void Wait();
private:
	static constexpr int N = 60;//���ς����T���v����
	static constexpr int SetFps = 60;	//�ݒ肵��Fps

	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps

};