#pragma once
#include "../../api_build.h"
#include "Entity.h"
#include "Scene.h"
#include <vector>

namespace Stylite
{
	class RenderComponent;

	STYLITE_API Entity* CreateEntity();
	STYLITE_API Entity* CreateEntity(RenderComponent* render_component, vec3 position, float rotation);
	STYLITE_API Entity* CloneEntity(Entity* entity, vec3 position, float rotation);
	STYLITE_API void	DeleteEntity(Entity* entity);
	STYLITE_API void	DeleteAllEntities();

	STYLITE_API void	AddEntityToScene(Entity* entity);
	STYLITE_API void	AddEntityToScene(Entity* entity, Scene* scene);
	STYLITE_API void	RemoveEntityFromScene(Entity* entity);
}
