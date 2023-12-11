#pragma once

namespace Game {
	struct Settings {
		std::pair<int, int> resolution = {800, 600};
		const int fps_cap = 60; }; }