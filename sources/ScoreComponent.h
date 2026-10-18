//
// Created by sunvy on 10/08/2026.
//

#pragma once

#include "GameFramework/Components/Component.h"

class ScoreComponent : public Sunset::Component
{
public:
    bool hasWinner(int& winner) const;
    void DisplayWinner(int winner) const;
    void Reset();
    int p1 = 0, p2 = 0;
};
