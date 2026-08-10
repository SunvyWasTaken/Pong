//
// Created by sunvy on 09/08/2026.
//

#pragma once
#include "GameFramework/World/ScriptEntity.h"

class BallScript : public Sunset::ScriptEntity
{
public:
    Sunset::ReflectionType Properties() override;
    void OnBeginPlay() override;
    void OnUpdate(float deltaTime) override;
    float ballSpeed = 10.f;
};
