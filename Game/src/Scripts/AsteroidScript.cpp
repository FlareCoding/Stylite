#include "AsteroidScript.h"

AsteroidScript::AsteroidScript()
{
}

AsteroidScript::~AsteroidScript()
{
}

void AsteroidScript::OnUpdate()
{
	if ((int)Time::GetTime() % 4 == 0)
	{
		Entity* newAsteroid = CreateEntity();
		newAsteroid->AddComponent<RenderComponent>(new RenderComponent(Shapes::Rectangle(100, 100), nullptr));
		newAsteroid->transform->position = owner->transform->position;
		newAsteroid->transform->position.x -= 20;
		AddEntityToScene(newAsteroid);
	}
}
