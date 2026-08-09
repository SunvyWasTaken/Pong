//
// Created by sunvy on 09/08/2026.
//

#include "CollisionComponent.h"

#include "GameFramework/Components/TransformComponent.h"
#include "GameFramework/World/World.h"
#include "GameFramework/World/Entity.h"

namespace
{

    glm::vec2 Min(const Sunset::TransformComponent& t)
    {
        return {t.Position.x - (t.Scale.x / 2.f), t.Position.y - (t.Scale.y / 2.f)};
    }

    glm::vec2 Max(const Sunset::TransformComponent& t)
    {
        return {t.Position.x + (t.Scale.x / 2.f), t.Position.y + (t.Scale.y / 2.f)};
    }

    void CheckCollision(const Sunset::Entity& e1, const Sunset::Entity& e2)
    {
        auto* t1 = e1.GetComponent<Sunset::TransformComponent>();
        auto* t2 = e2.GetComponent<Sunset::TransformComponent>();

        const glm::vec2 aMin = Min(*t1);
        const glm::vec2 aMax = Max(*t1);

        const glm::vec2 bMin = Min(*t2);
        const glm::vec2 bMax = Max(*t2);

        if (aMin.x <= bMax.x && aMax.x >= bMin.x && aMin.y <= bMax.y && aMax.y >= bMin.y)
        {
            if (e1.GetComponent<CollisionComponent>()->OnCollision)
                e1.GetComponent<CollisionComponent>()->OnCollision(e2);
            if (e2.GetComponent<CollisionComponent>()->OnCollision)
                e2.GetComponent<CollisionComponent>()->OnCollision(e1);
        }
    }
}

void CollisionSystem::Update(float dt)
{
    IWorldSystem::Update(dt);
    std::vector<Sunset::Entity> entities;
    m_World->Each<Sunset::TransformComponent, CollisionComponent>([&](const Sunset::Entity& entity, Sunset::TransformComponent& transform, CollisionComponent& collider)
    {
        entities.emplace_back(entity);
    });

    for (size_t i = 0; i < entities.size(); ++i)
    {
        for (size_t j = i + 1; j < entities.size(); ++j)
        {
            CheckCollision(entities[i], entities[j]);
        }
    }
}
