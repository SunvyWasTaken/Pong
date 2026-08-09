//
// Created by sunvy on 09/08/2026.
//

#pragma once
#include "GameFramework/Components/Component.h"
#include "GameFramework/System/IWorldSystem.h"


class CollisionComponent : public Sunset::Component
{
public:
    std::function<void(const Sunset::Entity&)> OnCollision;
};

class CollisionSystem : public Sunset::IWorldSystem
{
public:
    using IWorldSystem::IWorldSystem;
    void Update(float dt) override;
};
