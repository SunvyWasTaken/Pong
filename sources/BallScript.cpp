//
// Created by sunvy on 09/08/2026.
//

#include "BallScript.h"

#include "CollisionComponent.h"
#include "ScoreComponent.h"
#include "Core/Input.h"
#include "GameFramework/Components/InputComponent.h"
#include "GameFramework/Components/TransformComponent.h"

#include <random>

namespace
{
    enum Actions : Sunset::InputAction
    {
        Enter
    };

    bool Restart = true;
    bool start = false;
    glm::vec2 currVel = glm::vec2(0.0f);
    bool p1Serve = true;
    int nbrRebond = 0;

    std::ranlux24_base rng{std::random_device{}()};

    void Stop()
    {
        nbrRebond = 0;
        start = false;
        currVel = glm::vec2(0.0f);
    }
}

Sunset::ReflectionType BallScript::Properties()
{
    Sunset::ReflectionType properties;
    properties.Field("Ball speed", &BallScript::ballSpeed);
    properties.Field("Rebond", [](void* instance){ return &nbrRebond; });
    return properties;
}

void BallScript::OnBeginPlay()
{
    ScriptEntity::OnBeginPlay();
    GetComponent<Sunset::InputComponent>()->BindAction(Sunset::Key::Space, Enter);

    GetComponent<CollisionComponent>()->OnCollision = [&](const Sunset::Entity& entity)
    {
        glm::vec3 targetLoc = entity.GetComponent<Sunset::TransformComponent>()->GetLocation();
        glm::vec3 loc = GetComponent<Sunset::TransformComponent>()->GetLocation();

        glm::vec3 dir = loc - targetLoc;
        dir.z = 0.f;
        dir = glm::normalize(dir);
        ++nbrRebond;
        if (nbrRebond > 25)
            nbrRebond = 0;
        currVel = dir * (ballSpeed + nbrRebond * 0.5f);
    };
}

void BallScript::OnUpdate(float deltaTime)
{
    ScriptEntity::OnUpdate(deltaTime);
    if (!start)
    {
        if (GetComponent<Sunset::InputComponent>()->IsActionPressed(Enter))
        {
            StartGame();
        }
        return;
    }

    auto* trans = GetComponent<Sunset::TransformComponent>();
    trans->AddLocation(glm::vec3(currVel, 0.f) * deltaTime);
    const glm::vec3 pos = trans->GetLocation();

    if (pos.y >= 4.f && currVel.y > 0.f)
    {
        currVel.y = -currVel.y;
    }
    if (pos.y <= -4.f && currVel.y < 0.f)
        currVel.y = -currVel.y;

    if (pos.x >= 9.f)
    {
        Stop();
        trans->SetLocation({});
        GetComponent<ScoreComponent>()->p1++;
        p1Serve = true;
        StartGame();
    }
    if (pos.x <= -9.f)
    {
        Stop();
        trans->SetLocation({});
        GetComponent<ScoreComponent>()->p2++;
        p1Serve = false;
        StartGame();
    }

    int winner = 0;
    if (GetComponent<ScoreComponent>()->hasWinner(winner))
    {
        GetComponent<ScoreComponent>()->DisplayWinner(winner);
        Restart = true;
    }
}

void BallScript::StartGame()
{
    if (Restart)
    {
        GetComponent<ScoreComponent>()->Reset();
        Restart = false;
    }
    std::uniform_int_distribution<int> distX(5, 10);
    std::uniform_int_distribution<int> distY(1, 5);
    glm::vec2 dir = {distX(rng), distY(rng)};
    dir = glm::normalize(dir);
    currVel = dir * ballSpeed * (p1Serve ? 1.f : -1.f);
    start = true;
}
