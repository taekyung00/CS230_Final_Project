#pragma once
#include "..\Engine\Engine.h"
#include "..\Engine\Texture.h"
#include "States.h"

class GoodSandwich : public CS230::GameState {
public:
    GoodSandwich(){}
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;


    std::string GetName() override {
        return "GoodSandwich";
    }

private:
    CS230::Texture* texture;
};