#include "Bounce.h"

Bounce::Bounce(CS230::GameObject* given_object, Math::vec2 start_position, bool looping, double timer) :
	given_object(given_object),
	start_position(start_position),
	looping(looping),
	timer(timer)
{}
void Bounce::Update(double dt) {
	if (looping == false) {
		if (timer >= 0.0 && (timer - dt) >= 0.0) {
			timer -= dt;
		}
		else {
			timer = 0.0;
		}
	}

	if (looping == true || (looping == false &&timer > 0.0)) {
		if (given_object->GetPosition().y <= start_position.y) {
			given_object->SetVelocity({ given_object->GetVelocity().x,bounce_velocity });
			//Engine::GetLogger().LogDebug("just bounced");
		}
		else {
			given_object->UpdateVelocity({ 0,-100 * dt });
			//Engine::GetLogger().LogDebug("falling");
		}
	}
}