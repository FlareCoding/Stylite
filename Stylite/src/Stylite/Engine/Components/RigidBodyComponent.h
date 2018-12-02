#pragma once
#include "IComponent.h"
#include "../Math/Mathematics.h"

namespace Stylite
{
	class RigidBodyComponent : public IComponent
	{
	public:
		STYLITE_API RigidBodyComponent();

		vec2 velocity = vec2(0.0f, 0.0f);

		STYLITE_API ~RigidBodyComponent();
	};
}
