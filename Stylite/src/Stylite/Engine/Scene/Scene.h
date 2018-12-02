#pragma once
#include <vector>
#include "Entity.h"
#include "../../api_build.h"

namespace Stylite
{
	class STYLITE_API Scene
	{
	public:
		Scene();

		void AddEntity(Entity* e);
		void RemoveEntity(Entity* e);
		std::vector<Entity*>& GetEntities() { return *this->m_entities; }

		~Scene();

	private:
		std::vector<Entity*>* m_entities;
	};
}
