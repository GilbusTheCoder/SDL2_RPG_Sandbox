#pragma once

namespace Game {
	class Renderer {
	private:
		SDL_Renderer* _renderer = nullptr;
	
	public:
		bool init(SDL_Window* window);
		void destroy();
	
		void render();
	
		inline SDL_Renderer* getRenderer() { return _renderer; }
	};
}