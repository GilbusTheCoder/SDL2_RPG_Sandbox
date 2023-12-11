#include "pch.h"
#include "../hdr/Renderer.h"

const bool Game::Renderer::init(SDL_Window* window) {
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	if (!_renderer) {
		LOG_ERROR("Failed to initialize SDL_Renderer*");
		return false; } 
	return true; }


void Game::Renderer::destroy() { if (_renderer) { SDL_DestroyRenderer(_renderer); } }


void Game::Renderer::render() {
	SDL_RenderClear(_renderer);
	SDL_Surface* bestagon = IMG_Load("assets/sprites/bestagon.png");
	if (bestagon) {
		SDL_Texture* textagon = SDL_CreateTextureFromSurface(_renderer, bestagon); 
		SDL_FreeSurface(bestagon);
		SDL_RenderCopy(_renderer, textagon, nullptr, nullptr); }

	
	SDL_RenderPresent(_renderer); }
