//
// Created by sunvy on 21/07/2026.
//

#include "GameLayer.h"

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

    {
        auto p = GetWorld()->CreateEntity("P1 Entity");
        auto& trans = p.AddComponent<Sunset::TransformComponent>();
        trans.SetLocation({-7.5, 0, 0});
        p.AddComponent<Sunset::SpriteRenderComponent>();
        p.AddComponent<Sunset::InputComponent>();
        p.AddComponent<Sunset::NativeScriptComponent>().Bind<PlayerSript>();
    }

    {
        auto p = GetWorld()->CreateEntity("P2 Entity");
        auto& trans = p.AddComponent<Sunset::TransformComponent>();
        trans.SetLocation({7.5, 0, 0});
        p.AddComponent<Sunset::SpriteRenderComponent>();
    }

    {
        auto p = GetWorld()->CreateEntity("Ball Entity");
        auto& trans = p.AddComponent<Sunset::TransformComponent>();

        p.AddComponent<Sunset::SpriteRenderComponent>();
    }
}
