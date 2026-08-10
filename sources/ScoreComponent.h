//
// Created by sunvy on 10/08/2026.
//

#pragma once

#include "GameFramework/Components/Component.h"
#include "GameFramework/System/IWorldSystem.h"
#include "SRmGUI.h"

class ScoreComponent : public Sunset::Component
{
public:
    ScoreComponent();
    bool hasWinner(int& winner) const;
    void DisplayWinner(int winner) const;
    void Reset();
    int p1 = 0, p2 = 0;
    std::shared_ptr<SRmGUI::Text> BallScore;
    std::shared_ptr<SRmGUI::Text> Winner;
};

class ScoreSystem : public Sunset::IWorldSystem
{
public:
    using IWorldSystem::IWorldSystem;
    void Update(float deltaTime) override;
};
