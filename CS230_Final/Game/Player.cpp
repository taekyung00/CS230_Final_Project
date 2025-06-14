#include "Player.h"

Player::Player() : 
	GameObject({ BusStartPosition+SeatWidthHeight + SeatWidthHeight/2 - PlayerWidthHeight/2,0 })
{
	AddGOComponent(new CS230::Sprite("Assets/Player.spt", this));
	//SetVelocity({ 30,30 });
}

void Player::Update([[maybe_unused]] double dt) {
    GameObject::Update(dt);
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
        SetVelocity({ player_velocity.x,GetVelocity().y});
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
        SetVelocity({ -player_velocity.x,GetVelocity().y });
    }
    else {
        SetVelocity({ 0,GetVelocity().y });
    }

    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Up)) {
        SetVelocity({ GetVelocity().x,player_velocity.y });
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Down)) {
        SetVelocity({ GetVelocity().x,-player_velocity.y });
    }
    else {
        SetVelocity({ GetVelocity().x,0 });
    }
}

bool Player::CanCollideWith(GameObjectTypes other_object_type) {
    if (other_object_type == GameObjectTypes::Passenger) {
        return true;
    }
    return false;
}

void Player::ResolveCollision(GameObject* other_object) {
    if (other_object->Type() == GameObjectTypes::Passenger) {
        Math::rect player_rect = GetGOComponent<CS230::RectCollision>()->WorldBoundary();
        Math::rect passenger_rect = other_object->GetGOComponent<CS230::RectCollision>()->WorldBoundary();

        if (player_rect.Left() < passenger_rect.Left()) {
            UpdatePosition(Math::vec2{ (passenger_rect.Left() - player_rect.Right()), 0.0 });
            SetVelocity({ 0, GetVelocity().y });
        }
        else {
            UpdatePosition(Math::vec2{ (passenger_rect.Right() - player_rect.Left()), 0.0 });
            SetVelocity({ 0, GetVelocity().y });
        }
    }
}