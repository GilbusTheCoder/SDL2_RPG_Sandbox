#pragma once
#include "Renderer.h"
#include "Window.h"
#include "Settings.h"
#include "../../ecs/hdr/ECManager.h"

namespace Game {
	class Game {
	private:
		bool _is_running = false;
		Window* _window = new Window();
		Renderer* _renderer = new Renderer();
		Settings* _settings = new Settings();

		ECS::ECManager* _ec_manager = new ECS::ECManager();

	public:
		bool init();
		void run();
		void quit();
	
	private:
		void update(const int dt);
		void render();
	};
}