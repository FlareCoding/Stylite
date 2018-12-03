#include "PlayerScript.h"

PlayerScript::PlayerScript(Entity* firstAsteroid)
{
	normalTexture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\spaceship.png", ClampToBorder);
	normalTexture.transparent = true;

	acceleratingTexture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\spaceshipAccelerating.png", ClampToBorder);
	acceleratingTexture.transparent = true;

	asteroids.push_back(firstAsteroid);
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::ProcessMovement()
{
	if (Keyboard::IsKeyDown(Keyboard::KEY_W))
	{
		owner->GetComponent<RenderComponent>()->texture = acceleratingTexture;
		Physics::ApplyForce(owner->GetComponent<RigidBodyComponent>(), owner->transform->GetDirectionVector(), playerSpeed * (float)Time::GetDeltaTime());
	}
	else
		owner->GetComponent<RenderComponent>()->texture = normalTexture;

	if (Keyboard::IsKeyDown(Keyboard::KEY_S)) Physics::ApplyForce(owner->GetComponent<RigidBodyComponent>(), owner->transform->GetDirectionVector() * -1, (playerSpeed / 2) * (float)Time::GetDeltaTime());

	// rotation
	if (Keyboard::IsKeyDown(Keyboard::KEY_LEFT))
		owner->transform->rotation += (float)Time::GetDeltaTime() * playerTurnSpeed;

	if (Keyboard::IsKeyDown(Keyboard::KEY_RIGHT))
		owner->transform->rotation -= (float)Time::GetDeltaTime() * playerTurnSpeed;
}

void PlayerScript::SpawnBullet()
{
	Entity* bullet = CreateBullet();
	vec2 direction = owner->transform->GetDirectionVector();
	
	Physics::ApplyForce(bullet->GetComponent<RigidBodyComponent>(), direction, bulletSpeed);

	AddEntityToScene(bullet);
}

Entity* PlayerScript::CreateBullet()
{
	bulletMesh = Shapes::Circle(10, 3);
	Entity* bullet = CreateEntity(new RenderComponent(bulletMesh, nullptr), owner->transform->position, owner->transform->rotation);

	bullet->AddComponent<RigidBodyComponent>(new RigidBodyComponent());
	bullet->AddComponent<ScriptComponent>(new BulletScript(asteroids));

	return bullet;
}

void PlayerScript::CheckCollisionWithAsteroids()
{
	for (Entity* e : GetActiveScene()->GetEntities())
	{
		if (e->name._Equal("Asteroid"))
		{
			if (Physics::Distance(owner, e) < 40)
			{
				size_t asteroidIndex = std::find(asteroids.begin(), asteroids.end(), e) - asteroids.begin();
				asteroids.erase(asteroids.begin() + asteroidIndex);
				RemoveEntityFromScene(e);
				DeleteEntity(e);
				health--;
				return;
			}
		}
	}
}

void PlayerScript::CheckHealth()
{
	std::cout << "Health: " << health << "\n";
	if (health < 0)
	{
		RemoveEntityFromScene(owner);
		DeleteEntity(owner);
		Time::TimeScale = 0;
		return;
	}
}

void PlayerScript::OnUpdate()
{
	ProcessMovement();
	CheckCollisionWithAsteroids();
	CheckHealth();
	
	if (timeUntilNextShot > 0) timeUntilNextShot--;

	if (Keyboard::IsKeyDown(Keyboard::KEY_SPACE))
	{
		if (timeUntilNextShot == 0) 
		{
			SpawnBullet();
			timeUntilNextShot = reloadTime;
		}
	}
}
