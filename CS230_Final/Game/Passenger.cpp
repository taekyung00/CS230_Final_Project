#include "Passenger.h"

Passenger::Passenger(BusLine busline, Player* player, int is_right) :
	busline(busline),
	player(player),
	GameObject({ BusStartPosition + static_cast<double>(is_right * SeatWidthHeight * 2) + PassengerPadding, static_cast<double>(static_cast<int>(busline) * (SeatWidthHeight + GapHeight)) + PassengerPadding })
{
	AddGOComponent(new CS230::Sprite("Assets/Passenger.spt", this));
	AddGOComponent(new CS230::Timer(0.0));
	current_state = &state_idle;
	current_state->Enter(this);
	Engine::GetGameStateManager().GetGSComponent<CS230::GameObjectManager>()->Add(new Food(this, GetPosition()));
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
				player->GetGOComponent<Score>()->Add(20);
				has_food = false;
				change_state(&state_sad);
			}
			else {
				player->GetGOComponent<Score>()->Sub(10);
				change_state(&state_angry);
			}
			
		}
    }
}

void Passenger::State_Idle::Enter([[maybe_unused]] GameObject* object) {
	Passenger* passenger = static_cast<Passenger*>(object);
	passenger->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Idle));
}

void Passenger::State_Idle::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {

}

void Passenger::State_Idle::CheckExit([[maybe_unused]] GameObject* object) {

}

void Passenger::State_Angry::Enter([[maybe_unused]] GameObject* object) {
	Passenger* passenger = static_cast<Passenger*>(object);
	passenger->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Angry));
}

void Passenger::State_Angry::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {

}

void Passenger::State_Angry::CheckExit([[maybe_unused]] GameObject* object) {

}

void Passenger::State_Sad::Enter([[maybe_unused]] GameObject* object) {
	Passenger* passenger = static_cast<Passenger*>(object);
	passenger->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Sad));
	passenger->GetGOComponent<CS230::Timer>()->Set(cry_timer);
	Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Tears>>()->Emit(1, Math::vec2{ 10,PassengerWidthHeight * 2 / 3 } + passenger->GetPosition(), { 0,0 }, { -10, -10 }, PI / 3);
	Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Tears>>()->Emit(1, Math::vec2{ PassengerWidthHeight -10,PassengerWidthHeight * 2 / 3 } + passenger->GetPosition(), { 0,0 }, { 10, -10 }, PI / 3);
}

void Passenger::State_Sad::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {
	Passenger* passenger = static_cast<Passenger*>(object);
	if (passenger->GetGOComponent<CS230::Timer>()->Remaining() == 0.0) {
		passenger->GetGOComponent<CS230::Timer>()->Set(cry_timer);
		Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Tears>>()->Emit(1, Math::vec2{ 10,PassengerWidthHeight * 2 / 3 } + passenger->GetPosition(), { 0,0 }, { -10, -10 }, PI / 3);
		Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Tears>>()->Emit(1, Math::vec2{ PassengerWidthHeight -10,PassengerWidthHeight * 2 / 3 } + passenger->GetPosition(), { 0,0 }, { 10, -10 }, PI / 3);
	}
}

void Passenger::State_Sad::CheckExit([[maybe_unused]] GameObject* object) {

}