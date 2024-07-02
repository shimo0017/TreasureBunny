#include"DxLib.h"
#include"Fade.h"



Fade::Fade()
{
	transparency = 0;
}
Fade::~Fade()
{
	//�����Ȃ�
}
void Fade::Initialize(bool isOut)
{
	if (isOut)
	{
		transparency = MinTransparency;
	}
	else
	{
		transparency = MaxTransparency;
	}
}

bool Fade::FadeInOut(bool isOut)
{
	//�Â�
	if (isOut)
	{
		transparency += FadeSpeed;
		if (transparency >= MaxTransparency)
		{
			transparency = MaxTransparency;
			return true;
		}
	}
	//���邭
	else
	{
		transparency -= FadeSpeed;
		if (transparency <= MinTransparency)
		{
			transparency = MinTransparency;
			return true;
		}
	}
	return false;
}
void Fade::Draw(const int blackColor)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparency);
	//�����{�b�N�X����ʂ����ς��ɕ\��
	DrawBox(BoxX, BoxY, BoxWidth, BoxWidth, blackColor,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}