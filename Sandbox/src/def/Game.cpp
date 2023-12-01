#include "pch.h"
#include "../hdr/Game.h"

bool Game::Game::init() {
	WindowData init_data{
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		"Game" };

	if (!_window->init(init_data)) { return false; }
	if (!_renderer->init(_window->getWindow())) { return false; }

	_is_running = true;
	return true; }

void Game::Game::update() { }
void Game::Game::render() { _renderer->render(); }

void Game::Game::quit() { 
	if (_window) { _window->destroy(); }
	if (_renderer) { _renderer->destroy(); } }
