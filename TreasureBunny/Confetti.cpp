#include"DxLib.h"
#include "Confetti.h"
#include"Paper.h"

std::vector<Paper> Confetti::paper;
Confetti::Confetti()
{
    VECTOR pos = VGet(0, 0, 0);
    for (int i = 0; i < Size; i++)
    {
        pos = VGet((float)GetRand(CreatePositionX)-10, (float)GetRand(CreatePositionY), (float)GetRand(CreatePositionZ));
        paper.push_back(pos);
    }
}
Confetti::~Confetti()
{
    paper.clear();
}
void Confetti::UpDate()
{
    for (auto& papers : paper)
    {
        papers.UpDate();
    }
}
void Confetti::Draw(const int colorHandle[])
{
    for (auto& papers : paper)
    {
        papers.Draw(colorHandle);
    }
}