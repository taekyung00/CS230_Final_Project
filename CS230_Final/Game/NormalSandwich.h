#pragma once
#include "..\Engine\Engine.h"
#include "..\Engine\Texture.h"
#include "States.h"

class NormalSandwich : public CS230::GameState {
public:
    NormalSandwich(){}
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;


    std::string GetName() override {
        return "NormalSandwich";
    }

private:
    CS230::Texture* texture;
};