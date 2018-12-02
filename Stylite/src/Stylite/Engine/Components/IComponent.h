#pragma once
#include "../../api_build.h"

namespace Stylite
{
	class Entity;

	class STYLITE_API IComponent 
	{
	public:
		Entity* owner;
		bool operator==(const IComponent& comp);

		virtual ~IComponent() {}
	};
}