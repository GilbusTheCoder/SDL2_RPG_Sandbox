#pragma once
#include "Renderer.h"
#include "Window.h"

namespace Game {
	class Game {
	private:
		bool _is_running = false;

		Window* _window = new Window();
		Renderer* _renderer = new Renderer();
	

	public:
		bool init();
		void update();
		void render();
		void quit();
	
		inline bool isRunning() { return _is_running; }
	};
}

