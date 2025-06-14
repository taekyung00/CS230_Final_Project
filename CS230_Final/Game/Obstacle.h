#pragma once
#include <random>
#include "../Engine/GameObject.h"
#include "Score.h"
#include "Ziggle.h"

class Player;
class Obstacle : public CS230::GameObject {
public:
	Obstacle(Player* player, Math::vec2 pos);
	virtual int			DrawPriority() const { return 12; }
	GameObjectTypes		Type() override { return GameObjectTypes::Obstacle; }
	std::string			TypeName() override { return "Obstacle"; }

	bool				CanCollideWith(GameObjectTypes other_object_type) override;
	void				ResolveCollision(GameObject* other_object) override;
private:
	Player* player;
};