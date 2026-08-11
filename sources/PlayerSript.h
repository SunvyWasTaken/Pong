//
// Created by sunvy on 09/08/2026.
//

#pragma once

#include "GameFramework/World/ScriptEntity.h"

constexpr float BaseSpeed = 8.f;

class PlayerSript : public Sunset::ScriptEntity
{
    public:
    Sunset::ReflectionType Properties() override;
    void OnBeginPlay() override;
    void OnUpdate(float dt) override;

    Sunset::Entity ballEntity;

    float Speed = BaseSpeed;
};

class Player2Sript : public Sunset::ScriptEntity
{
public:
    Sunset::ReflectionType Properties() override;
    void OnBeginPlay() override;
    void OnUpdate(float dt) override;

    Sunset::Entity ballEntity;

    float Speed = BaseSpeed;
};
