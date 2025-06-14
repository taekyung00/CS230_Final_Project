#pragma once
#include "..\Engine\Engine.h"
#include "..\Engine\Texture.h"
#include "States.h"

class BadSandwich : public CS230::GameState {
public:
    BadSandwich(){}
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;


    std::string GetName() override {
        return "BadSandwich";
    }

private:
    CS230::Texture* texture;
};