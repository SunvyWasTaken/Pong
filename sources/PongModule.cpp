//
// Created by sunvy on 21/07/2026.
//

#include "PongModule.h"

#include "BallScript.h"
#include "CollisionComponent.h"
#include "PlayerSript.h"
#include "GameFramework/World/ScriptRegistry.h"

void PongModule::Load(Sunset::Application &app)
{
    Sunset::ScriptRegistry::Register<BallScript>("BallScript");
    Sunset::ScriptRegistry::Register<PlayerSript>("PlayerScript");
    Sunset::ScriptRegistry::Register<Player2Sript>("Player2Script");
}

void PongModule::Unload()
{
}
