#include "Passenger.h"

Passenger::Passenger(BusLine busline, Player* player, int is_right) :
	busline(busline),
	player(player),
	GameObject({ BusStartPosition + static_cast<double>(is_right * SeatWidthHeight * 2) + PassengerPadding, static_cast<double>(static_cast<int>(busline) * (SeatWidthHeight + GapHeight)) + PassengerPadding })
{
	AddGOComponent(new CS230::Sprite("Assets/Passenger.spt", this));
	current_state = &state_idle;
	current_state->Enter(this);
}

bool Passenger::CanCollideWith(GameObjectTypes other_object_type) {
    if (other_object_type == GameObjectTypes::Player) {
        return true;
    }
    return false;
}

void Passenger::ResolveCollision(GameObject* other_object) {
    if (other_object->Type() == GameObjectTypes::Player) {
		if (has_food == true) {
			if (player->GetCanSteel()[static_cast<int>(busline)] == true) {
				player->SetScore() += 10;
				has_food = false;
				change_state(&state_sad);
			}
			else {
				Engine::GetLogger().LogDebug("You're Captured!!!!");
				change_state(&state_angry);
			}
			
		}
    }
}

void Passenger::Draw(Math::TransformationMatrix camera_matrix) {
	GameObject::Draw(camera_matrix);
	has_food_texture->Draw(camera_matrix * GetMatrix());
}

void Passenger::State_Idle::Enter([[maybe_unused]] GameObject* object) {
	Passenger* passenger = static_cast<Passenger*>(object);
	passenger->has_food_texture = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("O", 0x000000FF);
}

void Passenger::State_Idle::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {

}

void Passenger::State_Idle::CheckExit([[maybe_unused]] GameObject* object) {

}

void Passenger::State_Angry::Enter([[maybe_unused]] GameObject* object) {
	Passenger* passenger = static_cast<Passenger*>(object);
	passenger->has_food_texture = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("XX", 0x000000FF);
}

void Passenger::State_Angry::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {

}

void Passenger::State_Angry::CheckExit([[maybe_unused]] GameObject* object) {

}

void Passenger::State_Sad::Enter([[maybe_unused]] GameObject* object) {
	Passenger* passenger = static_cast<Passenger*>(object);
	passenger->has_food_texture = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("X", 0x000000FF);
}

void Passenger::State_Sad::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {

}

void Passenger::State_Sad::CheckExit([[maybe_unused]] GameObject* object) {

}