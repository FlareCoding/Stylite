#include "PhysicsManager.h"
#include "../Time/Time.h"

namespace Stylite
{
	PhysicsManager::PhysicsManager()
	{
	}

	PhysicsManager::~PhysicsManager()
	{
	}

	void PhysicsManager::Initialize()
	{
	}

	void PhysicsManager::Shutdown()
	{
	}

	void PhysicsManager::NormalizeEntityRotation(Entity* entity)
	{
		if (entity->transform->rotation > 180.0f) entity->transform->rotation -= 360.0f;
		if (entity->transform->rotation < -180.0f) entity->transform->rotation += 360.0f;
	}

	void PhysicsManager::ApplyRigidProperties(Entity* entity, RigidBodyComponent* rigid_body)
	{
		entity->transform->position.x += rigid_body->velocity.x * (float)Time::GetDeltaTime();
		entity->transform->position.y += rigid_body->velocity.y * (float)Time::GetDeltaTime();
	}
}
