#pragma once
#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Camera.h"
#include "../Engine/GameObjectManager.h"

#include "Grid.h"
#include "Player.h"
#include "States.h"
#include "Bus.h"
#include "BusLine.h"
#include "Passenger.h"
#include "Particles.h"
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
    Player* player_ptr;
    CS230::Camera* camera;
    static constexpr int default_width = 600;
    static constexpr int default_height = 800;
};