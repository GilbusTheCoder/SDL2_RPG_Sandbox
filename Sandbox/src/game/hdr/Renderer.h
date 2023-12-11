#pragma once

namespace Game {
	class Renderer {
	private:
		SDL_Renderer* _renderer = nullptr;
	
	public:
		const bool init(SDL_Window* window);
		void render();
		void destroy();
	
		inline SDL_Renderer* getRenderer() { return _renderer; }
	};
}