#include "IComponent.h"

bool Stylite::IComponent::operator==(const IComponent& comp)
{
	return (this->owner == comp.owner);
}
