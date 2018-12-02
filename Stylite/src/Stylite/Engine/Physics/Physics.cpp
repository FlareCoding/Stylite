#include "Physics.h"

namespace Stylite
{
	void Physics::ApplyForce(RigidBodyComponent* rigid_body, vec2 direction, float speed)
	{
		rigid_body->velocity += direction * speed;
	}
}
