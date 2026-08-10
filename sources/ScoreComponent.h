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
    int p1 = 0, p2 = 0;
    std::shared_ptr<SRmGUI::Text> BallScore;
};

class ScoreSystem : public Sunset::IWorldSystem
{
public:
    using IWorldSystem::IWorldSystem;
    void Update(float deltaTime) override;
};
