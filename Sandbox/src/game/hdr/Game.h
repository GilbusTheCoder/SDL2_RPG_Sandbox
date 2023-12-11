#pragma once
#include "Renderer.h"
#include "Window.h"
#include "Settings.h"
#include "../../ecs/hdr/ECManager.h"

class Sandbox {
private:
	bool _is_running = false;
	Game::Window* _window = new Game::Window();
	Game::Renderer* _renderer = new Game::Renderer();
	Game::Settings* _settings = new Game::Settings();

	ECS::ECManager* _ec_manager = new ECS::ECManager();

public:
	const bool init();
	void run();
	void quit();

private:
	void update(const int dt);
	void render();
};
