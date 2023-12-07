#pragma once
#include <SDL.h>
#include <string>

namespace ECS {
	typedef std::string ucid, ueid;
	enum ComponentType {
		C_TRANSFORM,
		C_TEXTURE,
		C_INVALID };


	struct Component {
		ucid id;
		ComponentType type; };

	struct Transform : public Component {
		SDL_Rect bounds;
		SDL_Point origin; };

	struct Texture : public Component {
		bool render_this;
		SDL_Texture* sprite; };
}
