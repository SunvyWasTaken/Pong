//
// Created by sunvy on 21/07/2026.
//

#include "GameLayer.h"

#include "BallScript.h"
#include "CollisionComponent.h"
#include "PlayerSript.h"
#include "SunsetEngine.h"
#include "GameFramework/Components/CameraComponent.h"
#include "GameFramework/Components/InputComponent.h"
#include "GameFramework/Components/NativeScriptComponent.h"
#include "GameFramework/Components/SpriteRenderComponent.h"
#include "GameFramework/Components/TransformComponent.h"
#include "Render/Camera.h"

void GameLayer::Init()
{
    Layer::Init();

    LOG("Engine", info, "Pong Init");

    GetWorld()->AddSystem<CollisionSystem>();

    std::shared_ptr<SRmGUI::Panel> panel;
    std::shared_ptr<SRmGUI::Text> TextPlayer;

    SRmGUI::SNewAssign(panel)
        .Fill()
        .Child(
            SRmGUI::SNewAssign(TextPlayer)
            );

    AddToViewport(panel);

    Sunset::Entity camera = GetWorld()->CreateEntity("Camera Entity");
    auto& cam = camera.AddComponent<Sunset::CameraComponent>();
    cam.Activate(true);
    cam.SetProjectionType(Sunset::ProjectionType::Orthographic);

    // Player 1
    {
        auto p = GetWorld()->CreateEntity("P1 Entity");
        auto& trans = p.AddComponent<Sunset::TransformComponent>();
        trans.SetLocation({-7.5, 0, 0});
        trans.SetScale({0.2f, 1.f, 1.f});
        p.AddComponent<CollisionComponent>();
        p.AddComponent<Sunset::SpriteRenderComponent>();
        p.AddComponent<Sunset::InputComponent>();
        p.AddComponent<Sunset::NativeScriptComponent>().Bind<PlayerSript>();
    }

    // Player 2
    {
        auto p = GetWorld()->CreateEntity("P2 Entity");
        auto& trans = p.AddComponent<Sunset::TransformComponent>();
        trans.SetLocation({7.5, 0, 0});
        trans.SetScale({0.2f, 1.f, 1.f});
        p.AddComponent<CollisionComponent>();
        p.AddComponent<Sunset::SpriteRenderComponent>();
    }

    // Ball
    {
        auto p = GetWorld()->CreateEntity("Ball Entity");
        auto& trans = p.AddComponent<Sunset::TransformComponent>();
        trans.SetScale({0.1f, 0.1f, 0.1f});
        p.AddComponent<CollisionComponent>();
        p.AddComponent<Sunset::SpriteRenderComponent>();
        p.AddComponent<Sunset::InputComponent>();
        p.AddComponent<Sunset::NativeScriptComponent>().Bind<BallScript>();
    }
}
