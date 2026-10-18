//
// Created by sunvy on 10/08/2026.
//

#include "ScoreComponent.h"


bool ScoreComponent::hasWinner(int& winner) const
{
    if (p1 >= 10)
        winner = 1;
    if (p2 >= 10)
        winner = 2;

    return p1 >= 10 || p2 >= 10;
}

void ScoreComponent::DisplayWinner(int winner) const
{
    LOG("Engine", info, "Player {} WIN", winner)
}

void ScoreComponent::Reset()
{
    p1 = 0;
    p2 = 0;
}
