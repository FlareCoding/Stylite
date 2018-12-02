#pragma once
#include "IComponent.h"

namespace Stylite
{
	class STYLITE_API ScriptComponent : public IComponent
	{
	public:
		ScriptComponent();
		
		virtual void OnUpdate() {}

		virtual ~ScriptComponent();
	};
}

