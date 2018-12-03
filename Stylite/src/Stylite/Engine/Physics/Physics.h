#pragma once
#include "../../api_build.h"
#include "../Components/RigidBodyComponent.h"
#include "../Scene/Entity.h"
#include <vector>

namespace Stylite
{
	class Physics
	{
	public:
		STYLITE_API static	void		ApplyForce(RigidBodyComponent* rigid_body, vec2 direction, float speed);
		STYLITE_API static	float		Distance(Entity* first, Entity* second);
	};
}
