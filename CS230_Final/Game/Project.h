#pragma once
#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Camera.h"
#include "Grid.h"
class Project : public CS230::GameState {
public:
    Project();
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;

    std::string GetName() override {
        return "Project";
    }
private:
    static constexpr int default_width = 800;
    static constexpr int default_height = 600;
};