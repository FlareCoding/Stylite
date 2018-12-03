#pragma once
#include "../Scene/Entity.h"
#include "../Scene/Scene.h"
#include "Physics.h"

namespace Stylite
{
	class PhysicsManager
	{
	public:
		PhysicsManager();
		void Initialize();

		void NormalizeEntityRotation(Entity* entity);
		void ApplyRigidProperties(Entity* entity, RigidBodyComponent* rigid_body);

		void Shutdown();
		~PhysicsManager();
	};
}
