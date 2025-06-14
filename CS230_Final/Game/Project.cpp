#include "Project.h"

Project::Project(){}

void Project::Load() 
{
	AddGSComponent(new CS230::Camera({ Math::vec2{ 0,0 }, static_cast<Math::vec2>(Engine::GetWindow().GetSize()) }));
	GetGSComponent<CS230::Camera>()->SetPosition({ 0.0, 0.0 });
	AddGSComponent(new Grid());
}

void Project::Update([[maybe_unused]] double dt) 
{
	UpdateGSComponents(dt);
	GetGSComponent<CS230::Camera>()->Update(static_cast<Math::vec2>(Engine::GetWindow().GetSize()));
}

void Project::Unload() {}

void Project::Draw() 
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
	GetGSComponent<Grid>()->Draw(*(GetGSComponent<CS230::Camera>()));
}