#pragma once

#include "../Engine/GameObject.h"

#include "Bus.h"
#include "Constants.h"
#include "Passenger.h"


class Player : public CS230::GameObject {
public:
	Player();
	void				Update(double dt) override;
	GameObjectTypes		Type() override { return GameObjectTypes::Player; }
	std::string			TypeName() override { return "Player"; }

	bool				CanCollideWith(GameObjectTypes other_object_type) override;
	void				ResolveCollision(GameObject* other_object) override;

	int					DrawPriority() const override { return 11; }

	const Math::vec2&	GetPosition() const { return GameObject::GetPosition(); }

	std::vector<bool>&			SetCanSteel() { return can_steel; }
	const std::vector<bool>&	GetCanSteel() const{ return can_steel; }

	int&						SetScore() { return score; }
	
private:
	int					score = 0;
	const Math::vec2	player_velocity = { 96.0,96.0 };
	
	std::vector<bool>	can_steel = { false,false,false,false,false };

};