//
// Created by sunvy on 21/07/2026.
//

#include "GameLayer.h"

#include "SunsetEngine.h"
#include "GameFramework/Components/CameraComponent.h"
#include "GameFramework/Components/SpriteRenderComponent.h"
#include "GameFramework/Components/TransformComponent.h"
#include "Render/Camera.h"

void GameLayer::Init()
{
    Layer::Init();

    LOG("Engine", info, "Pong Init");

    Sunset::Entity camera = GetWorld()->CreateEntity("Camera Entity");
    camera.AddComponent<Sunset::CameraComponent>().Activate(true);

    auto p1 = GetWorld()->CreateEntity("P1 Entity");
    p1.AddComponent<Sunset::TransformComponent>();
    p1.AddComponent<Sunset::SpriteRenderComponent>();

    // auto p2 = GetWorld()->CreateEntity("P2 Entity");
    // p2.AddComponent<Sunset::TransformComponent>();
}
