#include "Food.h"
#include "Passenger.h"

Food::Food(Passenger* owner, Math::vec2 pos) :
	owner(owner),
	GameObject(pos + Math::vec2{PassengerWidthHeight * 2/3,PassengerWidthHeight * 2 / 3 })
{
	AddGOComponent(new Bounce(this,GetPosition(),true));
	int result = Engine::GetGameStateManager().GetGSComponent<Random>()->PickRandomIndex(5, true);// index 0: Bread, 1: Hotdog, 2: KimBab, 3: Snack, 4: Strawberry

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
		Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Shining>>()->Emit(1, GetPosition(), {0,0}, {-10, -10}, PI / 3);
		Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Shining>>()->Emit(1, Math::vec2{PlayerWidthHeight/2,0} + GetPosition(), {0,0}, {10, 10}, PI / 3);
		Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Shining>>()->Emit(1, Math::vec2{0,PlayerWidthHeight/2} + GetPosition(), { 0,0 }, { 10, -10 }, PI / 3);
		Destroy();
	}
}