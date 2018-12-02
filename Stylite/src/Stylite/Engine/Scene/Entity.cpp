#include "Entity.h"
#include <algorithm>

namespace Stylite
{
	Entity::Entity()
	{
		transform = new TransformComponent();
	}

	Entity::~Entity()
	{
		for (std::map<unsigned int, IComponent*>::iterator it = components.begin(); it != components.end(); it++)
			delete it->second;
		delete transform;
	}
}
