#include "GoodSandwich.h"
void GoodSandwich::Load() {
    texture = Engine::GetTextureManager().Load("Assets/GoodSandwich.png");
}

void GoodSandwich::Update([[maybe_unused]] double dt) {
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Escape)) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
    }

    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::R)) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Project));
    }
}

void GoodSandwich::Unload() {
    
}

void GoodSandwich::Draw() {
    Engine::GetWindow().Clear(UINT_MAX);
    texture->Draw(Math::TransformationMatrix());
}