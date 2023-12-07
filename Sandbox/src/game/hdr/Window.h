#pragma once

namespace Game {
	struct WindowData {
		int x, y, w, h;
		const char* title; };

	class Window {
	private:
		int _x=0, _y=0, _w=0, _h=0;
		const char* _title = "";

		SDL_Window* _window = nullptr;

	public:
		bool init(WindowData init_data);
		void destroy();

		inline SDL_Window* getWindow() { return _window; }
	};
}

