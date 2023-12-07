#include "pch.h"
#include "../hdr/Game.h"

bool Game::Game::init() {
	WindowData init_data{
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		"Game" };

	if (!_window->init(init_data)) { return _is_running; }
	if (!_renderer->init(_window->getWindow())) { return _is_running; }
	//if (!_ec_manager->init()) { return _is_running; }

	_is_running = true;
	return _is_running; }


void Game::Game::run() {
	const int dt = 1000 / _settings->fps_cap;	// In milliseconds
	Uint32 frame_start = SDL_GetTicks();

	while (_is_running) {
		frame_start = SDL_GetTicks();

		update(dt);
		render(); 
		
		if (SDL_GetTicks() - frame_start < dt) { SDL_Delay(dt - (SDL_GetTicks() - frame_start)); }
	}
}

void Game::Game::update(const int dt) { 

}
void Game::Game::render() { _renderer->render(); }

void Game::Game::quit() { 
	if (_window) { _window->destroy(); }
	if (_renderer) { _renderer->destroy(); } }
