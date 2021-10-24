#include "game.h"

void Game::Init(ILevel& level)
{
	level.Load();
}

void Game::UpDate(float delta_time, ILevel& level)
{
	camera.MoveCamera(delta_time);
	level.UpDate(delta_time);
}
