//
// Created by sunvy on 21/07/2026.
//

#include "PongModule.h"

#include "BallScript.h"
#include "CollisionComponent.h"
#include "PlayerSript.h"
#include "ScoreComponent.h"
#include "GameFramework/Components/ComponentRegistry.h"
#include "GameFramework/World/ScriptRegistry.h"
#include "SaveSystem/BinaryArchive.h"

void PongModule::Load(Sunset::Application &app)
{
    Sunset::ScriptRegistry::Register<BallScript>("BallScript");
    Sunset::ScriptRegistry::Register<PlayerSript>("PlayerScript");
    Sunset::ScriptRegistry::Register<Player2Sript>("Player2Script");
    Sunset::ComponentRegistry::Register<CollisionComponent>("Collision", "Gameplay", {
        .Copy = [](const CollisionComponent&, CollisionComponent&) {},
        .Save = [](Sunset::BinaryOutputArchive&, CollisionComponent&) {},
        .Load = [](Sunset::BinaryInputArchive&, CollisionComponent&) {}
    });
    Sunset::ComponentRegistry::Register<ScoreComponent>("Score", "Gameplay", {
        .Copy = [](const ScoreComponent& source, ScoreComponent& target)
        {
            target.p1 = source.p1;
            target.p2 = source.p2;
        },
        .Save = [](Sunset::BinaryOutputArchive& archive, ScoreComponent& component)
        {
            archive(component.p1);
            archive(component.p2);
        },
        .Load = [](Sunset::BinaryInputArchive& archive, ScoreComponent& component)
        {
            archive(component.p1);
            archive(component.p2);
        }
    });
}

void PongModule::Unload()
{
}
