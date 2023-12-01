#include "pch.h"
#include "../hdr/Renderer.h"

bool Game::Renderer::init(SDL_Window* window) {
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer) {
		SDL_Log("Renderer >> Couldn't init SDL_Render*\n");
		return false;	}
	
	return true; }


void Game::Renderer::destroy() { if (_renderer) { SDL_DestroyRenderer(_renderer); } }


void Game::Renderer::render() {
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer); }
