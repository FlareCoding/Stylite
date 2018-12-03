#include "Physics.h"

namespace Stylite
{
	void Physics::ApplyForce(RigidBodyComponent* rigid_body, vec2 direction, float speed)
	{
		rigid_body->velocity += direction * speed;
	}

	float Physics::Distance(Entity* first, Entity* second)
	{
		return abs((first->transform->position - second->transform->position).Length());
	}
}
