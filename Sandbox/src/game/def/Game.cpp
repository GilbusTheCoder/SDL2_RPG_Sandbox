#include "pch.h"
#include "../hdr/Logger.h"
#include "../hdr/Game.h"


const bool Sandbox::init() {
	Game::Logger::init();
	Game::WindowData init_data{
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		"Game" };

	if (!_window->init(init_data)) { 
		LOG_ERROR("Window wrapper failed to initialize.");
		return _is_running; }
	
	if (!_renderer->init(_window->getWindow())) { 
		LOG_ERROR("Renderer wrapper failed to initialize.");
		return _is_running; }

	_is_running = true;
	LOG_INFO("Initialization Successful.");
	return _is_running; }


void Sandbox::run() {
	const int dt = 1000 / _settings->fps_cap;	// In milliseconds
	Uint32 frame_start = SDL_GetTicks();

	while (_is_running) {
		frame_start = SDL_GetTicks();

		update(dt);
		render(); 
		
		if (SDL_GetTicks() - frame_start < dt) { SDL_Delay(dt - (SDL_GetTicks() - frame_start)); }
	} }


void Sandbox::update(const int dt) { }


void Sandbox::render() { _renderer->render(); }


void Sandbox::quit() {
	if (_window) { _window->destroy(); }
	if (_renderer) { _renderer->destroy(); } }

