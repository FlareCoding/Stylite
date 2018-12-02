#pragma once
#include <map>
#include "../../api_build.h"
#include "../Components/IComponent.h"
#include "../Components/TransformComponent.h"

namespace Stylite
{
	class Entity
	{
	public:
		STYLITE_API Entity();

		template <typename T>
		void AddComponent(IComponent* _component) 
		{
			if (components.find(typeid(T).hash_code()) == components.end())
			{
				components[typeid(T).hash_code()] = _component;
				_component->owner = this;
			}
		}

		template <typename T>
		T* GetComponent() 
		{
			unsigned int hash = typeid(T).hash_code();
			if (components.find(hash) != components.end())
				return static_cast<T*>(components.at(hash));
			return nullptr;
		}

		template <typename T>
		void RemoveComponent()
		{
			unsigned int hash = typeid(T).hash_code();
			IComponent* component = components.at(hash);
			components.erase(hash);
			delete component;
		}

		STYLITE_API void RemoveComponent(IComponent* _component);
		TransformComponent* transform;

		STYLITE_API ~Entity();

	private:
		std::map<unsigned int, IComponent*> components;
	};
	
	inline STYLITE_API void Entity::RemoveComponent(IComponent* _component)
	{
		for (std::map<unsigned int, IComponent*>::iterator it = components.begin(); it != components.end(); it++)
		{
			if ((it->second) == _component)
			{
				components.erase(it);
				delete it->second;
				break;
			}
		}
	}
}
