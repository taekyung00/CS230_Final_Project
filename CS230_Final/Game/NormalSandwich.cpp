#include "NormalSandwich.h"
void NormalSandwich::Load() {
    texture = Engine::GetTextureManager().Load("Assets/NormalSandwich.png");
}

void NormalSandwich::Update([[maybe_unused]] double dt) {
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Escape)) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
    }

    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::R)) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Project));
    }
}

void NormalSandwich::Unload() {

}

void NormalSandwich::Draw() {
    Engine::GetWindow().Clear(UINT_MAX);
    texture->Draw(Math::TransformationMatrix());
}