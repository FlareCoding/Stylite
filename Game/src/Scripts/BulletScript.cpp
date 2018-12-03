#include "BulletScript.h"

BulletScript::BulletScript(std::vector<Entity*>& asteroids) : asteroids(asteroids)
{
	startTime = Time::GetTime();
}

BulletScript::~BulletScript()
{
}

void BulletScript::OnUpdate()
{
	currentTime = Time::GetTime();
	owner->transform->rotation += 1;

	if (currentTime - startTime > lifeTime)
	{
		RemoveEntityFromScene(owner);
		DeleteEntity(owner);
		return;
	}
	
	for (size_t i = 0; i < asteroids.size(); i++)
	{
		if (!asteroids.at(i)) continue;

		if (Physics::Distance(owner, asteroids.at(i)) < 34)
		{
			Entity* asteroid = asteroids.at(i);
			asteroids.erase(asteroids.begin() + i);

			asteroid->transform->scale -= 0.3f;
			if (asteroid->transform->scale.x < 0.2f)
			{
				RemoveEntityFromScene(asteroid);
				DeleteEntity(asteroid);

				RemoveEntityFromScene(owner);
				DeleteEntity(owner);
				return;
			}

			Entity* newAsteroid = CloneEntity(asteroid, asteroid->transform->position, asteroid->transform->rotation);
			newAsteroid->transform->scale = asteroid->transform->scale;
			AddEntityToScene(newAsteroid);
			asteroids.push_back(asteroid);
			asteroids.push_back(newAsteroid);

			asteroid->GetComponent<RigidBodyComponent>()->velocity = vec2(0, 0);
			Physics::ApplyForce(asteroid->GetComponent<RigidBodyComponent>(), vec2(RandomFloat(-1, 1), RandomFloat(-1, 1)), 160.0f);
			Physics::ApplyForce(newAsteroid->GetComponent<RigidBodyComponent>(), vec2(RandomFloat(-1, 1), RandomFloat(-1, 1)), 160.0f);

			RemoveEntityFromScene(owner);
			DeleteEntity(owner);
			return;
		}
	}
}

float RandomFloat(float a, float b)
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}
