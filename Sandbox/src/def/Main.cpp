#include "pch.h"
#include "../hdr/Game.h"

int main(int argc, char** argv) {
	Game::Game game;

	if (!game.init()) { return 0; }
	while (game.isRunning()) {
		game.update();
		game.render(); }

	game.quit();
	return 0; }