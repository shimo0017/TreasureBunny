#include"DxLib.h"
#include"SoundManager.h"

int SoundManager::SoundHandle[] = {0};
bool SoundManager::isFirstConstructor=false;


SoundManager::SoundManager()
{
	if (isFirstConstructor == false)
	{
		LoadSound("Sound/280_BPM125.mp3");
		LoadSound("Sound/372_BPM146.mp3");
		LoadSound("Sound/005_BPM150.mp3");
		LoadSound("Sound/カーソル移動12.mp3");
		LoadSound("Sound/決定ボタンを押す38.mp3");
		LoadSound("Sound/Motion-Pop42-1.mp3");
		LoadSound("Sound/se_jump_003.wav");
		isFirstConstructor = true;
	}
}
SoundManager::~SoundManager()
{

}
void SoundManager::LoadSound(const char* fileName)
{
	static int Number = 0;
	SoundHandle[Number] = LoadSoundMem(fileName);
	Number++;
}
void SoundManager::SoundPlay(SoundKinds playbackNumber, SoundMethod playbackMethod)
{
	int handle = SoundHandle[static_cast<int>(playbackNumber)];
	//再生されていないなら流す
	if (CheckSoundMem(handle) == 0)
	{
		switch (playbackMethod)
		{
		case SoundMethod::Loop:
			PlaySoundMem(handle, DX_PLAYTYPE_LOOP);
			break;

		case SoundMethod::BackGround:
			PlaySoundMem(handle, DX_PLAYTYPE_BACK);
			break;

		case SoundMethod::Normal:
			PlaySoundMem(handle, DX_PLAYTYPE_NORMAL);
			break;

		default:
			break;
		}
	}
}
void SoundManager::SoundStop(SoundKinds playbackNumber)
{
	StopSoundMem(SoundHandle[static_cast<int>(playbackNumber)]);
}
