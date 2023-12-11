#include "pch.h"
#include "../hdr/Game.h"

int main(int argc, char** argv) {
	Sandbox game;
	if (!game.init()) { return 0; }

	game.run();
	game.quit();

	return 0; }