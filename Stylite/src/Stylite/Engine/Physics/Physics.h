#pragma once
#include "../../api_build.h"
#include "../Components/RigidBodyComponent.h"

namespace Stylite
{
	class STYLITE_API Physics
	{
	public:
		static void ApplyForce(RigidBodyComponent* rigid_body, vec2 direction, float speed);
	};
}
