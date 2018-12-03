#include "EntityManager.h"
#include "SceneManager.h"
#include "../Components/Components.h"

namespace Stylite
{
	static std::vector<Entity*> entity_pool;

	Entity* CreateEntity()
	{
		Entity* entity = new Entity();
		entity_pool.push_back(entity);
		return entity;
	}

	STYLITE_API Entity* CreateEntity(RenderComponent* render_component, vec3 position, float rotation)
	{
		Entity* entity = new Entity();
		entity->AddComponent<RenderComponent>(render_component);
		entity->transform->position = position;
		entity->transform->rotation = rotation;
		entity_pool.push_back(entity);
		return entity;
	}

	STYLITE_API Entity* CloneEntity(Entity* entity, vec3 position, float rotation)
	{
		Entity* clone = new Entity();
		entity_pool.push_back(clone);
		clone->	name = entity->name;

		auto* _RenderComponent = entity->GetComponent<RenderComponent>();
		auto* _ShaderComponent = entity->GetComponent<ShaderComponent>();
		auto* _RigidBodyComponent = entity->GetComponent<RigidBodyComponent>();

		if (_RenderComponent) clone->AddComponent<RenderComponent>(new RenderComponent(_RenderComponent->mesh, &_RenderComponent->texture));
		if (_ShaderComponent) clone->AddComponent<ShaderComponent>(new ShaderComponent(_ShaderComponent->shader_type));
		if (_RigidBodyComponent) clone->AddComponent<RigidBodyComponent>(new RigidBodyComponent());

		clone->transform->position = position;
		clone->transform->rotation = rotation;

		return clone;
	}

	void DeleteEntity(Entity* entity)
	{
		size_t idx = std::find(entity_pool.begin(), entity_pool.end(), entity) - entity_pool.begin();
		if (idx < entity_pool.size())
		{
			delete entity_pool.at(idx);
			entity_pool.erase(entity_pool.begin() + idx);
		}
	}

	void DeleteAllEntities()
	{
		for (size_t i = 0; i < entity_pool.size(); i++)
			delete entity_pool.at(i);
		entity_pool.clear();
	}

	STYLITE_API void AddEntityToScene(Entity* entity)
	{
		Scene* scene = GetActiveScene();
		if (scene) scene->AddEntity(entity);
	}

	STYLITE_API void AddEntityToScene(Entity* entity, Scene* scene)
	{
		if (scene) scene->AddEntity(entity);
	}

	STYLITE_API void RemoveEntityFromScene(Entity* entity)
	{
		Scene* scene = GetActiveScene();
		if (scene) scene->RemoveEntity(entity);
	}
}
