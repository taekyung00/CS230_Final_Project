#pragma once

#include "../Engine/GameObject.h"

#include "BusLine.h"
#include "Player.h"
#include "Constants.h"
#include "Fonts.h"
class Passenger : public CS230::GameObject {
public:
    Passenger(BusLine busline,Player* player, int is_right);
    GameObjectTypes		Type() override { return GameObjectTypes::Passenger; }
    std::string			TypeName() override { return "Passenger"; }

    bool				CanCollideWith(GameObjectTypes other_object_type) override;
    void				ResolveCollision(GameObject* other_object) override;

    void                Draw(Math::TransformationMatrix camera_matrix) override;
private:
    Player* player;
    BusLine busline;
    CS230::Texture* has_food_texture;
    bool has_food = true;
    enum class Animations {
        Idle,
        Angry,
        Sad
    };
	

    class State_Idle : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Idle"; }
    };

    State_Idle state_idle;

    class State_Angry : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Angry"; }
    };

    State_Angry state_angry;

    class State_Sad : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Sad"; }
    };

    State_Sad state_sad;


};
