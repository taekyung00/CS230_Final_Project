#include "Obstacle.h"
#include "Player.h"
Obstacle::Obstacle(Player* player, Math::vec2 pos) :
	player(player),
	GameObject(pos)
{
	int result = Engine::GetGameStateManager().GetGSComponent<Random>()->PickRandomIndex(2,true);// index 0: Bomb, 1: Shoes
	switch (result)
	{
	case 0:
		AddGOComponent(new CS230::Sprite("Assets/Bomb.spt", this));
		break;
	case 1:
		AddGOComponent(new CS230::Sprite("Assets/Shoes.spt", this));
		break;
	}
}

bool Obstacle::CanCollideWith(GameObjectTypes other_object_type) {
	if (other_object_type == GameObjectTypes::Player) {
		return true;
	}
	return false;
}

void Obstacle::ResolveCollision(GameObject* other_object) {
	if (other_object->Type() == GameObjectTypes::Player) {
		player->GetGOComponent<Score>()->Sub(10);
		Destroy();
	}
}
