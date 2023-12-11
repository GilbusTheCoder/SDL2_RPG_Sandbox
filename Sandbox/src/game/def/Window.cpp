#include "pch.h"
#include "../hdr/Window.h"

// Returns true on success.
bool Game::Window::init(WindowData init_data) {
	_window = SDL_CreateWindow(init_data.title, init_data.x, 
		init_data.y, init_data.w, init_data.h, 0);

	if (!_window) { 
		LOG_ERROR("Failed to initialize SDL_Window.");	
		return false; }
	
	return true; }


void Game::Window::destroy() {
	if (_window) {
		SDL_DestroyWindow(_window);
		_window = nullptr; } }

