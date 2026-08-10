//
// Created by sunvy on 09/08/2026.
//

#pragma once
#include "GameFramework/World/ScriptEntity.h"


class PlayerSript : public Sunset::ScriptEntity
{
    public:
    Sunset::ReflectionType Properties() override;
    void OnBeginPlay() override;
    void OnUpdate(float dt) override;

    float Speed = 10.f;
};

class Player2Sript : public Sunset::ScriptEntity
{
public:
    Sunset::ReflectionType Properties() override;
    void OnBeginPlay() override;
    void OnUpdate(float dt) override;

    float Speed = 10.f;
};
