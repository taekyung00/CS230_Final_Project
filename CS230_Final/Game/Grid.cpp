#include "Grid.h"

Grid::Grid()
{
	black_dot = Engine::GetTextureManager().Load("Assets/BlackDot.png");
	red_dot = Engine::GetTextureManager().Load("Assets/RedDot.png");
	blue_dot = Engine::GetTextureManager().Load("Assets/BlueDot.png");
}

void Grid::Update([[maybe_unused]] double dt) {
	if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Tab)) {
		draw = !draw;
	}
}
void Grid::Draw([[maybe_unused]] const CS230::Camera& camera) {
	if (draw) {
		for (int i = 0; i <= Engine::GetWindow().GetSize().y / 10; ++i) {
			for (int j = 0; j <= Engine::GetWindow().GetSize().x / 10; ++j) {
				Math::TransformationMatrix draw_matrix = Math::TranslationMatrix(Math::ivec2{ j * 10,i * 10 }) /** Math::TranslationMatrix(-camera.GetPosition())*/;
				if (i == 0 && j == 0) {
					blue_dot->Draw(draw_matrix * Math::ScaleMatrix(4.0));
				}
				else if (i == 0 || i == Engine::GetWindow().GetSize().y / 10 || j == 0 || j == Engine::GetWindow().GetSize().x / 10) {
					red_dot->Draw(draw_matrix * Math::ScaleMatrix(2.0));
				}
				else {
					black_dot->Draw(draw_matrix);
				}
			}
		}
	}
	
}