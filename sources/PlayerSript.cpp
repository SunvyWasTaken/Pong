//
// Created by sunvy on 09/08/2026.
//

#include "PlayerSript.h"

#include "GameFramework/Components/InputComponent.h"
#include "GameFramework/Components/TransformComponent.h"

namespace
{
    enum PlayerAction : Sunset::InputAction
    {
        MoveUp,
        MoveDown
    };
}

Sunset::ReflectionType PlayerSript::Properties()
{
    Sunset::ReflectionType properties;
    properties.Field("Speed", &PlayerSript::Speed);
    return properties;
}

void PlayerSript::OnBeginPlay()
{
    ScriptEntity::OnBeginPlay();
    GetComponent<Sunset::InputComponent>()->BindAction(Sunset::Key::W, MoveUp);
    GetComponent<Sunset::InputComponent>()->BindAction(Sunset::Key::S, MoveDown);
}

void PlayerSript::OnUpdate(float dt)
{
    ScriptEntity::OnUpdate(dt);

    if (GetComponent<Sunset::TransformComponent>()->GetLocation().y < 4.f)
        if (GetComponent<Sunset::InputComponent>()->IsActionDown(MoveUp))
            GetComponent<Sunset::TransformComponent>()->AddLocation(glm::vec3(0.0f, Speed, 0.0f) * dt);
    if (GetComponent<Sunset::TransformComponent>()->GetLocation().y > -4.f)
        if (GetComponent<Sunset::InputComponent>()->IsActionDown(MoveDown))
            GetComponent<Sunset::TransformComponent>()->AddLocation(glm::vec3(0.0f, -Speed, 0.0f) * dt);
}

Sunset::ReflectionType Player2Sript::Properties()
{
    Sunset::ReflectionType properties;
    properties.Field("Speed", &PlayerSript::Speed);
    return properties;
}

void Player2Sript::OnBeginPlay()
{
    ScriptEntity::OnBeginPlay();
    GetComponent<Sunset::InputComponent>()->BindAction(Sunset::Key::Up, MoveUp);
    GetComponent<Sunset::InputComponent>()->BindAction(Sunset::Key::Down, MoveDown);
}

void Player2Sript::OnUpdate(float dt)
{
    ScriptEntity::OnUpdate(dt);

    if (GetComponent<Sunset::TransformComponent>()->GetLocation().y < 4.f)
        if (GetComponent<Sunset::InputComponent>()->IsActionDown(MoveUp))
            GetComponent<Sunset::TransformComponent>()->AddLocation(glm::vec3(0.0f, Speed, 0.0f) * dt);
    if (GetComponent<Sunset::TransformComponent>()->GetLocation().y > -4.f)
        if (GetComponent<Sunset::InputComponent>()->IsActionDown(MoveDown))
            GetComponent<Sunset::TransformComponent>()->AddLocation(glm::vec3(0.0f, -Speed, 0.0f) * dt);
}
