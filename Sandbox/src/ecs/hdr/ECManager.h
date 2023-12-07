#pragma once
#include "System.h"
#include "Components.h"

namespace ECS {
	class ECManager {
	private:
		std::unordered_map<int, System*> _systems;
		std::vector<ueid> _entities;
		std::unordered_map<ComponentType ,std::unordered_map<ucid, Component*>> _components;

	public:
		bool init();
		void update(const int dt);
		void render();
		void destroy();
		
		void addSystem();
		void addEntity();
		void addComponent();

	private:
	};
}

