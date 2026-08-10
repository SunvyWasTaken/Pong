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
}

void ScoreSystem::Update(float deltaTime)
{
    m_World->Each<ScoreComponent>([&](const Sunset::Entity& entity, const ScoreComponent& score)
    {
        score.BallScore->SetText(std::format("{} | {}", score.p1, score.p2));
    });
}
