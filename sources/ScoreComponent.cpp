//
// Created by sunvy on 10/08/2026.
//

#include "ScoreComponent.h"

#include "GameFramework/World/World.h"
#include "GameFramework/World/Entity.h"

ScoreComponent::ScoreComponent()
{
    SRmGUI::SNewAssign(BallScore)
    .AnchorMin({0.475, 0.1})
    .AnchorMax({0.475, 0.1});

    SRmGUI::SNewAssign(Winner)
    .Fill()
    .AnchorMin({0.5f, 0.5})
    .AnchorMax({0.5f, 0.5});
    Winner->SetVisibility(false);
}

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
    Winner->SetText(std::format("Player {} WIN", winner));
    Winner->SetVisibility(true);
}

void ScoreComponent::Reset()
{
    Winner->SetVisibility(false);
    p1 = 0;
    p2 = 0;
}

void ScoreSystem::Update(float deltaTime)
{
    m_World->Each<ScoreComponent>([&](const Sunset::Entity& entity, const ScoreComponent& score)
    {
        score.BallScore->SetText(std::format("{} | {}", score.p1, score.p2));
    });
}
