//
// Created by sunvy on 21/07/2026.
//

#pragma once

#include "Core/GameModule.h"

class PongModule : public Sunset::IGameModule
{
public:
    void Load(Sunset::Application &app) override;
    void Unload() override;
};

CREATE_MODULE(PongModule);
