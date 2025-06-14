#pragma once
#include <filesystem>
#include "../Engine/Engine.h"
#include "../Engine/Component.h"
#include "../Engine/Vec2.h"
#include "../Engine/Camera.h"
#include "../Engine/Texture.h"
#include "Fonts.h"

class Grid : public CS230::Component {
public:
    Grid(); 
    void Update(double dt) override;
    void Draw(const CS230::Camera& camera);
private:
    Math::ivec2 window_size;
    bool draw = true;
    CS230::Texture* black_dot;
    CS230::Texture* red_dot;
    CS230::Texture* blue_dot;
    CS230::Texture* dot_number;
};