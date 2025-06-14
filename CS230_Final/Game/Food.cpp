#include "Food.h"
#include "Passenger.h"

Food::Food(Passenger* owner, Math::vec2 pos) :
	owner(owner),
	GameObject(pos + Math::vec2{PassengerWidthHeight * 2/3,PassengerWidthHeight * 2 / 3 })
{
	AddGOComponent(new Bounce(this,GetPosition(),true));
	std::random_device rd;
	std::mt19937 gen(rd());

	std::discrete_distribution<> dist({ 20, 20, 20, 20, 20 }); // index 0: Bread, 1: Hotdog, 2: KimBab, 3: Snack, 4: Strawberry
	int result = dist(gen);

	switch (result)
	{
	case 0:
		AddGOComponent(new CS230::Sprite("Assets/Bread.spt", this));
		break;
	case 1:
		AddGOComponent(new CS230::Sprite("Assets/Hotdog.spt", this));
		break;
	case 2:
		AddGOComponent(new CS230::Sprite("Assets/KimBab.spt", this));
		break;
	case 3:
		AddGOComponent(new CS230::Sprite("Assets/Snack.spt", this));
		break;
	case 4:
		AddGOComponent(new CS230::Sprite("Assets/Strawberry.spt", this));
		break;
	}
}

void Food::Update(double dt) {
	GameObject::Update(dt);
	if (owner->GetHasFood() == false) {
		Destroy();
	}
}