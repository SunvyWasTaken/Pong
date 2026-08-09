//
// Created by sunvy on 21/07/2026.
//

#include "PongModule.h"

#include "GameLayer.h"
#include "Core/Application.h"

void PongModule::Load(Sunset::Application &app)
{
    app.PushLayer<GameLayer>();
}

void PongModule::Unload()
{
}
