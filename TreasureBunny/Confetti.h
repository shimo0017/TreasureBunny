#pragma once

#include<vector>

class Paper;
//†áƒNƒ‰ƒX
class Confetti
{
public:
    Confetti();
    ~Confetti();
    void UpDate();
    void Draw(const int colorHandle[]);

private:
    static constexpr int Size = 500;
    static constexpr int MaxColorKinds = 4;
    static constexpr int CreatePositionX = 50;
    static constexpr int CreatePositionY = 500;
    static constexpr int CreatePositionZ = 20;

    static std::vector<Paper> paper;

};

