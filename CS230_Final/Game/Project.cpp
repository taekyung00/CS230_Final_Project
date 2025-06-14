#include "Project.h"

Project::Project() : 
	player_ptr(nullptr),
	camera(nullptr)
{}

void Project::Load() 
{
	//Engine::GetWindow().SetSize({ default_width, default_height });
	/*camera = new CS230::Camera({ Math::vec2{ 0,0 }, static_cast<Math::vec2>(Engine::GetWindow().GetSize()) });
	camera->SetLimit({ {0,0},Engine::GetWindow().GetSize() });
	AddGSComponent(camera);*/
	//GetGSComponent<CS230::Camera>()->SetPosition({ 0.0, 0.0 });
	
#ifdef _DEBUG
	AddGSComponent(new CS230::ShowCollision());
	AddGSComponent(new Grid());
#endif
	AddGSComponent(new CS230::GameObjectManager);
	AddGSComponent(new CS230::ParticleManager<Particles::Tears>());
	
	player_ptr = new Player();
	GetGSComponent<CS230::GameObjectManager>()->Add(player_ptr);
	GetGSComponent<CS230::GameObjectManager>()->Add(new Bus(player_ptr));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line1,player_ptr,0));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line2,player_ptr,0));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line3,player_ptr,0));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line4,player_ptr,0));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line5,player_ptr,0));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line1, player_ptr, 1));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line2, player_ptr, 1));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line3, player_ptr, 1));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line4, player_ptr, 1));
	GetGSComponent<CS230::GameObjectManager>()->Add(new Passenger(BusLine::line5, player_ptr, 1));
}

void Project::Update([[maybe_unused]] double dt) 
{
	UpdateGSComponents(dt);
	/*camera->SetLimit({ {0,0},Engine::GetWindow().GetSize() });
	camera->Update(static_cast<Math::vec2>(Engine::GetWindow().GetSize()));*/
	GetGSComponent<CS230::GameObjectManager>()->UpdateAll(dt);

	Engine::GetGameStateManager().GetGSComponent<CS230::GameObjectManager>()->SortForDraw();

	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Escape)) {
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
	}
}

void Project::Unload() 
{
	
	GetGSComponent<CS230::GameObjectManager>()->Unload();
	ClearGSComponents();
	player_ptr = nullptr;
	camera = nullptr;
}

void Project::Draw() 
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
	//Math::TransformationMatrix camera_matrix = camera->GetMatrix();
	GetGSComponent<CS230::GameObjectManager>()->DrawAll(Math::TransformationMatrix());
	GetGSComponent<Grid>()->Draw(*(GetGSComponent<CS230::Camera>()));
}