//
// Created by sunvy on 09/08/2026.
//

#include "BallScript.h"

#include "CollisionComponent.h"
#include "ScoreComponent.h"
#include "Core/Input.h"
#include "GameFramework/Components/InputComponent.h"
#include "GameFramework/Components/TransformComponent.h"

namespace
{
    enum Actions : Sunset::InputAction
    {
        Enter
    };

    bool start = false;
    glm::vec2 currVel = glm::vec2(0.0f);

    void Stop()
    {
        start = false;
        currVel = glm::vec2(0.0f);
    }
}

void BallScript::OnBeginPlay()
{
    ScriptEntity::OnBeginPlay();
    GetComponent<Sunset::InputComponent>()->BindAction(Sunset::Key::Enter, Enter);

    GetComponent<CollisionComponent>()->OnCollision = [&](const Sunset::Entity& entity)
    {
        currVel = -currVel;
    };
}

void BallScript::OnUpdate(float deltaTime)
{
    ScriptEntity::OnUpdate(deltaTime);
    if (!start)
        if (GetComponent<Sunset::InputComponent>()->IsActionPressed(Enter))
        {
            currVel = glm::vec2(10.f, 0.f);
            start = true;
        }

    auto* trans = GetComponent<Sunset::TransformComponent>();
    trans->AddLocation(glm::vec3(currVel, 0.f) * deltaTime);
    const glm::vec3 pos = trans->GetLocation();
    if (pos.x >= 9.f)
    {
        Stop();
        trans->SetLocation({});
        GetComponent<ScoreComponent>()->p1++;
    }
    if (pos.x <= -9.f)
    {
        Stop();
        trans->SetLocation({});
        GetComponent<ScoreComponent>()->p2++;
    }
}
